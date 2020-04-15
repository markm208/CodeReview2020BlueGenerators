#include <iostream>
#include "characteristic.h";
using namespace std;



bool characteristic(const char numString[], int &c)
{
	bool retVal = true;
	
	int size = strlen(numString);
	int spaces = 0;

	//Counts how many spaces there are 
	for (int i = 0; i < size; i++)
	{
		if (numString[i] == ' ')
		{
			spaces++;
		}
	}

	//This checks to see if '.' is the only character in the string
	//if it is then it is not valid
	if (numString[0] == '.' && size == 1)
	{
		retVal = false;
	}

	//if there are only spaces, then there is no characteristic
	//or mantissa
	if (size == spaces)
	{
		retVal = false;
	}

	//Loop goes through to the decimal and if a character is past 9 
	// then it is wrong
	int i = 0;
	while (numString[i] != '.')
	{
		if (numString[i] > '9')
		{
			retVal = false;
			break;
		}

		i++;
	}

	return retVal;
}

int convertToNum(const char numString[])
{
	//positon without spaces and Signs
	int sign = 1;
	int posWOSpaceSigns = 0;
	int size = strlen(numString);
	//Counts what will be the offset to where the real numbers will be
	//also it will keep track of the sign that it should be in the end
	for (int i = 0; i < size; i++)
	{
		if (numString[i] == ' ')
		{
			posWOSpaceSigns++;
		}
		if (numString[i] == '-')
		{
			sign = -1;
			posWOSpaceSigns++;
		}
		if (numString[i] == '+')
		{
			posWOSpaceSigns++;
		}
	}

	//adds how many significant figure values there are in the array up the decimal
	int sigFig = 0;
	for (int i = 0; i < size; i++)
	{
		if (numString[posWOSpaceSigns + i] == '.')
		{
			break;
		}
		else
		{
			sigFig++;
		}
	}

	//running sum of the string getting converted to a characteristic
	int wholeNum = 0;

	//converts the char array to integers and adds them together 
	for (int i = 0; i < sigFig; i++)
	{
		wholeNum = (sign)*((numString[posWOSpaceSigns+i] - '0') * (getSigVal(sigFig-i)))+wholeNum;
	}

	return wholeNum;

}

//Function is to get the significant value of the place of the number that is getting sent in
//works like a power function
int getSigVal(int sigNum)
{
	int value = 1;
	for (int i = 0; i < sigNum-1; i++)
	{
		value = value * 10;
	}

	return value;
}

