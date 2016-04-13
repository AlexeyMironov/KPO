#include "stdafx.h"
#include "RectangleFactory.h"
#include "Rectangle.h"

std::shared_ptr<IBody> CRectangleFactory::CreateBody(std::vector<SShapeParams> points) const
{
	return std::make_shared<CRectangle>(points[0], points[1]);
}

CRectangleFactory* CRectangleFactory::GetInstance()
{
	if (!instance)
	{
		instance = new CRectangleFactory();
	}
	return instance;
}

void CRectangleFactory::DeleteInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

CRectangleFactory *CRectangleFactory::instance = nullptr;