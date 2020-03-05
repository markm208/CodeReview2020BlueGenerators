#include <iostream>
#include "characteristic.h";
using namespace std;



int main()
{
	int characteristic=0;
	char numString[] = "100.0";
	//char part = numString[1]+numString[0];
	const char *str = (char *)numString[0];
	characteristic = atoi(str);
	//characteristic = (int)(numString[0]);

	//characteristic = (int)(part);

	if (characteristic == true)
	{
		//Do something to make it to a int;
		//characteristic = numString[1];
	}

	cout << characteristic;

	//sscanf(numString[0], "%d", characteristic);
	//cout << characteristic;

	return 0;
}

bool characteristic(char numString[], int &c)
{
	bool retVal = true;
	int i=0;
	while(numString[i] != '\0')
	{
		if(numString[i]=='.')
		{
			retVal = false;
			break;
		}
		i++;
	}
	return retVal;
}
