#include <iostream>
#include "characteristic.h";
using namespace std;


int main()
{
	int wholeNum = 0;
	char numString[] = "100.0";

	if (characteristic(numString, wholeNum))
	{
		//Do something to make it to a int;
		//characteristic = numString[1];
		cout<<"Valid characteristic"<<endl;
		cout<<characteristic<<endl;;
	}
	else
	{
		cout<<"not a valid characteristic"<<endl;
	}
	
	cout << numString;

	return 0;
}

bool characteristic(char numString[], int &c)
{
	bool retVal = true;
	int i=0;
	while(numString[i] != '.')
	{
		if(numString[i]=='\0')
		{
			retVal = false;
			break;
		}
		i++;
	}
	return retVal;
}


