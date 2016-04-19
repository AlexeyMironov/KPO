#include "stdafx.h"
#include "Circle.h"
#include "BodyVisitor.h"

CCircle::CCircle(SPoint p, CMyLongNumber radius)
	: m_radius(radius)
	, m_p(p)
{
}


CCircle::~CCircle()
{
}

CMyLongNumber CCircle::GetRadius() const
{
	return m_radius;
}

CMyLongNumber CCircle::GetPerimeter() const
{
	std::vector<int> two;
	two.push_back(2);                               
	std::vector<int> numeratorOfPi = { 9, 7, 9, 8, 5, 3, 5, 6, 2, 9, 5, 1, 4, 1, 3 };
	std::vector<int> denominatorOfPi = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	return two * m_radius * numeratorOfPi / denominatorOfPi;
}

CMyLongNumber CCircle::GetArea() const
{
	std::vector<int> numeratorOfPi = { 9, 7, 9, 8, 5, 3, 5, 6, 2, 9, 5, 1, 4, 1, 3 };
	std::vector<int> denominatorOfPi = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	return pow(m_radius, 2) * numeratorOfPi / denominatorOfPi;
}

void CCircle::Accept(CBodyVisitor &visitor) const
{
	return visitor.Visit(*this);
}