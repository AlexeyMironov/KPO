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
		result[ix] += a[ix]; // суммируем последние разряды чисел
		result[ix + 1] += (result[ix] / 10); // если есть разряд для переноса, переносим его в следующий разряд
		result[ix] %= 10; // если есть разряд для переноса он отсекается
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
	int k = 3; // если к == 3, значит числа одинаковой длинны
	length = a.size();
	if (a.size() > b.size())
	{
		length = a.size();
		k = 1; // если к == 1, значит первое число длиннее второго
		return k;
	}
	else
		if (b.size() > a.size())
		{
			length = b.size();
			k = 2; // если к == 2, значит второе число длиннее первого
			return k;
		}
		else // если числа одинаковой длинны, то необходимо сравнить их веса
			for (int ix = length - 1; ix >= 0; ix--) // поразрядное сравнение весов чисел
			{
				if (a[ix] > b[ix]) // если разряд первого числа больше
				{
					k = 1; // значит первое число длиннее второго
					return k; // выход из цикла for
				}

				if (b[ix] > a[ix]) // если разряд второго числа больше
				{
					k = 2; // значит второе число длиннее первого
					return k; // выход из цикла for
				}
			} // конец for
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

	for (int ix = 0; ix < length; ix++) // проход по всем разрядам числа, начиная с последнего, не доходя до первого
	{
		if (ix < (length - 1)) // если текущий разряд чисел не первый
		{
			a[ix + 1]--; // в следующуем разряде большего числа занимаем 1.
			result[ix] += 10 + a[ix]; // в ответ записываем сумму значения текущего разряда большего числа и 10-ти
		}
		else  // если текущий разряд чисел - первый
		{
			result[ix] += a[ix]; // в ответ суммируем значение текущего разряда большего числа
		}

		if (ix < b.size())
		{
			result[ix] -= b[ix]; // вычитаем значение текущего разряда меньшего числа
		}

		if (result[ix] / 10 > 0) // если значение в текущем разряде двухразрядное
		{
			result[ix + 1]++; // переносим единицу в старший разряд
			result[ix] %= 10; // в текущем разряде отсекаем ее
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

	int curLen = b.size(); //меньшая 
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
