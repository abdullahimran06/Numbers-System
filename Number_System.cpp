#include "Number_System.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const void Numbers::Menu()
{
	cout << "1. Decimal" << endl;
	cout << "2. Octal" << endl;
	cout << "3. HexaDecimal" << endl;
	cout << "4. Binary" << endl;
	cout << "5. BCD10" << endl;
	cout << "6. Exit" << endl;

	int inp;
	cout << "Choose a Number System: ";
	cin >> inp;
	setInput(inp);
}

const void Numbers::Menu2()
{
	cout << "1. Decimal" << endl;
	cout << "2. Octal" << endl;
	cout << "3. HexaDecimal" << endl;
	cout << "4. Binary" << endl;
	cout << "5. BCD" << endl;
	cout << "6. Go Back" << endl;
	int inp;
	cout << "Convert to: ";
	cin >> inp;
	setInput2(inp);
}

void Numbers::setInput(int input) { this->input = input; }
int Numbers::getInput() const { return input; }

void Numbers::setInput2(int input2) { this->input2 = input2; }
int Numbers::getInput2() const { return input2; }

void Numbers::Navigations()
{
	Menu();
	int input = getInput();
	switch (input)
	{
	case 1:
		Menu2();
		Navigations2();
		break;
	case 2:
		Menu2();
		Navigations2();
		break;
	case 3:
		Menu2();
		Navigations2();
		break;
	case 4:
		Menu2();
		Navigations2();
		break;
	case 5:
		Menu2();
		Navigations2();
		break;
	case 6:
		break;
	default:
		cout << "Invalid Input!" << endl;
	};
}

void Numbers::Navigations2()
{
	int input = getInput();
	int input2 = getInput2();

	switch (input)
	{

	case 1:
		if (input2 == 1)
		{
			Decimal_Decimal();
		}
		else if (input2 == 2)
		{
			Decimal_Octal();
		}
		else if (input2 == 3)
		{
			Decimal_HexaDecimal();
		}
		else if (input2 == 4)
		{
			Decimal_Binary();
		}
		else if (input2 == 5)
		{
			Decimal_BCD();
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		Navigations();
		break;

	default:
		cout << "Invalid Input!" << endl;
	};
}

void Numbers::Decimal_Decimal()
{
	int decimal;
	cout << "Enter Decimal Number: ";
	cin >> decimal;
	cout << "Binary = " << decimal << endl;
}

void Numbers::Decimal_Binary()
{
	int decimal;
	string binary = " ";
	cout << "Enter Decimal Number: ";
	cin >> decimal;
	while (decimal >= 1)
	{
		if (decimal % 2 == 0)
		{
			decimal /= 2;
			binary += "0";
		}
		else
		{
			decimal /= 2;
			binary += "1";
		}
	}
	cout << "Binary =" << binary << endl;
}

void Numbers::Decimal_Octal()
{
	int decimal;
	string octal = " ";
	cout << "Enter Decimal Number: ";
	cin >> decimal;
	while (decimal >= 1)
	{
		int rem;
		rem = decimal % 8;
		decimal /= 8;
		string r = to_string(rem);
		octal += r;
	}
	cout << "Octal =" << octal << endl;
}

void Numbers::Decimal_HexaDecimal()
{
	int decimal;
	string hexa = " ";
	cout << "Enter Decimal Number: ";
	cin >> decimal;
	while (decimal >= 1)
	{
		int rem;
		rem = decimal % 16;
		decimal /= 16;

		if (rem == 10)
		{
			hexa += "A";
		}
		else if (rem == 11)
		{
			hexa += "B";
		}
		else if (rem == 12)
		{
			hexa += "C";
		}
		else if (rem == 13)
		{
			hexa += "D";
		}
		else if (rem == 14)
		{
			hexa += "E";
		}
		else if (rem == 15)
		{
			hexa += "F";
		}
		else
		{
			string r = to_string(rem);
			hexa += r;
		}
	}
	cout << "HexaDecimal =" << hexa << endl;
}

void Numbers::Decimal_BCD()
{
	vector<string> decimal;
	string bcd = " ";
	string temp;
	cout << "Enter Decimal Number: ";
	cin >> temp;
	decimal.push_back(temp);
	for (int i = 0; i < decimal.size(); i++)
	{
		for (int j = 0; j < decimal[i].length(); j++)
		{
			bcd += decimal[i][j];
		}
	}

	cout << "BCD =" << bcd << endl;
}