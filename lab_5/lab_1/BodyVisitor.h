#pragma once

class CCircle;
class CRectangle;
class CTriangle;

class CBodyVisitor
{
public:
	virtual ~CBodyVisitor() = default;
	virtual void Visit(CCircle const& body) = 0;
	virtual void Visit(CRectangle const& body) = 0;
	virtual void Visit(CTriangle const& body) = 0;
};