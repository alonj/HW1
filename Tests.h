//
// Created by annabel@staff.technion.ac.il on 4/6/17.
//

#ifndef LAB3_KMEANS_TESTS_H
#define LAB3_KMEANS_TESTS_H

#include <vector>
#include <string>
#include "Point.h"

class Tests {

public:
    enum eTests{ eTestKMeans=0, eTestKMedoids, eTestKMeansSSE, eTestKMedoidsSSE, numOfTests};
    static const std::string testNames[numOfTests];

public:
    static void testKMeans(unsigned K, unsigned max_iterations, const std::vector<Point>& points);
    static void testKMedoids(unsigned K, unsigned max_iterations, const std::vector<Point>& points);
    static void testKMeansSSE(unsigned K, unsigned max_iterations, const std::vector<Point>& points);
    static void testKMedoidsSSE(unsigned K, unsigned max_iterations, const std::vector<Point>& points);

private:
    Tests();

};

#endif //LAB3_KMEANS_TESTS_H
