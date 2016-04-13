#pragma once

#include "MyLongNumber.h"

struct SPoint
{
	CMyLongNumber x;
	CMyLongNumber y;
};

struct SShapeParams
{
	CMyLongNumber x;
	CMyLongNumber radius;
	CMyLongNumber y;

	operator SPoint();
};

