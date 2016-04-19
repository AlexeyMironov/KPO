#pragma once

#include "stdafx.h"
#include "Point.h"

class CBodyVisitor;

class IBody
{
public:
	IBody();
	virtual ~IBody();
	virtual void Accept(CBodyVisitor &visitor) const = 0;

	virtual CMyLongNumber GetPerimeter() const = 0;
	virtual CMyLongNumber GetArea() const = 0;
};
