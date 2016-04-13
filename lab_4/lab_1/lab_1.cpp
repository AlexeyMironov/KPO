// lab_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <memory>

#include "Body.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

shared_ptr<IBody> AddBody();
vector<shared_ptr<IBody>> bodies;

typedef shared_ptr<IBody> CBodyPointer;

SShapeParams PointReader(string &paramsStr)
{
	vector<int> args;
	SShapeParams point;
	const string symbols = " ,;=CRP";
	size_t end, beg;
	end = 0;
	while ((beg = paramsStr.find_first_not_of(symbols, end)) != paramsStr.npos)
	{
		end = paramsStr.find_first_of(symbols, beg);
		args.push_back(stoi(paramsStr.substr(beg, end - beg)));
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
	return make_shared<CTriangle>(points[0], points[1], points[2]);
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
	return make_shared<CRectangle>(points[0], points[1]);
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
	return make_shared<CCircle>(points[0], points[1].radius);
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
	string inFileName = "input.txt";
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
		outFile << typeBody << " P = " << body->GetPerimeter() << "; S = " << body->GetArea() << endl;
	}

	cout << "completed!" << endl;
	system("pause");
	return 0;
}

