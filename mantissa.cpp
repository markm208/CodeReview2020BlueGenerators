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

//finds the length of the array
int stringLength(const char numString[]){
	int i = 0;
	while(numString[i] != '\0'){
		i++;
	}
	return i;
}

//checks for a negative
bool negativeCheck(const char numstring[]){
    for(int i = 0;i < stringLength(numstring);i++){
        if(numstring[i] == '-'){
            if(numstring[i + 1] == '0' || numstring[i + 1] == '.'){
                    return true;
            }
        }
    }
    return false;
}

//checks for a digit
bool digitCheck(char c){
    if(c >= 48 && c <= 57){
    return true;
    }
    return false;
}

//checks for a space
bool spaceCheck(char s){
    if(s == 32)
    {
    return true;
    }
    else
    {
    return false;
    }
}

//checks to see if numstring contains a period, if not returns false and the number in the cstring is not valid
bool floatCheck(const char numstring[]){
    int iter = 0;
    
    while (numstring[iter] != '\0'){
        if(numstring[iter] == '.'){
            if(numstring[iter + 1] != '\0' && numstring[iter + 1] != '0'){ //makes sure there is something after the decimal
            return true;
            }
        }
        if(digitCheck(numstring[iter]) == true && spaceCheck(numstring[iter]) == true){
            return true;
        }
        iter++;
    }
    return false;
}

//converts numerator array into a integer
int solveNumerator(const char numstring[]){
    int result = 0;
    
    if(numstring[0] != '-'){
    for(int i = 0;numstring[i] != '\0';i++){
        result = result * 10 + numstring[i] - '0';
        }
    }
    else{
        for(int i = 1;numstring[i] != '\0';i++){
        result = result * 10 + numstring[i] - '0';
        }
        result = result * -1;
    }
    
    return result;
}

//checks for a decimal point
bool DecChecker(const char numstring[]){
    int iter = 0;
    int endNum = stringLength(numstring) - 1;
    while(numstring[iter] != '\0'){
        if(numstring[iter] == '.'){
            if(numstring[endNum] >= 49 && numstring[endNum] <= 57){
            return true;
            }
        }
        iter++;
    }
    return false;
}
//checks to make sure numstring is legal and then creates the mantissa
bool mantissa(const char numstring[], int & numerator, int& denominator){
    int length = 0;     //holds length of whole array
    int decimalLocation = 0;        //keeps track of decimal
    denominator = 10;               //default value of denominator if there is one
    
    
    while(numstring[length] != '\0'){       //solves for length and decimal location
        if(numstring[length] == '.'){
            decimalLocation = length;
        }
        length++;
    }

    char top[0];                    //array that holds the numbers after the decimal that arent 0
    int iter = 0;                   //incrementor in loops
    int preDec = decimalLocation - 1;       //for checking the number before the decimal
    if(negativeCheck(numstring)){           //if is neagtive and if there is a 0 or - right before the decimal then numerator is -
        if(numstring[preDec] == '0' || numstring[preDec] == '-'){
        top[0] = '-';
        iter++;
        }
    }

    for(int i = decimalLocation;i < length;i++){        //runs through the loop and grabs the non zeros after the decimal
        if(floatCheck(numstring)){
            if(digitCheck(numstring[i])){
                if(numstring[i] == '0'){                //if there is a zero it breaks
                    break;
                }
            top[iter] = numstring[i];                   //top now contains nonzeros after the decimal
            iter++;
            }
        }
    }
    
    int iterator = 0;                                   //another incrementor
    int zeroCounter = 0;                                //counts number of zeros after decimal
    int tens = 1;                                       //will hold the amount of tens columns to add up denominator
    
    //handles if there is zeros afer the decimal but other significant numbers after the zeros
    if(floatCheck(numstring) == false && DecChecker(numstring) == true){
        for(int i = decimalLocation; i < stringLength(numstring); i++){
            if(numstring[i] >= 49 && numstring[i] <= 57){       //only adds the numbers to top if they arent 0
                top[iterator] = numstring[i];
                iterator++;
            }
            if(numstring[i] == '0'){                            //if they are zero increment zerocounter
            zeroCounter++;
            }
        }
        zeroCounter += iterator;                        //zerocounter now contains the amount of tens columns after the decimal
        for(int i = 1;i < zeroCounter;i++){
            tens *= 10;                                 //10 to that power for solving denominator
        }
        numerator = solveNumerator(top);
        denominator = denominator * tens;
        return true;
    }
    
    //if negative number how to solve for denominator
    if(negativeCheck(numstring)){
        iter--;
        if(numstring[preDec] >= 49 && numstring[preDec] <= 57){
            iter++;
        }
        
    for (int i = 0;i < iter - 1; i++){
    denominator = denominator * 10;
        }
    }
    
    //if it is a decimal but not negative solves for denominator
    if(floatCheck(numstring)){
    if(negativeCheck(numstring) == false){
        for (int i = 0;i < iter - 1; i++){
        denominator = denominator * 10;
            }
        }
    }

    //if a decimal and contains letters than return false otherwise solves
    if(floatCheck(numstring)){
        for(int i = 0; i < stringLength(numstring);i++){
            if(numstring[i] >= 97 && numstring[i] <= 122){
                return false;
            }
        }
    numerator = solveNumerator(top);
    return true;
    }
    
    //checks it starts with a non digit and then if the second number is one
    if(digitCheck(numstring[0]) == false && spaceCheck(numstring[0]) == false) {
        if(numstring[1] >= 48 && numstring[1] <= 57){
            return true;
        }
        return false;
    }
    
    //checks if it starts with a space and then checks to see if it contains a digit anywhere
    if(spaceCheck(numstring[0])){
        for(int i = 0; i < stringLength(numstring);i++){
            if(digitCheck(numstring[i])){
                return true;
            }
        }
        return false;
    }

    //if you reached here you set them as there default values for strings that should be parsed
    else{
            numerator = 0;
            denominator = 10;
        return true;
    }
     
    return false;
}
