#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_types.h>
#include <iostream>

int main(){
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl:: PointCloud<pcl::PointXYZ>);

    for (int i = 0; i <100; i++){
        pcl::PointXYZ p;
        p.x = static_cast<float> (rand()/static_cast<float> (RAND_MAX));
        p.y = static_cast<float> (rand()/static_cast<float> (RAND_MAX));
        p.z = static_cast<float> (rand()/static_cast<float> (RAND_MAX));
        cloud->push_back(p);

    }
    
    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
    kdtree.setInputCloud(cloud);

    //create a query point

    pcl::PointXYZ searchPoint;
    searchPoint.x = 0.1f;
    searchPoint.y = 0.1f;
    searchPoint.z = 0.1f;
    
    int k=5;
    std::vector<int> indices(k);
    std::vector<float> distances(k);
    kdtree.nearestKSearch(searchPoint, k, indices, distances);

    for (int i =0; i < int(indices.size()); i++){
        std::cout << "indices" << i << "j:" << indices[i] << "distances[" << i <<"]:" << distances[i] << std::endl;
        
    }
    return 0;
}