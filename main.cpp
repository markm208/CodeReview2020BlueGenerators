#include <iostream>
#include <addsubtract.hpp>
using namespace std;


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

  if(add(c1, n1, d1, c2, n2, d2, answer, 10)) {
    cout << "Addition test completed" << endl;
    cout << endl;
  }

  if(subtract(c1, n1, d1, c2, n2, d2, answer, 10)) {
    cout << "Subtraction test completed" << endl;
    cout << endl;
  }

  else {
    cout << "Function could not be completed" << endl;
  }


  return 0;
}