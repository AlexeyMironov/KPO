#include "stdafx.h"
#include "AreaVisitor.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "PerimeterVisitor.h"

void CAreaVisitor::Visit(CCircle const& shape)
{
	std::vector<int> numeratorOfPi = { 9, 7, 9, 8, 5, 3, 5, 6, 2, 9, 5, 1, 4, 1, 3 };
	std::vector<int> denominatorOfPi = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	result = pow(shape.GetRadius(), 2) * numeratorOfPi / denominatorOfPi;
}

void CAreaVisitor::Visit(CRectangle const& shape)
{
	result = ((shape.GetFirstPoint().x - shape.GetSecondPoint().x) * (shape.GetFirstPoint().y - shape.GetSecondPoint().y));
}

void CAreaVisitor::Visit(CTriangle const& shape)
{
	std::vector<int> two;
	two.push_back(2);
	CMyLongNumber semiper = (shape.GetSideA() + shape.GetSideB() + shape.GetSideC()) / two;
	result = sqrt(semiper * (semiper - shape.GetSideA()) * (semiper - shape.GetSideB()) * (semiper - shape.GetSideC()));
}

