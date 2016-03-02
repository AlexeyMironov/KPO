// lab_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyLongNumber.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> num1 = {-8,9,6,3,4,5,9,7,8,9};
	vector<int> num2 = {6,6,6,6,6,6,6,6,6,6};
	vector<int> num3 = {1,5,6,3,0,1,2,6,4,5,5};
	vector<int> num4 = {1,1,8,9,7,6,5,4,1,2,3};
	vector<int> num5 = {5,9,7,5,6,3,9,8,5,8,7,3,5,7,6,9,3,4,7,3};
	vector<int> num6 = {1,0,0,0,0};
	vector<int> num7 = {1,5,0,0,0};

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	reverse(num3.begin(), num3.end());
	reverse(num4.begin(), num4.end());
	reverse(num5.begin(), num5.end());
	reverse(num6.begin(), num6.end());
	reverse(num7.begin(), num7.end());

	CMyLongNumber number1(num1);
	CMyLongNumber number2(num2);
	CMyLongNumber number3(num3);
	CMyLongNumber number4(num4);
	CMyLongNumber number5(num5);
	CMyLongNumber number6(num6);
	CMyLongNumber number7(num7);
	CMyLongNumber result = number1 * number2;
	vector<int> res = result.GetNumber();
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	cout << endl;

	result = number4 - number3;
	res = result.GetNumber();
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}

	cout << endl;

	result = number1 + number2;
	res = result.GetNumber();
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}

	cout << endl;

	result = number5 / number2;
	res = result.GetNumber();
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	return 0;
}

