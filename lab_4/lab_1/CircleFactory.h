#pragma once

#include "Body.h"
#include "Circle.h"

class CCircleFactory
{
public:
	std::shared_ptr<IBody> CreateBody(std::vector<SShapeParams> points) const;
	static CCircleFactory* GetInstance();
	static void DeleteInstance();

private:
	static CCircleFactory *instance;
};
