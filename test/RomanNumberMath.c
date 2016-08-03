#include <stdlib.h>
#include <check.h>

#include "RomanNumberMath.h"

/*****************************************************************************
 * ROMAN DIGITS
 * 
 * Set of test to insure that the most fundimental element of the RomanNumber
 * library is getting created correctly
 *
 ****************************************************************************/

/***************** A Blank/NULL should generate a failure *******************/
START_TEST(failed_to_give_a_char_to_encode) {
   RomanDigit digit = rdEncode(' ');

   ck_assert(digit.Symbol == ' ');
   ck_assert(digit.Value == 0);
} END_TEST

/************ Create a Roman Digit from letter A -- Should Fail *************/
START_TEST(create_roman_digit_from_letter_A) {
   RomanDigit digit = rdEncode('A');

   ck_assert(digit.Symbol == ' ');
   ck_assert(digit.Value == 0);
} END_TEST

START_TEST(create_roman_digit_from_letter_a) {
   RomanDigit digit = rdEncode('a');

   ck_assert(digit.Symbol == ' ');
   ck_assert(digit.Value == 0);
} END_TEST

/******************** Create a Roman Digit from letter I ********************/
START_TEST(create_roman_digit_from_letter_I) {
   RomanDigit digit = rdEncode('I');

   ck_assert(digit.Symbol == 'I');
   ck_assert(digit.Value == 1);
} END_TEST

START_TEST(create_roman_digit_from_letter_i) {
   RomanDigit digit = rdEncode('i');

   ck_assert(digit.Symbol == 'I');
   ck_assert(digit.Value == 1);
} END_TEST

/******************** Create a Roman Digit from letter V ********************/
START_TEST(create_roman_digit_from_letter_V) {
   RomanDigit digit = rdEncode('V');

   ck_assert(digit.Symbol == 'V');
   ck_assert(digit.Value == 5);
} END_TEST

START_TEST(create_roman_digit_from_letter_v) {
   RomanDigit digit = rdEncode('v');

   ck_assert(digit.Symbol == 'V');
   ck_assert(digit.Value == 5);
} END_TEST

/******************** Create a Roman Digit from letter X ********************/
START_TEST(create_roman_digit_from_letter_X) {
   RomanDigit digit = rdEncode('X');

   ck_assert(digit.Symbol == 'X');
   ck_assert(digit.Value == 10);
} END_TEST

START_TEST(create_roman_digit_from_letter_x) {
   RomanDigit digit = rdEncode('x');

   ck_assert(digit.Symbol == 'X');
   ck_assert(digit.Value == 10);
} END_TEST

/******************** Create a Roman Digit from letter L ********************/
START_TEST(create_roman_digit_from_letter_L) {
   RomanDigit digit = rdEncode('L');

   ck_assert(digit.Symbol == 'L');
   ck_assert(digit.Value == 50);
} END_TEST

START_TEST(create_roman_digit_from_letter_l) {
   RomanDigit digit = rdEncode('l');

   ck_assert(digit.Symbol == 'L');
   ck_assert(digit.Value == 50);
} END_TEST

/******************** Create a Roman Digit from letter C ********************/
START_TEST(create_roman_digit_from_letter_C) {
   RomanDigit digit = rdEncode('C');

   ck_assert(digit.Symbol == 'C');
   ck_assert(digit.Value == 100);
} END_TEST

START_TEST(create_roman_digit_from_letter_c) {
   RomanDigit digit = rdEncode('c');

   ck_assert(digit.Symbol == 'C');
   ck_assert(digit.Value == 100);
} END_TEST

/******************** Create a Roman Digit from letter D ********************/
START_TEST(create_roman_digit_from_letter_D) {
   RomanDigit digit = rdEncode('D');

   ck_assert(digit.Symbol == 'D');
   ck_assert(digit.Value == 500);
} END_TEST

START_TEST(create_roman_digit_from_letter_d) {
   RomanDigit digit = rdEncode('d');

   ck_assert(digit.Symbol == 'D');
   ck_assert(digit.Value == 500);
} END_TEST

/******************** Create a Roman Digit from letter M ********************/
START_TEST(create_roman_digit_from_letter_M) {
   RomanDigit digit = rdEncode('M');

   ck_assert(digit.Symbol == 'M');
   ck_assert(digit.Value == 1000);
} END_TEST

START_TEST(create_roman_digit_from_letter_m) {
   RomanDigit digit = rdEncode('m');

   ck_assert(digit.Symbol == 'M');
   ck_assert(digit.Value == 1000);
} END_TEST


/*****************************************************************************
 * ROMAN NUMBERS
 * 
 * These tests use the Roman Digits internally to create a full Romann Number
 *
 ****************************************************************************/

/******************* Create a Roman Number from string I ********************/
START_TEST(create_roman_number_from_I) {
   RomanNumber number = rnEncode("I");

   ck_assert(number.Size == 1);
   ck_assert(number.Digit[0].Symbol == 'I');
} END_TEST

/****************** Create a Roman Number from string XX ********************/
START_TEST(create_roman_number_from_XX) {
   RomanNumber number = rnEncode("XX");

   ck_assert(number.Size == 2);
   ck_assert(number.Digit[0].Symbol == 'X');
   ck_assert(number.Digit[1].Symbol == 'X');
} END_TEST

/****************** Create a Roman Number from string LIC *******************/
START_TEST(create_roman_number_from_LIC) {
   RomanNumber number = rnEncode("LIC");

   ck_assert(number.Size == 3);
   ck_assert(number.Digit[0].Symbol == 'L');
   ck_assert(number.Digit[1].Symbol == 'I');
   ck_assert(number.Digit[2].Symbol == 'C');
} END_TEST

/***************** Create a Roman Number from string XCIX *******************/
START_TEST(create_roman_number_from_XCIX) {
   RomanNumber number = rnEncode("XCIX");

   ck_assert(number.Size == 4);
   ck_assert(number.Digit[0].Symbol == 'X');
   ck_assert(number.Digit[1].Symbol == 'C');
   ck_assert(number.Digit[2].Symbol == 'I');
   ck_assert(number.Digit[3].Symbol == 'X');
} END_TEST

/***************** Create a Roman Number from string CXCIX ******************/
START_TEST(create_roman_number_from_CXCIX) {
   RomanNumber number = rnEncode("CXCIX");

   ck_assert(number.Size == 5);
   ck_assert(number.Digit[0].Symbol == 'C');
   ck_assert(number.Digit[1].Symbol == 'X');
   ck_assert(number.Digit[2].Symbol == 'C');
   ck_assert(number.Digit[3].Symbol == 'I');
   ck_assert(number.Digit[4].Symbol == 'X');
} END_TEST

Suite * roman_number_math_suite(void) {
   Suite *s;
   TCase *tc_digits, *tc_numbers;

   s = suite_create("RomanNumberMath");

   /* Testing Creating of Roman Digits */
   tc_digits = tcase_create("RomanDigits");

   tcase_add_test(tc_digits, failed_to_give_a_char_to_encode);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_A);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_a);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_I);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_i);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_V);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_v);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_X);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_x);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_L);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_l);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_C);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_c);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_D);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_d);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_M);
   tcase_add_test(tc_digits, create_roman_digit_from_letter_m);

   suite_add_tcase(s, tc_digits);

   tc_numbers = tcase_create("RomanNumbers");

   tcase_add_test(tc_numbers, create_roman_number_from_I);
   tcase_add_test(tc_numbers, create_roman_number_from_XX);
   tcase_add_test(tc_numbers, create_roman_number_from_LIC);
   tcase_add_test(tc_numbers, create_roman_number_from_XCIX);
   tcase_add_test(tc_numbers, create_roman_number_from_CXCIX);

   suite_add_tcase(s, tc_numbers);

   return s;
}

int main(int argc, char *argv[]) {
   int number_failed;
   Suite *s;
   SRunner *sr;

   s = roman_number_math_suite();
   sr = srunner_create(s);

   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
