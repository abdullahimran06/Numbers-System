#include "Number_System.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;


string reverse(string str)
{ 
	int s, e;
	s = 0;
	e = (str.length()) - 1;
	char temp;
	while (s < e)
	{
		temp = str[s];
		str[s] = str[e];
		str[e] = temp;
		s++;
		e--;
	}
	return str;
}

const void Numbers::Menu()
{
	cout << "1. Decimal" << endl;
	cout << "2. Octal" << endl;
	cout << "3. HexaDecimal" << endl;
	cout << "4. Binary" << endl;
	cout << "5. BCD" << endl;
	cout << "6. Exit" << endl;

	int inp;
	cout << "Choose a Number System: ";// which no is user is going to enter 
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

void Numbers::setInput(int input) {
	this->input = input;
}
int Numbers::getInput() const {
	return input;
}

void Numbers::setInput2(int input2) {
	this->input2 = input2;
}
int Numbers::getInput2() const {
	return input2;
}

void Numbers::Navigations()
{
	Menu();
	int input = getInput();
	switch (input)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		Menu2();
		Navigations2();
		break;
	case 6:
		cout << "exit"<<endl;
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

	case 1: // decimal to other function conversion
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
		if (input2 == 1)
		{
			Binary_Decimal();
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
	cout << "Binary = " << decimal << endl; // ???? why binary
}

void Numbers::Decimal_Binary()
{
	int decimal;
	string binary = "";
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
	binary = reverse(binary);
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
			if (decimal[i][j] == '0')
				bcd += "0000 ";
			else if (decimal[i][j] == '1')
				bcd += "0001 ";
			else if (decimal[i][j] == '2')
				bcd += "0010 ";
			else if (decimal[i][j] == '3')
				bcd += "0011 ";
			else if (decimal[i][j] == '4')
				bcd += "0100 ";
			else if (decimal[i][j] == '5')
				bcd += "0101 ";
			else if (decimal[i][j] == '6')
				bcd += "0110 ";
			else if (decimal[i][j] == '7')
				bcd += "0111 ";
			else if (decimal[i][j] == '8')
				bcd += "1000 ";
			else if (decimal[i][j] == '9')
				bcd += "1001 ";
		}
	}

	cout << "BCD =" << bcd << endl;
}

int stringToInt(string s)
{
	int num = 0;

	for (int i = 0; i < s.length(); i++)
	{
		num = num * 10 + (s[i] - '0');
	}

	return num;
}

void Numbers::Binary_Decimal()
{
	vector<string> binary;
	int decimal = 0;
	string temp;
	cout << "Enter Binary Number: ";
	cin >> temp;
	binary.push_back(temp);
	for (int i = 0; i < binary.size(); i++)
	{
		int expo = binary[i].length() - 1;

		for (int j = 0; j < binary[i].length(); j++)
		{
			int num = binary[i][j] - '0';
			if (num == 1)
			{
				decimal += (pow(2, expo)) * num;
			}
			expo--;
		}
	}
	cout << "Decimal = " << decimal << endl;
}
