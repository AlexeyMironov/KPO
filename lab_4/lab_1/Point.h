#pragma once

struct SPoint
{
	int x;
	int y;
};

struct SShapeParams
{
	union{
		int x;
		int radius;
	};
	int y;

	operator SPoint();
};

