#pragma once
#include "Body.h"
#include "Point.h"


class CRectangle final :
	public IBody
{
public:
	CRectangle(SPoint p1, SPoint p2);
	~CRectangle();
	virtual CMyLongNumber GetPerimeter() const override;
	virtual CMyLongNumber GetArea() const override;
private:
	SPoint m_p1, m_p2;
};

