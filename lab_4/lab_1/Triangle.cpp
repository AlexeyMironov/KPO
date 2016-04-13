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

CMyLongNumber CTriangle::GetPerimeter() const
{
	CMyLongNumber a, b, c;
	a = GetLineLength(m_p1, m_p2);
	b = GetLineLength(m_p2, m_p3);
	c = GetLineLength(m_p1, m_p3);
	return a + b + c;
}

CMyLongNumber CTriangle::GetArea() const
{
	CMyLongNumber a, b, c;
	a = GetLineLength(m_p1, m_p2);
	b = GetLineLength(m_p2, m_p3);
	c = GetLineLength(m_p1, m_p3);
	std::vector<int> two;
	two.push_back(2);
	CMyLongNumber semiper = (a + b + c) / two;
	//CMyLongNumber area = sqrt(semiper * (semiper - a) * (semiper - b) * (semiper - c));
	return sqrt(semiper * (semiper - a) * (semiper - b) * (semiper - c));
}

CMyLongNumber CTriangle::GetLineLength(const SPoint &p1, const SPoint &p2)
{
	/*CMyLongNumber fst = p1.x - p2.x;
	CMyLongNumber scnd = pow(fst, 2);
	CMyLongNumber thrd = fst + scnd; // (p1.y - p2.y, 2)*/
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}