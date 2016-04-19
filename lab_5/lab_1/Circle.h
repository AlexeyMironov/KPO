#pragma once
#include "Body.h"
#include "Point.h"

class CCircle final :
	public IBody
{
public:
	CCircle(SPoint p, CMyLongNumber radius);
	~CCircle();

	virtual CMyLongNumber GetPerimeter() const override;
	virtual CMyLongNumber GetArea() const override;
	CMyLongNumber GetRadius() const;
	void Accept(CBodyVisitor &visitor) const override;
private:
	CMyLongNumber m_radius;
	SPoint m_p;
};

