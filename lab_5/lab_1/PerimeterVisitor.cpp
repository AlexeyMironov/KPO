#include "stdafx.h"
#include "PerimeterVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void CPerimeterVisitor::Visit(CCircle const& shape)
{
	std::vector<int> two;
	two.push_back(2);                                         
	std::vector<int> numeratorOfPi = { 9, 7, 9, 8, 5, 3, 5, 6, 2, 9, 5, 1, 4, 1, 3 };
	std::vector<int> denominatorOfPi = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	result = two * shape.GetRadius() * numeratorOfPi / denominatorOfPi;
}

void CPerimeterVisitor::Visit(CRectangle const& shape)
{
	std::vector<int> two;
	two.push_back(2);
	result = ((shape.GetFirstPoint().x - shape.GetSecondPoint().x) + shape.GetFirstPoint().y - shape.GetSecondPoint().y) * two;
}

void CPerimeterVisitor::Visit(CTriangle const& shape)
{
	result = shape.GetSideA() + shape.GetSideB() + shape.GetSideC();
}
