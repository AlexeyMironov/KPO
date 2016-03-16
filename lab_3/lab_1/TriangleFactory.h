#pragma once

#include "Body.h"
#include "Triangle.h"

using namespace std;

class CTriangleFactory
{
public:
	std::shared_ptr<IBody> CreateBody(vector<SShapeParams> points) const;
	static CTriangleFactory* GetInstance();
	static void DestroyInstance();

private:
	static CTriangleFactory *inst;
};
                                                                                                                                                                                                                                                                                                 