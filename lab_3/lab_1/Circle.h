#pragma once
#include "Body.h"
#include "Point.h"

class CCircle final :
	public IBody
{
public:
	CCircle(SPoint p, double radius);
	~CCircle();

	virtual double GetPerimeter() const override;
	virtual double GetArea() const override;
private:
	double m_radius;
	SPoint m_p;
};

