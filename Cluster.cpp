//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//
#include "Cluster.h"
#include <cmath>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void Cluster::addPoint(size_t pointID)
{
    bool exists = 0;
    for(vector<Point>::size_type i = 0; i < _points.size(); i++)
    {
        if(_points[i] == pointID)
            exists = 1;
    }
    if(!exists)
        _points.push_back(pointID);
}


bool Cluster::removePoint(size_t pointID)
{
   for(vector<Point>::size_type i = 0; i < _points.size(); i++)
    {
        if(_points[i] == pointID)
        {
            _points.erase(_points.begin() + i);
            return true;
        }
    }
    return false;
}

void Cluster::print(const vector<Point>& allPoints) const
{
    cout << "Cluster " << _idCluster + 1 << endl;
    for(vector<Point>::size_type j = 0; j < _points.size(); j++)
    {
        cout << "Point " << allPoints[_points[j]].getID() + 1 << ": ";
        allPoints[_points[j]].print();
    }

    cout << "Cluster prototype: ";
    _prototype.print();
}

Cluster::Cluster(int idCluster, const Point &prototype):_idCluster(idCluster),
                                                        _prototype(prototype){}


void Cluster::updatePrototype(const std::vector<Point> &allPoints)
{
    int dim=allPoints[_points[0]].getDimension();
    _prototype=allPoints[0];
    for(vector<Point>::size_type i = 1; i < _points.size(); i++)
    {
        _prototype = _prototype+allPoints[_points[i]];
    }
    _prototype = _prototype/dim;
}