#include "stdafx.h"
#include "Point.h"

SShapeParams::operator SPoint()
{
	SPoint result = { x, y };
	return result;
}