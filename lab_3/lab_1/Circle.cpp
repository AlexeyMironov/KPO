#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(SPoint p, double radius)
	: m_radius(radius)
	, m_p(p)
{
}


CCircle::~CCircle()
{
}

double CCircle::GetPerimeter() const
{
	return 2 * m_radius * M_PI;
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}
