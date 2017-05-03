//
// Created by annabel@staff.technion.ac.il on 4/6/17.
//

#include "Tests.h"
#include "Kmeans.h"
#include "KMedoids.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;

const std::string Tests::testNames[numOfTests]={"testKMeans", "testKMedoids", "testKMeansSSE", "testKMedoidsSSE"};

void Tests::testKMeans(unsigned K, unsigned max_iterations, const std::vector<Point>& points)
{
    KMeans kmeans(K, max_iterations);
    kmeans.run(points);
    kmeans.print();
}

void Tests::testKMedoids(unsigned K, unsigned max_iterations, const std::vector<Point>& points)
{
    KMedoids kmedoids(K, max_iterations);
    kmedoids.run(points);
    kmedoids.print();
}

void Tests::testKMeansSSE(unsigned K, unsigned max_iterations, const std::vector<Point>& points)
{
    KMeans kmeans(K, max_iterations);
    kmeans.run(points);
    cout << kmeans.calculateSSE() << endl;
}

void Tests::testKMedoidsSSE(unsigned K, unsigned max_iterations, const std::vector<Point>& points)
{
    KMedoids kmedoids(K, max_iterations);
    kmedoids.run(points);
    cout << kmedoids.calculateSSE() << endl;
}
