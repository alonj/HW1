//
// Created by annabel@staff.technion.ac.il on 4/5/17.
//

#ifndef LAB3_KMEANS_KMEDOIDS_H
#define LAB3_KMEANS_KMEDOIDS_H

#include <vector>
#include "Cluster.h"
#include "Point.h"

class KMedoids
{
private:
    unsigned _K; // number of clusters
    unsigned _maxIterations;
    std::vector<Cluster> _clusters;
    std::vector<Point> _points;
    // return ID of nearest center (uses euclidean distance)
    size_t getIDNearestCenter(const Point& point);

public:
    KMedoids(unsigned K, unsigned maxIterations): _K(K), _maxIterations(maxIterations){ }
    void run( const std::vector<Point> &points);
    void print();
    double calculateSSE();

private:
    void setRandomSeeds();
    bool attributePoints();

};


#endif //LAB3_KMEANS_KMEDOIDS_H

