// Generated by gencpp from file visual_feature_server/Convert2DPoint.msg
// DO NOT EDIT!


#ifndef VISUAL_FEATURE_SERVER_MESSAGE_CONVERT2DPOINT_H
#define VISUAL_FEATURE_SERVER_MESSAGE_CONVERT2DPOINT_H

#include <ros/service_traits.h>


#include <visual_feature_server/Convert2DPointRequest.h>
#include <visual_feature_server/Convert2DPointResponse.h>


namespace visual_feature_server
{

struct Convert2DPoint
{

typedef Convert2DPointRequest Request;
typedef Convert2DPointResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Convert2DPoint
} // namespace visual_feature_server


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::visual_feature_server::Convert2DPoint > {
  static const char* value()
  {
    return "da24dbed0bfc78862b40c7bfe16c141e";
  }

  static const char* value(const ::visual_feature_server::Convert2DPoint&) { return value(); }
};

template<>
struct DataType< ::visual_feature_server::Convert2DPoint > {
  static const char* value()
  {
    return "visual_feature_server/Convert2DPoint";
  }

  static const char* value(const ::visual_feature_server::Convert2DPoint&) { return value(); }
};


// service_traits::MD5Sum< ::visual_feature_server::Convert2DPointRequest> should match
// service_traits::MD5Sum< ::visual_feature_server::Convert2DPoint >
template<>
struct MD5Sum< ::visual_feature_server::Convert2DPointRequest>
{
  static const char* value()
  {
    return MD5Sum< ::visual_feature_server::Convert2DPoint >::value();
  }
  static const char* value(const ::visual_feature_server::Convert2DPointRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::visual_feature_server::Convert2DPointRequest> should match
// service_traits::DataType< ::visual_feature_server::Convert2DPoint >
template<>
struct DataType< ::visual_feature_server::Convert2DPointRequest>
{
  static const char* value()
  {
    return DataType< ::visual_feature_server::Convert2DPoint >::value();
  }
  static const char* value(const ::visual_feature_server::Convert2DPointRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::visual_feature_server::Convert2DPointResponse> should match
// service_traits::MD5Sum< ::visual_feature_server::Convert2DPoint >
template<>
struct MD5Sum< ::visual_feature_server::Convert2DPointResponse>
{
  static const char* value()
  {
    return MD5Sum< ::visual_feature_server::Convert2DPoint >::value();
  }
  static const char* value(const ::visual_feature_server::Convert2DPointResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::visual_feature_server::Convert2DPointResponse> should match
// service_traits::DataType< ::visual_feature_server::Convert2DPoint >
template<>
struct DataType< ::visual_feature_server::Convert2DPointResponse>
{
  static const char* value()
  {
    return DataType< ::visual_feature_server::Convert2DPoint >::value();
  }
  static const char* value(const ::visual_feature_server::Convert2DPointResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // VISUAL_FEATURE_SERVER_MESSAGE_CONVERT2DPOINT_H