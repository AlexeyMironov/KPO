#pragma once

#include "Body.h"
#include "Rectangle.h"

using namespace std;

class CRectangleFactory
{
public:
	std::shared_ptr<IBody> CreateBody(vector<SShapeParams> points) const;
	static CRectangleFactory* GetInstance();
	static void DestroyInstance();

private:
	static CRectangleFactory *inst;
};
