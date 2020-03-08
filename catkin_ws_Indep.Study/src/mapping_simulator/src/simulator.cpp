#include <iostream>
#include <string>
#include "simulator.h"
#include "segment.h"
#include "robot.h"
#include "laser.h"
#include "noise.h"
#include <geometry_msgs/Vector3.h>
#include <visualization_msgs/Marker.h>
using namespace std;


void simulate_scan(vector<Vec2f> &point_cloud, Robot &robot, vector<Segment> &wall_segments,
                            Laser &laser_sensor, Noise &length_noise, Noise &angle_noise)
{
    float angle = robot.angle_degree 
                - (laser_sensor.FOV_degree / 2.0);                     // Calculate starting angle from current Position(x, y, theta)

    for(int i = 1; i <= laser_sensor.num_total_rays; i++) {            // For all each laser ray
        // cout << "------ rays ----------\n";
        Segment ray = 
            laser_sensor.create_a_ray(robot.position, angle, length_noise, angle_noise); // Create a ray
        // cout << ray << "\n-------------------------\n";
        angle += laser_sensor.angular_resolution_degree;               // Get the next ray's angle

        float min_t = 99999;                                            // Temp value for min
        bool point_exists = false;
        Vec2f min_point;                                                // Pointer of the closest segment at the moment

        for(vector<Segment>::iterator wall_it = wall_segments.begin(); wall_it != wall_segments.end(); wall_it++) {  // For all each wall segment
            if (!ray.isParallel(*wall_it)) {                                 // If two segments(Laser ray & Wall segment) is not Parallel
                Vec2f new_point = ray.intersection_point(*wall_it);                // Get the intersection point as a Vec2f
                // cout << "(" << new_point.x() << "," << new_point.y() << ")" << endl;
                    // cout << ray.t << " ** " << min_t << endl;                       // In two intersects on its length (not on a extended line)
                if (ray.ifIntersect(*wall_it)) {      
                    if (fabs(ray.t) < fabs(min_t)) {                    // Takes as closest wall segment at the moment
                        point_exists = true;
                        min_t = ray.t;                                  // Remember the min t (length)
                        min_point = new_point;
                        // cout << "(" << min_point.x() << "," << min_point.y() << ") with a wall " << *wall_it << "\n";
                    }
                }
            }
        }

        if (point_exists) {                                             // If there existed any closest wall segment
            // cout << "adding min!" << endl;
            // cout << min_point << endl;
            if (min_t < laser_sensor.range_min) {                      // Too close point (closer than min_range of laser)
                ;
                // cout << "Too close to detect... pass by this ray. t: " << min_t << "\trange_min: " << laser_sensor.range_min << endl;
            } else {
                // geometry_msgs::Vector3 vec;
                // vec.x = min_point.x();
                // vec.y = min_point.y();
                // vec.z = 0;
                point_cloud.push_back(min_point);                      // Push back into a vector of Segment* pointers
            }
        } else {
            ;
            // cout << "nothing to add!" << endl;
        }
        // cout << "\n\n";
    }
}


float get_vector_length(Vec2f &v)
{
    return sqrt((pow(v.x(), 2.0) + pow(v.y(), 2.0)));
}


deque<Vec2f> interpolate_curve_points(Robot &robot, Vec2f &goal)
// vector<Position> interpolate_curve_points(Robot &robot, Position &goal, int addiotional_num_cut, int default_num_cut)
{
    Vec2f L0 = robot.velocity;
    Vec2f L1 = goal - L0;
    cout << "L0: " << L0 << endl;
    cout << "L1: " << L1 << endl;

    float L0_length = get_vector_length(L0);
    float L1_length = get_vector_length(L1);
    cout << "L0 len: " << L0_length << endl;
    cout << "L1 len: " << L1_length << endl;

    if (L0_length <= 5.0) { L0_length = 5.0; }
    if (L1_length <= 5.0) { L1_length = 5.0; }
    float delta = 1 / (L0_length * L1_length);
    float t = 0.0;
    cout << "L0 len * L1 len = " << (L0_length * L1_length) << endl;
    cout << "delta:" << delta << endl;

    float robot_cur_angle = robot.angle_degree;
    Position P0 = Position(0, 0, robot_cur_angle);
    Position P1 = Position(L0.x(), L0.y(), robot_cur_angle);
    cout << "P0:" << P0 << endl;
    cout << "P1:" << P1 << endl;

    deque<Vec2f> curves;
    for(float curve_point = 0.0; curve_point <= 1.0; curve_point += delta) {
        cout << "curve_point: " << curve_point << endl;
        // Position p = (P0 * pow((1 - curve_point), 2.0)) +
        //             (P1 * 2 * (1 - curve_point) * curve_point) +
        //             (goal * pow(curve_point, 2.0));
        float x = (robot.position.x() * pow((1 - curve_point), 2.0)) +
                    (robot.velocity.x() * 2 * (1 - curve_point) * curve_point) +
                    (goal.x() * pow(curve_point, 2.0));
        float y = (robot.position.y() * pow((1 - curve_point), 2.0)) +
                    (robot.velocity.y() * 2 * (1 - curve_point) * curve_point) +
                    (goal.y() * pow(curve_point, 2.0));
        Vec2f p = Vec2f(x, y);
        cout << "new pos: " << p << "\t\tRobot pos:" << "(" << robot.position.x() << "," << robot.position.y() << ")" << endl;
        curves.push_back(p);
        // getchar();
    }

    return curves;
}


int usage(char *app_name) {
    cout << "Usage: " << app_name << " [text file]\n";
    cout << "Options:\n";
    cout << "  -p\t\t\tpause on every line\n\n";
    exit(0);
}


void read_segments(ifstream &seg_file, vector<Segment> &segs)
{
    Vec2f p1 = Vec2f(0,0);
    Vec2f p2 = Vec2f(0,0);
    Segment seg = Segment(p1, p2);
    float x, y;
    int count = 0;
    string line;
    while(getline(seg_file, line)) {
        stringstream ss(line);
        while(getline(ss, line, ',')) {
            count++;
            switch (count)
            {
            case 1: x = stof(line); break;
            case 2: y = stof(line); p1 = Vec2f(x, y); break;
            case 3: x = stof(line); break;
            case 4: 
                y = stof(line);
                p2 = Vec2f(x, y);
                count = 0;
                // Segment seg = Segment(p1, p2);
                seg = Segment(p1, p2);
                segs.push_back(seg);
                break;
            default: break;
            }
        }
    }
}


float cut_redundant_epsilon(float x, float threshold)
{
    return (fabs(x) < threshold) ? 0.0 : x;
}


// void read_positions(ifstream &pos_file, vector<Position> *positions)
// {
//     Position pos = Position(0, 0);
//     float x, y;
//     int count = 0;
//     string line;
//     while(getline(pos_file, line)) {
//         cout << "asdf";
//         stringstream ss(line);
//         while(getline(ss, line, ',')) {
//             cout << line << endl;
//             count++;
//             switch (count)
//             {
//             case 1: x = stof(line); break;
//             case 2: 
//                 y = stof(line); 
//                 pos.new_position(x, y); 
//                 count = 0;
//                 positions->push_back(pos);
//                 break;
//             case 3: break;
//             default: break;
//             }
//         }
//     }
// }