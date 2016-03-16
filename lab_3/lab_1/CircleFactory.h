#pragma once

#include "Body.h"
#include "Circle.h"

using namespace std;

class CCircleFactory
{
public:
	std::shared_ptr<IBody> CreateBody(vector<SShapeParams> points) const;
	static CCircleFactory* GetInstance();
	static void DestroyInstance();

private:
	static CCircleFactory *inst;
};
