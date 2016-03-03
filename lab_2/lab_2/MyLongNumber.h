#pragma once

class CMyLongNumber final
{
public:
	CMyLongNumber(std::string number1, std::string mathOperator, std::string number2);
	CMyLongNumber(std::vector<int> number);
	~CMyLongNumber();

	vector<int> StringToVectorInt(string &number) const;
	vector<int> GetNumber() const;
	int GetLargestNumber(vector<int> &a, vector<int> &b);

private:
	std::vector<int> m_number;
	std::string m_number1, m_number2, m_mathOperator;
};

const CMyLongNumber operator + (const CMyLongNumber &num1, const CMyLongNumber &num2);
const CMyLongNumber operator - (CMyLongNumber &num1, CMyLongNumber &num2);
const CMyLongNumber operator * (const CMyLongNumber &num1, const CMyLongNumber &num2);
const CMyLongNumber operator / (const CMyLongNumber &num1, const CMyLongNumber &num2);