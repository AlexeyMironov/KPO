#pragma once

class CMyLongNumber final
{
public:
	CMyLongNumber(std::vector<int> number);
	CMyLongNumber();
	~CMyLongNumber();

	std::vector<int> StringToVectorInt(std::string &number) const;
	std::vector<int> GetNumber() const;
	std::vector<int> GetReverseNumber() const;
	int GetLargestNumber(std::vector<int> &a, std::vector<int> &b);

private:
	std::vector<int> m_number;
};

const CMyLongNumber operator + (const CMyLongNumber &num1, const CMyLongNumber &num2);
const CMyLongNumber operator - (const CMyLongNumber &num1, const CMyLongNumber &num2);
const CMyLongNumber operator * (const CMyLongNumber &num1, const CMyLongNumber &num2);
const CMyLongNumber operator / (const CMyLongNumber &num1, const CMyLongNumber &num2);
const CMyLongNumber sqrt (const CMyLongNumber &num);
CMyLongNumber pow(const CMyLongNumber &num, int degree);
std::ostream &operator << (std::ostream&, const CMyLongNumber&);
