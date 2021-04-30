#ifndef COMPONENT_3D_HPP
#define COMPONENT_3D_HPP

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Component3D
{
public:
	Component3D();
	~Component3D();

	Vector3<float> at(int);
	int size();

	Component3D& add(float, float, float);
	Component3D& add(Vector3<float>);

	Component3D translate(float, float, float);

private:
	vector<Vector3<float> > points;
};

Component3D::Component3D()
{
	
}

Component3D::~Component3D()
{

}

Vector3<float> Component3D::at(int index)
{
	return points.at(index);
}

int Component3D::size()
{
	return points.size();
}

Component3D& Component3D::add(float x, float y, float z)
{
	Vector3<float> vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;

	points.push_back(vec);

	return *this;
}

Component3D& Component3D::add(Vector3<float> vec)
{
	points.push_back(vec);

	return *this;
}

Component3D Component3D::translate(float deltaX, float deltaY, float deltaZ)
{
	Component3D component;

	for(int i=0; i<points.size(); i++)
		component.add(points.at(i).x + deltaX, points.at(i).y + deltaY, points.at(i).z + deltaZ);

	return component;
}

#endif