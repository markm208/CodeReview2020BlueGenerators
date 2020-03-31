#include <iostream>
using namespace std;

int improperFracNum(int whole, int num, int den) {
  int improperNum = (den * whole) + num;
  return improperNum;
}

int findLCM(int a, int b) {
  int LCM, temp_a, temp_b;
  temp_a = a;
  temp_b = b;

  // one of the numbers is divisible by the other
  if (a % b == 0)
    LCM = a;
  else if (b % a == 0) 
    LCM = b;

  // executes until one of the numbers is equal to the other
  while (temp_a % temp_b != 0 || temp_b % temp_a != 0){
    if (temp_a > temp_b)
      temp_b += b;
    else
      temp_a += a;
  }
  LCM = temp_a;
  return LCM;
}

int applyLCM (int n, int d, int lcm) {
  int mult = lcm / d;
  return n * mult;
}

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
  bool flag = false;
  int num1 = improperFracNum(c1, n1, d1);
  int num2 = improperFracNum(c2, n2, d2);
  int LCM = findLCM(d1, d2);
  int addedNum = applyLCM(num1, d1, LCM) + applyLCM(num2, d2, LCM);
  // convert back to proper fractions
  return flag;
}

bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len) {
  bool flag = false;
  int num1 = improperFracNum(c1, n1, d1);
  int num2 = improperFracNum(c2, n2, d2);
  int LCM = findLCM(d1, d2);
  int subNum = applyLCM(n1, d1, LCM) - applyLCM(n2, d2, LCM);
  // convert back to proper fractions
  return flag;
}

int main() {
  char answer[10];
  int c1, n1, d1;
  int c2, n2, d2;
  
  c1 = 1;
  n1 = 1;
  d1 = 2;
  
  c2 = 2;
  n2 = 2;
  d2 = 3; 

  cout << findLCM(3, 6) << endl;
  
  add(c1, n1, d1, c2, n2, d2, answer, 10);

  if(add(c1, n1, d1, c2, n2, d2, answer, 10)) {
    // display string with answer
  }

  else {
    cout << "Function could not be completed" << endl;
  }
  return 0;
}