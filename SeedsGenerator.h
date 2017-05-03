//
// Created by annabel@staff.technion.ac.il on 4/5/17.
//

#ifndef LAB3_KMEANS_SEEDSGENERATOR_H
#define LAB3_KMEANS_SEEDSGENERATOR_H

#include <cstdlib>

class SeedsGenerator {
private:
    static const unsigned _seed;
public:
    static void init(){ srand(_seed); }
    static size_t getRandom(size_t min, size_t max) {  return min+rand()%(max-min); }

};


#endif //LAB3_KMEANS_SEEDSGENERATOR_H
