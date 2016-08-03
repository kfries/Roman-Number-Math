#ifndef __ROMAN_H_
#define __ROMAN_H_

typedef struct {
   char Symbol;
   int Value;
} RomanDigit;

typedef struct {
   int Size;
   RomanDigit Digit[100];
} RomanNumber;

RomanDigit rdEncode(char);
RomanNumber rnEncode(char *);
#endif
