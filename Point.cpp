//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//

#include "Point.h"
#include "Cluster.h"
#include <cmath>

using std::vector;
using std::string;
using std::cout;
using std::endl;

const int Point::_notAssignedToCluster=-1;

Point::Point(size_t id_point, const std::vector<double> &values, const std::string &name):_idPoint(id_point),
                                                                                          _values(values),
                                                                                          _name(name){
    _idCluster=_notAssignedToCluster;}

/*
double Point::euclideanDistance(const Point &other_point)
{
    double sum = 0.0;
    for(  vector<double>::size_type i = 0; i < _values.size(); i++)
    {
        sum += pow( _values[i] - other_point._values[i], 2.0);
    }

    return sqrt(sum);
}
*/

//calculate euclidean distance between points.
double Point::staticEucDist(const Point &this_point,const Point &other_point)
{ // implicit assumption that both points are of the same dimension - since we're checking points in similar vectors
    double sum(0.0);
    for(vector<size_t>::size_type i=0;i<this_point.getDimension();i++)
    {
        sum+=pow(this_point._values[i]-other_point._values[i],2.0);
    }
    return sqrt(sum);

}

/*void Point::print() const
{
    for(vector<double>::size_type i = 0; i < _values.size(); i++)
        cout << _values[i] << " ";

    if ( !_name.empty())
        cout << " - " << _name;

    cout << endl;

}*/

Point Point::operator+(Point other)
{
    for(vector<double>::size_type i=0;i<_values.size();i++)
    {
        double curVal = this->getValue(i);
        this->setValue(other.getValue(i)+curVal,i);
    }
    return *this;
}

Point Point::operator/(double denom) {
    for (vector<double>::size_type i = 0; i < _values.size(); i++)
    {
        double curVal = this->getValue(i);
        this->setValue(curVal/denom,i);
    }
    return *this;
}

/*Point Point::operator=(Point other)
{
    size_t dim = this->getDimension();
    this->setValue(other.getValue(dim),dim);
}*/

std::ostream& operator<<(std::ostream &os, const Point &point) {
    for(vector<double>::size_type i=0; i<point.getDimension();i++)
        os << point.getValue(i) << " ";
    if ( point.getName()!="")
        os << " - " << point.getName();
    os << endl;
    return os;
}
