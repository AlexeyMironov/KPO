#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(SPoint p1, SPoint p2)
	: m_p1(p1)
	, m_p2(p2)
{
}


CRectangle::~CRectangle()
{
}

double CRectangle::GetPerimeter() const
{
	return (abs(m_p1.x - m_p2.x) + abs(m_p1.y - m_p2.y)) * 2;
}

double CRectangle::GetArea() const
{
	return (abs(m_p1.x - m_p2.x) * abs(m_p1.y - m_p2.y));
}
