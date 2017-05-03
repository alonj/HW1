
#include <cstdlib>
#include "KMedoids.h"
#include "SeedsGenerator.h"
#include <algorithm>


using std::cout;
using std::vector;


size_t KMedoids::getIDNearestCenter(const Point& point)
{
    size_t idClusterCenter = 0;
    double min_dist = _clusters[idClusterCenter].getDistanceToPrototype(point);

    for(unsigned i = 1; i < _K; i++)
    {
        double dist = _clusters[i].getDistanceToPrototype(point);
        if(dist < min_dist)
        {
            min_dist = dist;
            idClusterCenter = i;
        }
    }
    return idClusterCenter;
}

void KMedoids::run( const vector <Point> &points ) {

    if( _K > points.size() )
        return;
    _points=points;
    // choose K distinct values for the medoids of the clusters
    setRandomSeeds();

    unsigned iter = 1;
    bool done(false);

    while( (!done) && (iter<= _maxIterations) )
    {
        // associates each point to the nearest medoid
        done = attributePoints();

        // recalculating the center of each medoid
        for( std::vector<Cluster>::size_type i = 0; i < _K; i++)
        {
            _clusters[i].updateMedoid(_points);
        }
        iter++;
    }
}

void KMedoids::print() // prints elements of clusters
{
    for( std::vector<Cluster>::size_type i = 0; i < _K; i++ )
        _clusters[i].print(_points);

}

bool KMedoids::attributePoints()
{
    bool done = true;
    for(vector<Point>::size_type i = 0; i < _points.size(); i++)
    {
        int id_old_cluster = _points[i].getCluster();
        size_t id_nearest_center = getIDNearestCenter( _points[i] );

        if(id_old_cluster != id_nearest_center)
        {
            if (id_old_cluster != Point::_notAssignedToCluster)
                _clusters[id_old_cluster].removePoint(_points[i].getID());

            //a valid cluster ID is a positive number, there is an implicit assumption here that the number of clusters does not exceed the positive value of integer
            _points[i].setCluster( (int)id_nearest_center );
            _clusters[id_nearest_center].addPoint( _points[i].getID() );
            done = false;
        }
    }
    return done;
}

void KMedoids::setRandomSeeds()
{
    vector<vector<Point>::size_type> seedIndexes;

    while (seedIndexes.size() < _K )
    {
        vector<Point>::size_type index_point = SeedsGenerator::getRandom( 0, _points.size() );
        //This is a standard library function that looks for a value inside a vector, if the values is not found - an iterator to the end of vector is returned
        if ( std::find( seedIndexes.begin(), seedIndexes.end(), index_point) == seedIndexes.end())
            seedIndexes.insert(seedIndexes.begin(),index_point);
    }
    for (vector<vector<Point>::size_type>::size_type i=0; i< seedIndexes.size(); i++ )
    {
        _points[seedIndexes[i]].setCluster((int)i);
        Cluster cluster((int)i, _points[seedIndexes[i]]);
        cluster.addPoint(_points[seedIndexes[i]].getID());
        _clusters.push_back( cluster );
    }
}

double KMedoids::calculateSSE() // calculates sum of SSE for all clusters
{
    double sum(0.0);
    for(std::vector<Cluster>::size_type i=0; i< _K; i++)
        sum+=_clusters[i].SSE(_points);
    return sum;
}