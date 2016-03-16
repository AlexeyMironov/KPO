#pragma once

#include "stdafx.h"


class IBody
{
public:
	IBody();
	virtual ~IBody();

	virtual double GetPerimeter() const = 0;
	virtual double GetArea() const = 0;
};
