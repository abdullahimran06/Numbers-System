#pragma once
#ifndef NUMBER_SYSTEM_H
#define NUMBER_SYSTEM_H
#include <string>

class Numbers
{
private:
	int input;
	int input2;

public:
	const void Menu();
	const void Menu2();
	void setInput(int input);
	int getInput() const;
	void setInput2(int input2);
	int getInput2() const;
	void Navigations();
	void Navigations2();

	void Decimal_Decimal();
	void Decimal_Binary();
	int Decimal_Octal(int decimal);
	std::string Decimal_HexaDecimal(int decimal);
	std::string Decimal_BCD(std::string decimal);

	int Binary_Decimal();
	void Binary_Binary();
	void Binary_Octal();
	void Binary_HexaDecimal();
	void Binary_BCD();

	int Octal_Decimal();
};

#endif
