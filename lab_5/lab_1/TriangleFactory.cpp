#include "stdafx.h"
#include "TriangleFactory.h"
#include "Triangle.h"

std::shared_ptr<IBody> CTriangleFactory::CreateBody(std::vector<SShapeParams> points) const
{
	return std::make_shared<CTriangle>(points[0], points[1], points[2]);
}

CTriangleFactory& CTriangleFactory::GetInstance()
{
	static CTriangleFactory instance;
	return instance;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                              