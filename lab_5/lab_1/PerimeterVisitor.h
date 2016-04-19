#pragma once

#include "BodyVisitor.h"
#include "MyLongNumber.h"

class CPerimeterVisitor :
	public CBodyVisitor
{
public:
	CMyLongNumber result;
	void Visit(CCircle const& shape) override final;
	void Visit(CRectangle const& shape) override final;
	void Visit(CTriangle const& shape) override final;
};

