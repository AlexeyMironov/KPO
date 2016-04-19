#pragma once

#include "Body.h"
#include "Triangle.h"


class CTriangleFactory
{
public:
	std::shared_ptr<IBody> CreateBody(std::vector<SShapeParams> points) const;
	static CTriangleFactory& GetInstance();

private:
	CTriangleFactory(){}
	CTriangleFactory(const CTriangleFactory&);
	CTriangleFactory& operator =(CTriangleFactory&);
};
                                                                                                                                                                                                                                                                                                 