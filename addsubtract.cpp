#include <iostream>
#include "addsubtract.hpp"
using namespace std;

// Converts a mixed number to an improper fraction
int improperNumerator(int whole, int num, int den) {
  int impNum = (den * whole) + num;
  return impNum;
}

// Finds the Least Common Multiple between two numbers
int findLCM(int a, int b) {
  int LCM, temp_a, temp_b; // Using temp values preserves original values of a and b
  temp_a = a;
  temp_b = b;

  // Determines LCM if one of the numbers is divisible by the other
  if (a % b == 0)
    LCM = a;
  else if (b % a == 0) 
    LCM = b;

  // Executes until one of the numbers is equal to the other and LCM is found
  while (temp_a % temp_b != 0 || temp_b % temp_a != 0){
    if (temp_a > temp_b)
      temp_b += b;
    else
      temp_a += a;
  }
  LCM = temp_a;
  return LCM;
}

// Displays improper fraction with LCM as denomitator
int applyLCM (int n, int d, int lcm) {
  int mult = lcm / d;
  return n * mult;
}

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {

  int num1 = improperNumerator(c1, n1, d1); // converts first number to improper fraction
  int num2 = improperNumerator(c2, n2, d2); // converts second number to improper fraction
  int LCM = findLCM(d1, d2); // determines LCM of the two numbers
  int addedNum = applyLCM(num1, d1, LCM) + applyLCM(num2, d2, LCM);
  cout << addedNum << " over " << LCM << endl;
  cout << addedNum / LCM << " and " << addedNum % LCM << " over " << LCM << endl;

  return true;
}

bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
  bool flag = false;

  int num1 = improperNumerator(c1, n1, d1); // converts first number to improper fraction
  int num2 = improperNumerator(c2, n2, d2); // converts second number to improper fraction
  int LCM = findLCM(d1, d2); // determines LCM of the two numbers
  int subbedNum = applyLCM(num1, d1, LCM) - applyLCM(num2, d2, LCM);
  cout << subbedNum << " over " << LCM << endl;
  cout << subbedNum / LCM << " and " << subbedNum % LCM << " over " << LCM << endl;

  return true;
}