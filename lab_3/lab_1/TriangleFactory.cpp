#include "stdafx.h"
#include "TriangleFactory.h"
#include "Triangle.h"

std::shared_ptr<IBody> CTriangleFactory::CreateBody(vector<SShapeParams> points) const
{
	return std::make_shared<CTriangle>(points[0], points[1], points[2]);
}

CTriangleFactory* CTriangleFactory::GetInstance()
{
	if (!inst)
	{
		inst = new CTriangleFactory();
	}
	return inst;
}

void CTriangleFactory::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

CTriangleFactory *CTriangleFactory::inst = nullptr;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  