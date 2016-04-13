#pragma once

#include "Body.h"
#include "Rectangle.h"


class CRectangleFactory
{
public:
	std::shared_ptr<IBody> CreateBody(std::vector<SShapeParams> points) const;
	static CRectangleFactory* GetInstance();
	static void DeleteInstance();

private:
	static CRectangleFactory *instance;
};
