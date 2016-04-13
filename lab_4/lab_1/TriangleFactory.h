#pragma once

#include "Body.h"
#include "Triangle.h"


class CTriangleFactory
{
public:
	std::shared_ptr<IBody> CreateBody(std::vector<SShapeParams> points) const;
	static CTriangleFactory* GetInstance();
	static void DeleteInstance();

private:
	static CTriangleFactory *instance;
};
                                                                                                                                                                                                                                                                                                 