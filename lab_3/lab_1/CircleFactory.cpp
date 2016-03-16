#include "stdafx.h"
#include "CircleFactory.h"
#include "Circle.h"

std::shared_ptr<IBody> CCircleFactory::CreateBody(vector<SShapeParams> points) const
{
	return std::make_shared<CCircle>(points[0], points[1].radius);
}

CCircleFactory* CCircleFactory::GetInstance()
{
	if (!inst)
	{
		inst = new CCircleFactory();
	}
	return inst;
}

void CCircleFactory::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

CCircleFactory *CCircleFactory::inst = nullptr;