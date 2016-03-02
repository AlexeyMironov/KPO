#pragma once

class CMyLongNumber final
{
public:
	CMyLongNumber(std::vector<int> number);
	~CMyLongNumber();

	vector<int> GetNumber() const;
	//vector<int> Subtraction() const;
	//void LevelUp(vector<int> &num, int &amount);
	int GetLargestNumber(const CMyLongNumber &num1, const CMyLongNumber &num2);

private:
	std::vector<int> m_number;
	//int amount;
	//vector<int> num;
};

const CMyLongNumber operator + (const CMyLongNumber &num1, const CMyLongNumber &num2);
const CMyLongNumber operator - (CMyLongNumber &num1, CMyLongNumber &num2);
const CMyLongNumber operator * (const CMyLongNumber &num1, const CMyLongNumber &num2);
const CMyLongNumber operator / (const CMyLongNumber &num1, CMyLongNumber &num2);

//std::ifstream & operator>>(std::ifstream & stream, CMyLongNumber & number);