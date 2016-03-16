#include "stdafx.h"
#include "RectangleFactory.h"
#include "Rectangle.h"

std::shared_ptr<IBody> CRectangleFactory::CreateBody(vector<SShapeParams> points) const
{
	return std::make_shared<CRectangle>(points[0], points[1]);
}

CRectangleFactory* CRectangleFactory::GetInstance()
{
	if (!inst)
	{
		inst = new CRectangleFactory();
	}
	return inst;
}

void CRectangleFactory::DestroyInstance()
{
	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

CRectangleFactory *CRectangleFactory::inst = nullptr;