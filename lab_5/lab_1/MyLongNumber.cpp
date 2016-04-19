#include "stdafx.h"
#include "MyLongNumber.h"

using namespace std;

CMyLongNumber::CMyLongNumber()
{
	m_number.push_back(0);
}


CMyLongNumber::CMyLongNumber(vector<int> number)
	: m_number(number)
{
}


CMyLongNumber::~CMyLongNumber()
{
}

vector<int> CMyLongNumber::GetNumber() const
{
	return m_number;
}

vector<int> CMyLongNumber::GetReverseNumber() const
{
	vector<int> num = m_number;
	reverse(num.begin(), num.end());
	return num;
}

vector<int> CMyLongNumber::StringToVectorInt(string &number) const
{
	vector<int> result;
	int num;
	for (int i = 0; i < number.size(); i++)
	{
		result.push_back(static_cast<int>(number[i]) - 48);
	}
	reverse(result.begin(), result.end());
	return result;
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

	for (int i = 0; i < result.size(); i++)
	{
		if (result[0] == 0)
		{
			result.erase(result.begin() + i);
			i = -1;
		}
		else
		{
			i = result.size();
		}
	}

	if (result.size() == 0)
	{
		result.push_back(0);
	}

	reverse(result.begin(), result.end());
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

const CMyLongNumber operator - (const CMyLongNumber &num1, const CMyLongNumber &num2)
{
	vector<int> a = num1.GetNumber();
	vector<int> b = num2.GetNumber();
	vector<int> result = (Subtraction(a, b));
	int i = 0;

	for (i = 0; i < result.size(); i++)
	{
		if (result[0] == 0)
		{
			result.erase(result.begin() + i);
			i = -1;
		}
		else
		{
			i = result.size();
		}
	}

	if (result.size() == 0)
	{
		result.push_back(0);
	}

	reverse(result.begin(), result.end());

	return CMyLongNumber(result);
}

const CMyLongNumber operator * (const CMyLongNumber &num1, const CMyLongNumber &num2)
{
	vector<int> a = num1.GetNumber();
	vector<int> b = num2.GetNumber();
	vector<int> result;
	if (a[a.size() - 1] == 0 || b[b.size() - 1] == 0)
	{
		result.push_back(0);
	}
	else
	{
		unsigned int length = num1.GetNumber().size() + num2.GetNumber().size() + 1;
		result.resize(length);
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

		for (i = 0; i < result.size(); i++)
		{
			if (result[0] == 0)
			{
				result.erase(result.begin() + i);
				i = -1;
			}
			else
			{
				i = result.size();
			}
		}

		if (isLessZero)
		{
			result[0] = -result[0];
		}
	}
	reverse(result.begin(), result.end());

	return CMyLongNumber(result);
}

const CMyLongNumber operator / (const CMyLongNumber &num1, const CMyLongNumber &num2)
{
	vector<int> a = num1.GetNumber();
	vector<int> b = num2.GetNumber();
	vector<int> result;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (b[0] != 0)
	{
		if (a[0] == 0)
		{
			result.push_back(0);
		}
		else
		{
			int curLen = b.size(); //задаем начальную позицию
			int curRes = 0;
			vector<int> curNum;
			int ix = 0;

			//берем часть массива делимого размером с делитель
			for (ix = 0; ix < curLen; ix++)
			{
				curNum.push_back(a[ix]);
			}

			//если делитель больше, увеличиваем эту часть, добавляя следующую цифру из делимого
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
				bool isLess = true;
				while (isLess)
				{
					if (GetLargestNumber(curNum, b) == 1)  //остаток > делителя
					{
						curRes++;
						curNum = Subtraction(curNum, b);    //уменьшаем, пока осаток больше делителя
						reverse(curNum.begin(), curNum.end());
						if (curNum[curNum.size() - 1] == 0)  //проверяем на лишние нули
						{
							curNum.pop_back();
						}
					}
					else if (GetLargestNumber(curNum, b) == 2)//остаток < делителя
					{
						if (curRes > 0)
						{
							result.push_back(curRes);
							curRes = 0;
						}
						curLen++;
						if (curLen <= a.size())   //добавляем к остатку следующую цифру, если это возможно
						{
							reverse(curNum.begin(), curNum.end());
							curNum.push_back(a[curLen - 1]);
							reverse(curNum.begin(), curNum.end());
						}
						isLess = false;
					}
					else if (GetLargestNumber(curNum, b) == 3) //остаток = делителю
					{
						curRes++;
						result.push_back(curRes);   //запись цифры в результат
						curRes = 0;
						curLen++;
						curNum = {};
						while (curLen <= a.size() && curNum.size() < b.size())
						{
							if (a[curLen - 1] == 0)  //если следующая цифра делимого = 0
							{
								result.push_back(0); //добавляем 0 к результату
								curLen++;
							}
							else
							{
								curNum.push_back(a[curLen - 1]); //иначе добавляем к остатку следующу
							}
						}
						if (GetLargestNumber(curNum, b) == 2 && curNum.size() > 0)
						{
							result.push_back(0);
							isLess = false;
						}
						else if (GetLargestNumber(curNum, b) == 3)
						{
							isLess = false;
						}
					}
				}
				if (curRes > 0)
				{
					result.push_back(curRes);
					curRes = 0;
				}
			}
		}
	}

	reverse(result.begin(), result.end());

	return CMyLongNumber(result);
}

CMyLongNumber pow(const CMyLongNumber &num, int degree)
{
	CMyLongNumber r = num;
	while (degree > 1)
	{
		r = r * num;
		degree--;
	}
	return r;
}

ostream& operator<<(ostream &ofs, const CMyLongNumber &num)
{
	vector<int> number = num.GetReverseNumber();
	for (int i = 0; i < number.size(); i++)
	{
		ofs << number[i];
	}
	return ofs;
}


const CMyLongNumber sqrt(const CMyLongNumber &num)
{
	CMyLongNumber cur;
	// максимальное количество разрядов в ответе
	int pos = (num.GetNumber().size() + 1) / 2;
	vector<int> digits(pos);
	pos--;
	while (pos >= 0)
	{
		int left = 0, right = 9; //r = osn;
		int curDigit = 0;
		while (left <= right) // подбираем текущую цифру
		{
			int m = (left + right) >> 1;
			digits[pos] = m;
			cur = digits;
			if (GetLargestNumber((cur * cur).GetNumber(), num.GetNumber()) == 2 || (GetLargestNumber((cur * cur).GetNumber(), num.GetNumber()) == 3))
			{
				curDigit = m;
				left = m + 1;
			}
			else
				right = m - 1;
		}
		digits[pos] = curDigit;
		pos--;
	}

	cur = digits;
	return cur;
}