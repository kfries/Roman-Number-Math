#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

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

RomanNumber rnEncode(char *rnumber) {
   RomanNumber returnValue;
   int idx, idx2;

   returnValue.Size = 0;

   for ( idx = 0; idx < strlen(rnumber); idx++) {
      RomanDigit digit = rdEncode(rnumber[idx]);

      if (digit.Value == 0) {
         returnValue.Size = 0;
         for (idx2 = 0; idx2 < 100; idx2++) returnValue.Digit[idx2] = digit;
         break;
      } else {
         returnValue.Digit[returnValue.Size] = digit;
         if (returnValue.Size > 0)
            if (returnValue.Digit[returnValue.Size].Value > returnValue.Digit[returnValue.Size-1].Value)
               returnValue.Digit[returnValue.Size-1].Value *= -1;
         returnValue.Size++;
      }
   }

   return returnValue;

}

char *rnPrint(RomanNumber number) {
   int idx;
   char *returnValue = (char *)malloc(number.Size+1);
   returnValue[number.Size] = '\0';

   for (idx = 0; idx < number.Size; idx++)
      returnValue[idx] = number.Digit[idx].Symbol;

   return returnValue;
}

uint32_t rnValue(RomanNumber number) {
   int idx;
   uint32_t returnValue = 0;

   for (idx = 0; idx < number.Size; idx++) returnValue += number.Digit[idx].Value;

   return returnValue;
}
