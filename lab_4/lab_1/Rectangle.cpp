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

CMyLongNumber CRectangle::GetPerimeter() const
{
	std::vector<int> two;
	two.push_back(2);
	return ((m_p1.x - m_p2.x) + (m_p1.y - m_p2.y)) * two;
}

CMyLongNumber CRectangle::GetArea() const
{
	return ((m_p1.x - m_p2.x) * (m_p1.y - m_p2.y));
}
