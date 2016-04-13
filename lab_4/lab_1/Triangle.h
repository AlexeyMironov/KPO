#pragma once
#include "Body.h"
#include "Point.h"


class CTriangle final :
	public IBody
{
public:
	CTriangle(SPoint p1, SPoint p2, SPoint p3);
	~CTriangle();

	virtual CMyLongNumber GetPerimeter() const override;
	virtual CMyLongNumber GetArea() const override;
private:
	SPoint m_p1, m_p2, m_p3;
	static CMyLongNumber GetLineLength(const SPoint &p1, const SPoint &p2);
};

