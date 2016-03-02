#include "stdafx.h"
#include "MyLongNumber.h"


CMyLongNumber::CMyLongNumber(vector<int> number)
	:m_number(number)
{
}


CMyLongNumber::~CMyLongNumber()
{
}

vector<int> CMyLongNumber::GetNumber() const
{
	return m_number;
}



const CMyLongNumber operator + (const CMyLongNumber &num1, const CMyLongNumber &num2)
{
	vector<int> a = num1.GetNumber();
	vector<int> b = num2.GetNumber();
	unsigned int length = a.size() + 1;
	if (a.size() < b.size())
	{
		length = b.size() + 1;
		a = num2.GetNumber();
		b = num1.GetNumber();
	}
	
	vector<int> result = b;
	result.resize(length);

	for (int ix = 0; ix < length - 1; ix++)
	{
		result[ix] += a[ix]; // ��������� ��������� ������� �����
		result[ix + 1] += (result[ix] / 10); // ���� ���� ������ ��� ��������, ��������� ��� � ��������� ������
		result[ix] %= 10; // ���� ���� ������ ��� �������� �� ����������
	}

	if (result[length - 1] == 0)
		length--;

	reverse(result.begin(), result.end());
	int i = 0;
	while (result[i] == 0)
	{
		result.erase(result.begin() + i);
		i++;
	}

	return CMyLongNumber(result);
}

int GetLargestNumber(vector<int> &a, vector<int> &b)
{
	unsigned int length = 0;
	int k = 3; // ���� � == 3, ������ ����� ���������� ������
	length = a.size();
	if (a.size() > b.size())
	{
		length = a.size();
		k = 1; // ���� � == 1, ������ ������ ����� ������� �������
		return k;
	}
	else
		if (b.size() > a.size())
		{
			length = b.size();
			k = 2; // ���� � == 2, ������ ������ ����� ������� �������
			return k;
		}
		else // ���� ����� ���������� ������, �� ���������� �������� �� ����
			for (int ix = length - 1; ix >= 0; ix--) // ����������� ��������� ����� �����
			{
				if (a[ix] > b[ix]) // ���� ������ ������� ����� ������
				{
					k = 1; // ������ ������ ����� ������� �������
					return k; // ����� �� ����� for
				}

				if (b[ix] > a[ix]) // ���� ������ ������� ����� ������
				{
					k = 2; // ������ ������ ����� ������� �������
					return k; // ����� �� ����� for
				}
			} // ����� for
	return k;
}

vector<int> Subtraction(vector<int> a, vector<int> b)
{
	int k = GetLargestNumber(a, b);

	if (k != 1)
	{
		vector<int> temp = a;
		a = b;
		b = temp;
	}
	

	unsigned int length = a.size();
	vector<int> result;
	result.resize(length);

	for (int ix = 0; ix < length; ix++) // ������ �� ���� �������� �����, ������� � ����������, �� ������ �� �������
	{
		if (ix < (length - 1)) // ���� ������� ������ ����� �� ������
		{
			a[ix + 1]--; // � ���������� ������� �������� ����� �������� 1.
			result[ix] += 10 + a[ix]; // � ����� ���������� ����� �������� �������� ������� �������� ����� � 10-��
		}
		else  // ���� ������� ������ ����� - ������
		{
			result[ix] += a[ix]; // � ����� ��������� �������� �������� ������� �������� �����
		}

		if (ix < b.size())
		{
			result[ix] -= b[ix]; // �������� �������� �������� ������� �������� �����
		}

		if (result[ix] / 10 > 0) // ���� �������� � ������� ������� �������������
		{
			result[ix + 1]++; // ��������� ������� � ������� ������
			result[ix] %= 10; // � ������� ������� �������� ��
		}
	}

	reverse(result.begin(), result.end());

	return result;
}

const CMyLongNumber operator - (CMyLongNumber &num1, CMyLongNumber &num2)
{
	vector<int> a = num1.GetNumber();
	vector<int> b = num2.GetNumber();
	vector<int> result = (Subtraction(a, b));
	int i = 0;
	while (i < result.size())
	{
		if (result[i] == 0)
		{
			result.erase(result.begin() + i);
		}
		else
		{
			i = result.size();
		}
		i++;
	}

	if (GetLargestNumber(a, b) != 1)
	{
		result[0] = -result[0];
	}

	return CMyLongNumber(result);
}

const CMyLongNumber operator * (const CMyLongNumber &num1, const CMyLongNumber &num2)
{
	unsigned int length = num1.GetNumber().size() + num2.GetNumber().size() + 1;
	vector<int> result;
	result.resize(length);
	vector<int> a = num1.GetNumber();
	vector<int> b = num2.GetNumber();
	bool isLessZero = false;
	if (a[a.size() - 1] < 0)
	{
		a[a.size() - 1] = -a[a.size() - 1];
		isLessZero = true;
	}

	else if (b[b.size() - 1] < 0)
	{
		b[b.size() - 1] = -b[b.size() - 1];
		isLessZero = true;
	}

	for (int ix = 0; ix < a.size(); ix++)
		for (int jx = 0; jx < b.size(); jx++)
			result[ix + jx] += a[ix] * b[jx];

	for (int ix = 0; ix < length - 1; ix++)
	{
		result[ix + 1] += result[ix] / 10;
		result[ix] %= 10;
	}

	reverse(result.begin(), result.end());
	int i = 0;
	while (result[i] == 0)  ///
	{
		result.erase(result.begin()+i);
		i++;
	}

	if (isLessZero)
	{
		result[0] = -result[0];
	}
	
	return CMyLongNumber(result);
}

const CMyLongNumber operator / (const CMyLongNumber &num1, CMyLongNumber &num2)
{
	vector<int> a = num1.GetNumber();
	vector<int> b = num2.GetNumber();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int curLen = b.size(); //������� 
	int curRes = 0;
	vector<int> result; 
	vector<int> curNum;    
	int ix = 0;
	for (ix = 0; ix < curLen; ix++)
	{
		curNum.push_back(a[ix]);
	}

	
	for (ix = 0; ix < curLen; ix++)
	{
		if (curNum[ix] < b[ix])
		{
			curLen++;
			if (curLen <= a.size())
			{
				curNum.push_back(a[curLen - 1]);
			}
			ix = curLen;
		}
		ix++;
	}

	reverse(b.begin(), b.end());
	reverse(curNum.begin(), curNum.end());

	while (curLen <= a.size())
	{
		bool flag = true;
		while (flag)
		{
			if (GetLargestNumber(curNum, b) == 1)
			{
				curRes++;
				curNum = Subtraction(curNum, b);
				reverse(curNum.begin(), curNum.end());
				if (curNum[curNum.size() - 1] == 0)  ///
				{
					curNum.pop_back();
				}
			}
			else if (GetLargestNumber(curNum, b) == 2)
			{
				curLen++;
				if (curLen <= a.size())
				{
					reverse(curNum.begin(), curNum.end());
					curNum.push_back(a[curLen - 1]);
					reverse(curNum.begin(), curNum.end());
				}
				flag = false;
			}
			else if (GetLargestNumber(curNum, b) == 3)
			{
				curRes++;
				result.push_back(curRes);
				curRes = 0;
				curLen++;
				curNum = {};
				while (curLen <= a.size())
				{
					if (a[curLen - 1] == 0)
					{
						result.push_back(0);
					}
					else
					{
						curNum.push_back(a[curLen - 1]);
					}	
					curLen++;
				}
				flag = false;
			}
		}
		if (curRes > 0)
		{
			result.push_back(curRes);
			curRes = 0;
		}
	}

	return CMyLongNumber(result);
}

/*std::ifstream & operator>>(std::ifstream & stream, CMyLongNumber & number)
{
	vector<int> firstNumber;
	vector<int> secondNumber;
	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		number = CMyLongNumber(numerator, denominator);
		return stream;
	}

	return stream;
}*/
