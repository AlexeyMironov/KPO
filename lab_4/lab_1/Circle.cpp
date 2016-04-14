#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(SPoint p, CMyLongNumber radius)
	: m_radius(radius)
	, m_p(p)
{
}


CCircle::~CCircle()
{
}

CMyLongNumber CCircle::GetPerimeter() const
{
	std::vector<int> two;
	two.push_back(2);                                            //8979323846 2643383279 5028841971
	std::vector<int> numeratorOfPi = {1,7,9,1,4,8,8,2,0,5,9,7,2,3,8,3,3,4,6,2,6,4,8,3,2,3,9,7,9,8,5,3,5,6,2,9,5,1,4,1,3};
	std::vector<int> denominatorOfPi = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	return two * m_radius * numeratorOfPi / denominatorOfPi;
}

CMyLongNumber CCircle::GetArea() const
{
	std::vector<int> numeratorOfPi = { 1, 7, 9, 1, 4, 8, 8, 2, 0, 5, 9, 7, 2, 3, 8, 3, 3, 4, 6, 2, 6, 4, 8, 3, 2, 3, 9, 7, 9, 8, 5, 3, 5, 6, 2, 9, 5, 1, 4, 1, 3 };
	std::vector<int> denominatorOfPi = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	return pow(m_radius, 2) * numeratorOfPi / denominatorOfPi;
}
