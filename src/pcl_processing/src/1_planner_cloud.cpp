#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main()
{
    //contains 3D points, also a vector
     pcl::PointCloud<pcl::PointXYZ> cloud;
    //creates cloud data to be pushed into
     cloud.push_back(pcl::PointXYZ(1.0, 2.0,3.0));
     std::string path = "/home/jun/ros2_ws/src/pcl_processing/point_clouds/plane.pcd";
     //saves cloud data to the file path
     pcl::io::savePCDFileASCII(path, cloud);
     std::cout<<cloud.size();
     
}