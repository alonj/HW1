//
// Created by shraga89@st.technion.ac.il on 3/5/17.
//

#ifndef LAB3_KMEANS_POINT_H
#define LAB3_KMEANS_POINT_H

#include <iostream>
#include <vector>
#include <string>


class Point
{
private:
    size_t _idPoint;
    int _idCluster;
    std::vector<double> _values;
    std::string _name;
public:
    static const int _notAssignedToCluster=-1;

public:
    Point(size_t id_point, const std::vector<double>& values, const std::string& name = "");

    size_t getID() const { return _idPoint; }

    void setCluster(int id_cluster) { _idCluster = id_cluster; }

    int getCluster() const { return _idCluster; }

    const std::string& getName() const { return _name;}

    size_t getDimension() const { return _values.size(); }

    double getValue(size_t dim) const { return _values[dim]; }

    void setValue(double value, size_t dim) { _values[dim]=value; }

    double euclideanDistance( const Point &other_point ) const;

    void print() const;

    void setName( const std::string& name){ _name=name; }

    Point operator +(Point other);
    Point operator /(double denom);

};


#endif //LAB2_POINT_H
