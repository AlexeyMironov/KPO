// lab_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>

#include "MyLongNumber.h"
#include "Body.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "TriangleFactory.h"
#include "RectangleFactory.h"
#include "CircleFactory.h"

using namespace std;

shared_ptr<IBody> AddBody();
vector<shared_ptr<IBody>> bodies;

typedef shared_ptr<IBody> CBodyPointer;

SShapeParams PointReader(string &paramsStr)
{
	vector<CMyLongNumber> args;
	SShapeParams point;
	const string symbols = " ,;=CRP";
	size_t end, beg;
	end = 0;
	while ((beg = paramsStr.find_first_not_of(symbols, end)) != paramsStr.npos)
	{
		end = paramsStr.find_first_of(symbols, beg);
		CMyLongNumber l(vector<int>({ 0 }));
		args.push_back(l.StringToVectorInt(paramsStr.substr(beg, end - beg)));
		beg = end;
	}
	if (args.size() == 3)
	{
		point.x = args[1];
		point.y = args[2];
	}
	else if (args.size() == 2)
	{
		point.x = args[0];
		point.y = args[1];
	}
	else if (args.size() == 1)
	{
		point.radius = args[0];
	}
	return point;
}

shared_ptr<IBody> CreateTriangle(ifstream &file)
{
	vector<SShapeParams> points;
	while (points.size() != 3)
	{
		string paramsStr;
		file >> paramsStr;
		points.push_back(PointReader(paramsStr));
	}
	return CTriangleFactory::GetInstance()->CreateBody(points);
}

shared_ptr<IBody> CreateRectangle(ifstream &file)
{
	vector<SShapeParams> points;
	while (points.size() != 2)
	{
		string paramsStr;
		file >> paramsStr;
		points.push_back(PointReader(paramsStr));
	}
	return CRectangleFactory::GetInstance()->CreateBody(points);
}

shared_ptr<IBody> CreateCircle(ifstream &file)
{
	vector<SShapeParams> points;
	while (points.size() != 2)
	{
		string paramsStr;
		file >> paramsStr;
		points.push_back(PointReader(paramsStr));
	}
	return CCircleFactory::GetInstance()->CreateBody(points);
}



shared_ptr<IBody> AddBody(string const & typeBody, ifstream &file)
{
	shared_ptr<IBody> body;

	if (typeBody == "TRIANGLE:")
	{	
		body = CreateTriangle(file);
	}
	else if (typeBody == "RECTANGLE:")
	{
		body = CreateRectangle(file);
	}	
	else if (typeBody == "CIRCLE:")
	{
		body = CreateCircle(file);
	}
	
	return body;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string inFileName = "inputT.txt";
	ifstream inFile(inFileName);

	shared_ptr<IBody> body;

	if (!inFile)
	{
		return false;
	}

	string outFileName = "output.txt";
	ofstream outFile(outFileName);

	while (!inFile.eof())
	{
		string typeBody;
		inFile >> typeBody;
		body = AddBody(typeBody, inFile);
		/*CMyLongNumber r = body->GetPerimeter();
		CMyLongNumber r1 = body->GetArea();
		CMyLongNumber r2 = body->GetArea();*/
		outFile << typeBody << " P = " << body->GetPerimeter() << "; S = " << body->GetArea() << endl;
	}

	CCircleFactory::DeleteInstance();
	CRectangleFactory::DeleteInstance();
	CTriangleFactory::DeleteInstance();
	cout << "completed!" << endl;
	system("pause");
	return 0;
}

