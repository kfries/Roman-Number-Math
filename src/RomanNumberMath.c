#include <stdio.h>
#include <ctype.h>

#include "RomanNumberMath.h"

#define NUMDIGITS 7

char allowedDigit[NUMDIGITS] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int digitValue[NUMDIGITS] = {1, 5, 10, 50, 100, 500, 1000};

RomanDigit rdEncode(char digit) {
   int idx;
   char target = toupper(digit);
   RomanDigit returnValue;

   returnValue.Symbol = ' ';
   returnValue.Value = 0;

   for (idx = 0; idx < NUMDIGITS; idx++) {
      if (target == allowedDigit[idx]) {
         returnValue.Symbol = allowedDigit[idx];
         returnValue.Value = digitValue[idx];
         break;
      }
   }

   return returnValue;
}
