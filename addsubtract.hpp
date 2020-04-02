#ifndef addsubtract.hpp
#define addsubtract.hpp

#include <stdio.h>
#pragma once

int improperNumerator(int whole, int num, int den);
int findLCM(int a, int b);
int applyLCM (int n, int d, int lcm);
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
