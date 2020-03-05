//
//  Mantissa.cpp
//  Mantissa
//
//  Created by Noah Lindner on 3/5/20.
//  Copyright © 2020 Noah Lindner. All rights reserved.
//

#include <iostream>
#include "mantissa.h"


using namespace std;

//checks to see if numstring contains a period, if not returns false and the number in the cstring is not valid
bool floatCheck(char numstring[]){
    for (int i = 0; i < strlen(numstring);i++){
        if(numstring[i] == '.'){
            if(numstring[i + 1] != '\0'){ //makes sure there is something after the decimal
            return true;
            }
        }
    }
    return false;
}

//takes the number of sig digits after the decimal. Will use this for tempstrings size in the numerator function
int sigDigits(char numstring[]){
    int sigdigits = 0;
    for(int i = 0; i <strlen(numstring);i++){
        if(numstring[i] == '.'){
            for(int j = i + 1;j < strlen(numstring);j++){
            if(numstring[i] != '0'){
                sigdigits++;
                }
            }
            break;
        }
    }
    return sigdigits;
}

//will create a temp string of size sigDigits. The temp string will hold all the decimals after the period and need to be converted to a int
char solveNumerator(char numstring[], int numerator){
    int decnum = 0;         //will be used to increment the tempstring array
    int size = sigDigits(numstring); //sets int size to the amount of significant digits
    
    //contains the numbers after the decimal, sized to the number of sig digits...strlen yields 6 for some reason I cannot figure out
    char tempstring [size];
    
    for(int i = 0; i < strlen(numstring); i++){
        if(numstring[i] == '.'){
            for(int j = i + 1; j < strlen(numstring);j++){
                tempstring[decnum] = numstring[j];      //tempstring now holds all the numbers after the decimal
                decnum++;
            }
            break;
        }
    }
    
    //should return 456 but this only returns 4.... it should be 456 in this example. however I did tests on my tempstring array and at tempstring[1] and tempstring[2] I was holding the 5 and 6 like I was supposed to be. I could not figure out how to pass this all through into my mantissa function though
    return *tempstring;
}

//uses the number of sig digits to figure out what the denominator should be.
int solveDenominator(char numstring[], int denominator){
    denominator = 1;
    for(int i = 0; i < sigDigits(numstring);i++){
        denominator *= 10;      //increments by tens for correct denominator size
    }
    return denominator;
}

//checks to make sure numstring is legal and then creates the mantissa
bool mantissa(char numstring[], int & numerator, int& denominator){
    if(floatCheck(numstring)){
    numerator = solveNumerator(numstring, numerator);
    denominator = solveDenominator(numstring, denominator);
    return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    char number[] = "123.456";
    int n,d;
    
    if(mantissa(number, n, d))
    {
        //test code
        floatCheck(number);
        sigDigits(number);
        solveNumerator(number,n);
        solveDenominator(number, d);
        
    }
    else
    {
        //handle the error on input
    }

    return 0;
}
