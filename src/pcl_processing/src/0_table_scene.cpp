#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

int main() {
    // Create a pointer to hold the point cloud data
    pcl::PCLPointCloud2::Ptr cloud(new pcl::PCLPointCloud2());
    
    // Create a PCD reader object
    pcl::PCDReader cloud_reader;
    
    // Path to the PCD file
    std::string path = "/home/jun/ros2_ws/src/pcl_processing/point_clouds/table_scene_lms400.pcd";
    
    // Read the PCD file into the point cloud object
    cloud_reader.read(path, *cloud);
    
    // Output the number of points in the point cloud
    std::cout << "Number of points: " << cloud->width * cloud->height << std::endl;

    return 0;
}
