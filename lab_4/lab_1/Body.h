#pragma once

#include "stdafx.h"
#include "Point.h"


class IBody
{
public:
	IBody();
	virtual ~IBody();

	virtual CMyLongNumber GetPerimeter() const = 0;
	virtual CMyLongNumber GetArea() const = 0;
};
