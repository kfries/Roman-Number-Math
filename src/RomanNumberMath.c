#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

#include "RomanNumberMath.h"

#define NUMDIGITS 7

char allowedDigit[NUMDIGITS] = {'I', 'V', 'X', 'L', 'C', 'D',  'M'  };
int  digitValue[NUMDIGITS]   = { 1,   5,   10,  50, 100, 500,  1000 };
int  nextDigit[NUMDIGITS]    = { 5,   2,   5,   2,   5,   2,  99999 };

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

RomanNumber rnSortDigits(RomanNumber number) {
   RomanNumber returnValue;
   int idx, idx2;

   returnValue.Size = 0;

   for (idx = NUMDIGITS-1; idx >= 0; idx--)
      for (idx2 = 0; idx2 < number.Size; idx2++)
         if (number.Digit[idx2].Symbol == allowedDigit[idx])
            returnValue.Digit[returnValue.Size++] = number.Digit[idx2];
   
   return returnValue;
}

RomanNumber rnConcatinate(RomanNumber number1, RomanNumber number2) {
   RomanNumber returnValue;
   int idx;

   returnValue.Size = number1.Size + number2.Size;

   for (idx = 0; idx < number1.Size; idx++)
      returnValue.Digit[idx] = number1.Digit[idx];

   for (idx = 0; idx < number2.Size; idx++)
      returnValue.Digit[number1.Size + idx] = number2.Digit[idx];

   return returnValue;
}

RomanNumber rnRemoveSubtractiveNotation(RomanNumber number) {
   RomanNumber returnValue;
   int idx, idx2;

   returnValue.Size = 0;

   idx = 0;
   while(idx < number.Size) {
      if (number.Digit[idx].Value > 0) {
         returnValue.Digit[returnValue.Size++] = number.Digit[idx++];
      } else {
         int targetValue = number.Digit[idx+1].Value + number.Digit[idx].Value;

         for (idx2 = NUMDIGITS-1; idx2 >= 0; idx2--) {
            while (targetValue >= digitValue[idx2]) {
               returnValue.Digit[returnValue.Size].Symbol = allowedDigit[idx2];
               returnValue.Digit[returnValue.Size++].Value = digitValue[idx2];
               targetValue -= digitValue[idx2];
            }
         }

         idx += 2;
      }
   }

   return returnValue;
}

RomanNumber rnSimplifyDigits(RomanNumber number) {
   RomanNumber returnValue;
   int counts[NUMDIGITS];
   int idx, idx2;

   returnValue.Size = 0;

   for (idx = 0; idx < NUMDIGITS; idx++) {
      counts[idx] = 0;

      for (idx2 = 0; idx2 < number.Size; idx2++)
         if (number.Digit[idx2].Symbol == allowedDigit[idx])
            counts[idx]++;
   }

   for (idx = 0; idx < NUMDIGITS; idx++) {
      while (counts[idx] >= nextDigit[idx]) {
         counts[idx] -= nextDigit[idx];
         counts[idx+1]++;
      }
   }

   for (idx = NUMDIGITS-1; idx >= 0; idx--) {
      while (counts[idx]) {
         RomanDigit digit;
         digit.Symbol = allowedDigit[idx];
         digit.Value = digitValue[idx];

         returnValue.Digit[returnValue.Size++] = digit;
         counts[idx]--;
      }
   }

   return returnValue;
}

RomanNumber rnConvertToSubtractiveNotation(RomanNumber number) {
   RomanNumber returnValue;
   int counts[NUMDIGITS], subtractive[NUMDIGITS], idx, idx2;

   returnValue.Size = 0;

   for (idx = 0; idx < NUMDIGITS; idx++) {
      counts[idx] = 0;
      subtractive[idx] = 0;

      for (idx2 = 0; idx2 < number.Size; idx2++)
         if (number.Digit[idx2].Symbol == allowedDigit[idx])
            counts[idx]++;
   }

   for (idx = 2; idx < NUMDIGITS; idx += 2) {
      if ((counts[idx-2] >= (nextDigit[idx-2]-1)) && (counts[idx-1] >= (nextDigit[idx-1]-1))) {
         subtractive[idx] = 1;
         counts[idx-2] -= (nextDigit[idx-2]-1);
         counts[idx-1] -= (nextDigit[idx-1]-1);
      }
   
      if (counts[idx-2] >= (nextDigit[idx-2]-1)) {
         subtractive[idx-1] = 1;
         counts[idx-2] -= (nextDigit[idx-2]-1);
      }
   }
   
   for (idx = (NUMDIGITS-1); idx >= 0; idx--) {
      RomanDigit digit = {allowedDigit[idx], digitValue[idx]};
      int modifierOffset = (idx % 2) == 0 ? 2 : 1;
      RomanDigit modifier = {allowedDigit[idx-modifierOffset], digitValue[idx-modifierOffset]};
   
      int repeat = counts[idx];
      while(repeat) {
         returnValue.Digit[returnValue.Size] = digit;
         returnValue.Size++;
         repeat--;
      }
   
      if (subtractive[idx] > 0) {
         returnValue.Digit[returnValue.Size] = modifier;
         returnValue.Digit[returnValue.Size+1] = digit;
         returnValue.Size += 2;
      }
   }

   return returnValue;
}

RomanNumber rnAdd(RomanNumber number1, RomanNumber number2) {
   return rnConvertToSubtractiveNotation(
             rnSimplifyDigits(
                rnSortDigits(
                   rnConcatinate(
                      rnRemoveSubtractiveNotation(number1),
                      rnRemoveSubtractiveNotation(number2)
                   )
                )
             )
          );
}
