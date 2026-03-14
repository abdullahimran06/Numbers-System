#pragma once
#ifndef NUMBER_SYSTEM_H
#define NUMBER_SYSTEM_H

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
	void Decimal_Octal();
	void Decimal_HexaDecimal();
	void Decimal_BCD();

	void Binary_Decimal();
};

#endif
