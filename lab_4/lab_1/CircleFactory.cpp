#include "stdafx.h"
#include "CircleFactory.h"
#include "Circle.h"

std::shared_ptr<IBody> CCircleFactory::CreateBody(std::vector<SShapeParams> points) const
{
	return std::make_shared<CCircle>(points[0], points[1].radius);
}

CCircleFactory& CCircleFactory::GetInstance()
{
	/*if (!instance)
	{
		instance = new CCircleFactory();
	}*/
	static CCircleFactory instance;
	return instance;
}

/*void CCircleFactory::DeleteInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

CCircleFactory *CCircleFactory::instance = nullptr;*/