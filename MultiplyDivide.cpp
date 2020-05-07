#include <iostream>
#include "MultiplyDivide.hpp"
using namespace std;

// counts the number of characters needed for characteristic c
int count(int c)
{
	int count = 0;
	if (c < 0)
	{
		c *= -1;
		count++;
	}
	if (c == 0)
	{
		count++;
	}
	while (c != 0)
	{
		c = c / 10;
		count++;
	}
	return count;
}

bool checkMantissa(int num, int den)
{
	// Neither should be negative and denominator should not equal 0
	return num >= 0 && den > 0;
}

bool toCharArray(int c, int n, int d, char result[], int len)
{
	if (!checkMantissa(n, d) || n > d)
	{
		return false;
	}
	len -= 1; // for \0 character
	bool neg = (c < 0);
	if ((count(c) > len))
	{
		return false;
	}

	if (neg)
	{
		result[0] = '-';
		c *= -1;
	}

	// Place all digits of characteristic in char array
	int countC = count(c);
	for (int i = 0; i < countC; i++)
	{
		int place = 1;
		for (int j = 1; j < count(c); j++)
		{
			place *= 10;
		}
		int digit = c / place;
		c -= digit * place;
		result[neg + i] = char(digit + 48);
	}

	int currentIndex = (countC + neg);
	int rem = n % d;
	// If there's room for a decimal, place decimal
	if (currentIndex < len && rem != 0)
	{
		result[currentIndex] = '.';
	}
	else
	{
		result[currentIndex] = '\0';
	}

	// Long division to get each digit of mantissa
	// for any remaining space in char array
	int i = (currentIndex + 1);
	for (; i < len && rem != 0; i++)
	{
		rem *= 10;
		int digit = rem / d;
		result[i] = char(digit + 48);
		rem = rem % d;
	}
	result[i] = '\0';

	return true;
}

bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	if (!checkMantissa(n1, d1) || !checkMantissa(n2, d2) || len <= 0)
	{
		return false;
	}

	// final character, final numerator, and final denominator are held in c3, n3, and d3 resepctively. This combination of character and mantissa can be found using simple algebra
	// Absolute characteristics are used to maintain correct algebra
	int c3 = 0;
	int n3 = (abs(c1) * d1 + n1) * (abs(c2) * d2 + n2);
	int d3 = d1 * d2;

	// If the result should be negative, adjust mantissa
	if (c1 < 0 ^ c2 < 0)
	{
		n3 *= -1;
	}

	// The final numerator may be greater than the denominator, effectively making it have a characteristic and mantissa itself
	// This adds said characteristic to the final characteristic, and adjusts the final numerator to now reflect the true mantissa
	int divRes = n3 / d3;
	c3 += divRes;
	n3 -= divRes * d3;
	if (n3 < 0)
	{
		n3 *= -1;
	}

	return toCharArray(c3, n3, d3, result, len);
}

bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
	if (!checkMantissa(n1, d1) || !checkMantissa(n2, d2) || len <= 0)
	{
		return false;
	}

	// final character, final numerator, and final denominator are held in c3, n3, and d3 resepctively. This combination of character and mantissa can be found using simple algebra
	int c3 = 0;
	int n3 = d2 * (abs(c1) * d1 + n1);
	int d3 = d1 * (abs(c2) * d2 + n2);
	// If the result should be negative, adjust mantissa
	if (c1 < 0 ^ c2 < 0)
	{
		n3 *= -1;
	}

	// The final numerator may be greater than the denominator, effectively making it have a characteristic and mantissa itself
	// This adds said character to the final character, and adjusts the final numerator to now reflect the mantissa
	int divRes = n3 / d3;
	c3 += divRes;
	n3 -= divRes * d3;
	if (n3 < 0)
	{
		n3 *= -1;
	}

	return toCharArray(c3, n3, d3, result, len);
}
