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
	two.push_back(2);
	//std::vector<int> numeratorOfPi = {3,1,4,1,5,9,2,6,5,3,5};
	std::vector<int> numeratorOfPi = {5,3,5,6,2,9,5,1,4,1,3};
	std::vector<int> denominatorOfPi = {0,0,0,0,0,0,0,0,0,0,1};
	CMyLongNumber num1 = two * m_radius * numeratorOfPi;
	CMyLongNumber num2 = two * m_radius * numeratorOfPi / denominatorOfPi;

	return two * m_radius * numeratorOfPi / denominatorOfPi;
}

CMyLongNumber CCircle::GetArea() const
{
	std::vector<int> numeratorOfPi = { 5, 3, 5, 6, 2, 9, 5, 1, 4, 1, 3 };
	std::vector<int> denominatorOfPi = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	CMyLongNumber num1 = pow(m_radius, 2) * numeratorOfPi;
	CMyLongNumber num2 = pow(m_radius, 2) * numeratorOfPi / denominatorOfPi;
	//return m_pi * pow(m_radius, 2);
	return pow(m_radius, 2) * numeratorOfPi / denominatorOfPi;
}
