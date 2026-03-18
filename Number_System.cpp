#include <string>
#include "Number_System.h"
#include <iostream>
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
			int decimal;
			cout << "Enter Decimal Number: ";
			cin >> decimal;
			int octal = Decimal_Octal(decimal);
			cout << "Octal = " << octal << endl;
		}
		else if (input2 == 3)
		{
			int decimal;
			cout << "Enter Decimal Number: ";
			cin >> decimal;
			string hexa = Decimal_HexaDecimal(decimal);
			cout << "HexaDecimal = " << hexa << endl;
		}
		else if (input2 == 4)
		{
			Decimal_Binary();
		}
		else if (input2 == 5)
		{
			string temp;
			cout << "Enter Decimal Number: ";
			cin >> temp;
			Decimal_BCD(temp);
		}
		break;
	case 2:
		if (input2 == 1)
		{
			int decimal = Octal_Decimal();
			cout << "Decimal = " << decimal << endl;
		}
		else if (input2 == 2)
		{
			Binary_Octal();
		}
		else if (input2 == 3)
		{
			Binary_HexaDecimal();
		}
		else if (input2 == 4)
		{
			Binary_Binary();
		}
		else if (input2 == 5)
		{
			Binary_BCD();
		}
		break;
	case 3:
		break;
	case 4:
		if (input2 == 1)
		{
			int decimal = Binary_Decimal();
			cout << "Decimal = " << decimal << endl;
		}
		else if (input2 == 2)
		{
			Binary_Octal();
		}
		else if (input2 == 3)
		{
			Binary_HexaDecimal();
		}
		else if (input2 == 4)
		{
			Binary_Binary();
		}
		else if (input2 == 5)
		{
			Binary_BCD();
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

int Numbers::Decimal_Octal(int decimal)
{

	string octal = " ";
	while (decimal >= 1)
	{
		int rem;
		rem = decimal % 8;
		decimal /= 8;
		string r = to_string(rem);
		octal += r;
	}
	int octalNum = stoi(octal);
	return octalNum;
}

string Numbers::Decimal_HexaDecimal(int decimal)
{
	string hexa = " ";

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
	return hexa;
}

string Numbers::Decimal_BCD(string temp)
{
	vector<string> decimal;
	decimal.push_back(temp);

	string bcd = " ";
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
	return bcd;
}

void Numbers::Binary_Binary()
{
	string binary;
	cout << "Enter Binary Number: ";
	cin >> binary;
	cout << "Binary = " << binary << endl;
}

int Numbers::Binary_Decimal()
{
	vector<string> binary;
	string temp;
	cout << "Enter Binary Number: ";
	cin >> temp;
	binary.push_back(temp);
	int decimal = 0;

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
	return decimal;
}

void Numbers::Binary_Octal()
{
	int decimal = Binary_Decimal();
	int octal = Decimal_Octal(decimal);
	cout << "Octal = " << octal << endl;
}

void Numbers::Binary_HexaDecimal()
{
	int decimal = Binary_Decimal();
	string hexa = Decimal_HexaDecimal(decimal);
	cout << "HexaDecimal = " << hexa << endl;
}

void Numbers::Binary_BCD()
{
	int decimal = Binary_Decimal();
	string s = to_string(decimal);
	string bcd = Decimal_BCD(s);
	cout << "BCD = " << bcd << endl;
}

int Numbers::Octal_Decimal()
{
	vector<string> binary;
	string temp;
	cout << "Enter Octal Number: ";
	cin >> temp;
	binary.push_back(temp);
	int decimal = 0;

	for (int i = 0; i < binary.size(); i++)
	{
		int expo = binary[i].length() - 1;

		for (int j = 0; j < binary[i].length(); j++)
		{
			int num = binary[i][j] - '0';
			if (num >= 1 && num <= 8)
			{
				decimal += (pow(8, expo)) * num;
			}
			expo--;
		}
	}
	return decimal;
}