#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(SPoint p1, SPoint p2, SPoint p3)
	: m_p1(p1)
	, m_p2(p2) 
	, m_p3(p3)
{
}


CTriangle::~CTriangle()
{
}

double CTriangle::GetPerimeter() const
{
	double a, b, c;
	a = GetLineLength(m_p1, m_p2);
	b = GetLineLength(m_p2, m_p3);
	c = GetLineLength(m_p1, m_p3);
	return a + b + c;
}

double CTriangle::GetArea() const
{
	//return sqrt(pow((m_p1.x - m_p1.y), 2) + pow((m_p2.x - m_p2.y), 2) + pow((m_p3.x - m_p3.y), 2));
	double a, b, c;
	a = GetLineLength(m_p1, m_p2);
	b = GetLineLength(m_p2, m_p3);
	c = GetLineLength(m_p1, m_p3);
	double semiper = (a + b + c) / 2;
	return sqrt(semiper * (semiper - a) * (semiper - b) * (semiper - c));
}

double CTriangle::GetLineLength(SPoint p1, SPoint p2)
{
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}