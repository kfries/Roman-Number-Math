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

/* Number Instantiation and Validation Functions */
RomanDigit rdEncode(char);
RomanNumber rnEncode(char *);

/* Core Mathmatical Functions */
RomanNumber rnAdd(RomanNumber, RomanNumber);
RomanNumber rnSubtract(RomanNumber, RomanNumber);

/* Debugging and Validation Helper Functions */
char *rnPrint(RomanNumber);
uint32_t rnValue(RomanNumber);

/* Algorithm Implementation Functions */
RomanNumber rnSortDigits(RomanNumber);
RomanNumber rnConcatinate(RomanNumber, RomanNumber);
RomanNumber rnRemoveSubtractiveNotation(RomanNumber);
RomanNumber rnSimplifyDigits(RomanNumber);
RomanNumber rnConvertToSubtractiveNotation(RomanNumber);
RomanNumber rnExpandValue(RomanNumber, RomanNumber);
void rnRemoveCommonDigits(RomanNumber *, RomanNumber *);

#endif
