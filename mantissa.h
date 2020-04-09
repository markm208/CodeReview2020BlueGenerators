//
//  Mantissa.hpp
//  Mantissa
//
//  Created by Noah Lindner on 3/5/20.
//  Copyright © 2020 Noah Lindner. All rights reserved.
//

#ifndef Mantissa_hpp
#define Mantissa_hpp

#include <stdio.h>
#pragma once


bool mantissa(const char numstring[], int & numerator, int& denominator);
int stringLength(const char numString[]);
bool floatCheck(const char numstring[]);
int solveNumerator(const char numstring[]);
bool digitCheck(char c);
bool spaceCheck(char s);
bool negativeCheck(const char numstring[]);
bool DecChecker(const char numstring[]);

#endif /* Mantissa_hpp */
