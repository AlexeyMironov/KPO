// lab_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyLongNumber.h"

int _tmain(int argc, _TCHAR* argv[])
{
	string inFileName = "input.txt";
	ifstream inFile(inFileName);

	if (!inFile)
	{
		return false;
	}

	string outFileName = "output.txt";
	ofstream outFile(outFileName);
	
	while (!inFile.eof())
	{
		string number1, mathOperator, number2;
		inFile >> number1 >> mathOperator >> number2;
		CMyLongNumber result(number1, mathOperator, number2);
		outFile << number1 << " " << mathOperator << " " << number2 << " = ";
		vector<int> res = result.GetNumber();
		if (res.size() > 0)
		{
			for (int i = 0; i < res.size(); i++)
			{
				outFile << res[i];
			}
			outFile << endl;
		}
		else
		{
			outFile << "ERROR (Деление на 0 невозможно!)" << endl;
		}
	}

	cout << "completed!" << endl;
	system("pause");
	return 0;
}

