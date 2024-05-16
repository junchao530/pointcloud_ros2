#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main()
{
    //contains 3D points, also a vector
     pcl::PointCloud<pcl::PointXYZRGB> cloud;
     double radius = 3.0;
     int num_points = 500;
     double angular_step_size = 2.0*M_PI/num_points;
     
     for(int i =0 ; i<num_points; i++){

     double angel = i * angular_step_size;
     pcl::PointXYZRGB point;
     point.x = radius * std::cos(angel);
     point.y = radius * std::sin(angel);
     point.z = 1.0;
     
     point.r = 255 * std::cos(angel);
     point.g = 255 * std::sin(angel);
     point.b = 255 * std::cos(angel * M_PI_2);

     cloud.push_back(point);
     }

     std::string path = "/home/jun/ros2_ws/src/pcl_processing/point_clouds/circular_plane.pcd";
     pcl::io::savePCDFileASCII(path, cloud);
    
}