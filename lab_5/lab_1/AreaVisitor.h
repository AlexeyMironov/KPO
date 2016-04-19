#pragma once
#include "BodyVisitor.h"
#include "MyLongNumber.h"

class CAreaVisitor :
	public CBodyVisitor
{
public:
	CMyLongNumber result;
	void Visit(CCircle const& body) override final;
	void Visit(CRectangle const& body) override final;
	void Visit(CTriangle const& body) override final;
};

