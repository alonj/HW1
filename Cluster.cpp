//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//
#include "Cluster.h"
#include <cmath>
#include <limits>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void Cluster::addPoint(size_t pointID)
{
    bool exists = 0;
    for(vector<size_t>::size_type i = 0; i < _points.size(); i++)
    {
        if(_points[i] == pointID)
            exists = 1;
    }
    if(!exists)
        _points.push_back(pointID);
}


bool Cluster::removePoint(size_t pointID)
{
   /*for(vector<size_t>::size_type i = 0; i < this->_points.size(); i++)
    {
        if(this->_points[i] == pointID)
        {
            this->_points.erase(this->_points.begin() + i);
            return true;
        }
    }*/
    this->_points.erase(this->find(pointID));
    return false;
}

void Cluster::print(const vector<Point>& allPoints) const
{
    cout << "Cluster " << _idCluster + 1 << endl;
    for(vector<Point>::size_type j = 0; j < _points.size(); j++)
    {
        cout << "Point " << allPoints[_points[j]].getID() + 1 << ": ";
//        allPoints[_points[j]].print();
        cout<<allPoints[_points[j]];
    }
    cout << "Cluster prototype: " << _prototype;
}

Cluster::Cluster(int idCluster, const Point &point):_idCluster(idCluster),
                                                        _prototype(point){
    _points.push_back(point.getID());
}


void Cluster::updatePrototype(const std::vector<Point> &allPoints)
{
    size_t prototypeDim = _prototype.getDimension();
    for(vector<size_t>::size_type j = 0; j < prototypeDim; j++)
    {
        _prototype.setValue(0.0,j);
    }
    _prototype.setName("");
    for(vector<size_t>::size_type i = 0; i < _points.size(); i++)
    {
        _prototype = _prototype+allPoints[_points[i]];
    }
    _prototype = _prototype/_points.size();
}

void Cluster::updateMedoid(const std::vector<Point> &allPoints){
    double minDist=std::numeric_limits<double>::max();
    _prototype.setName("");
    for(vector<size_t>::size_type i = 0; i < _points.size(); i++)
    {
        for(vector<size_t>::size_type j = i; j<_points.size(); j++) {
            if (minDist>Point::staticEucDist(allPoints[_points[i]],allPoints[_points[j]])) {
                minDist = Point::staticEucDist(allPoints[_points[i]],allPoints[_points[j]]);
                _prototype=allPoints[_points[i]];
            }
        }
    }
}


double Cluster::getDistanceToPrototype(const Point &point) const
{
    return Point::staticEucDist(point,_prototype);
}

std::vector<size_t>::iterator Cluster::find(size_t pointID)
{
    std::vector<size_t>::iterator result;
    bool updated=false;
    for(vector<size_t>::iterator i = _points.begin(); i!=_points.end(); i++)
    {
        if(*i == pointID) {
            result = i;
            updated=true;
        }
    }
    if (!updated)
                result=_points.end();
    return result;
}

double Cluster::SSE(const std::vector<Point> &allPoints) {
    double sum(0.0);
    for(vector<Point>::size_type i=0;i<_points.size();i++)
    {
        sum+=pow(getDistanceToPrototype(allPoints[_points[i]]),2.0);
    }
    return sum;
}