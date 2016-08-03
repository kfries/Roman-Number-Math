#ifndef __ROMAN_H_
#define __ROMAN_H_

typedef struct {
   char Symbol;
   int Value;
} RomanDigit;

RomanDigit rdEncode(char);
#endif
