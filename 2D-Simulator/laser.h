#ifndef LASER_H
#define LASER_H

#include <vector>
#include "segment.h"
#include "position.h"


struct Laser
{
    const float FOV_degree = 270;
    const float FOV = FOV_degree * (M_PI / 180.0);
    const float range_min = 0.2;
    const float range_max = 10.0;
    const float ray_length = range_max - range_min;
    const int num_total_rays = 1080;
    const float angular_resolution_degree = FOV_degree / num_total_rays;
    const float angular_resolution = FOV / num_total_rays;
    const float noise_mean = 0.2;
    const float noise_sigma = 1.0;
};


// const struct
// {
//     // Laser(Position pos);
//     Position position;

//     vector<Segment> rays;

//     void create_rays();
//     int add_ray(Segment ray);
//     void print_rays();
// } Laser ;

#endif