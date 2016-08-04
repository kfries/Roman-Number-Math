#include <stdint.h>
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

/*****************************************************************************
 * DISPLAY FUNCTIONS
 * 
 * These tests allow for printing of the Number, or Obtaining its value
 *
 ****************************************************************************/

/********* A Roman Number of V should display as V and have value 5 *********/
START_TEST(display_properties_for_roman_number_V) {
   RomanNumber number = rnEncode("I");

   ck_assert_str_eq(rnPrint(number), "I");
   ck_assert_int_eq(rnValue(number), 1);
} END_TEST

/******** A Roman Number of XX should display as V and have value 20 ********/
START_TEST(display_properties_for_roman_number_XX) {
   RomanNumber number = rnEncode("XX");

   ck_assert_str_eq(rnPrint(number), "XX");
   ck_assert_int_eq(rnValue(number), 20);
} END_TEST

/******* A Roman Number of LIX should display as V and have value 59 ********/
START_TEST(display_properties_for_roman_number_LIX) {
   RomanNumber number = rnEncode("LIX");

   ck_assert_str_eq(rnPrint(number), "LIX");
   ck_assert_int_eq(rnValue(number), 59);
} END_TEST

/******* A Roman Number of XCIX should display as V and have value 99 *******/
START_TEST(display_properties_for_roman_number_XCIX) {
   RomanNumber number = rnEncode("XCIX");

   ck_assert_str_eq(rnPrint(number), "XCIX");
   ck_assert_int_eq(rnValue(number), 99);
} END_TEST

/****** A Roman Number of CXCIX should display as V and have value 199 ******/
START_TEST(display_properties_for_roman_number_CXCIX) {
   RomanNumber number = rnEncode("CXCIX");

   ck_assert_str_eq(rnPrint(number), "CXCIX");
   ck_assert_int_eq(rnValue(number), 199);
} END_TEST

/*****************************************************************************
 * LIBRARY FUNCTIONS
 * 
 * When researching the algorithmm to do math with Roman Numbers, it game me
 * hints to take the number and not use subtractive notation, having to sort
 * the symbols, etc.
 *
 ****************************************************************************/

/***************** Sort a simple one character number value *****************/
START_TEST(sort_a_single_digit_value) {
   RomanNumber number = rnEncode("V");
   ck_assert_str_eq(rnPrint(rnSortDigits(number)), "V");
} END_TEST

/******************** Sort a simple two character number ********************/
START_TEST(sort_a_two_digit_value) {
   RomanNumber number = rnEncode("XX");
   ck_assert_str_eq(rnPrint(rnSortDigits(number)), "XX");
} END_TEST

/********* Sort a three character value with some values out of oder ********/
START_TEST(sort_a_number_with_digits_out_of_order) {
   RomanNumber number = rnEncode("LIX");
   ck_assert_str_eq(rnPrint(rnSortDigits(number)), "LXI");
} END_TEST

/******** Sort a four digit number with multiple digits out of order ********/
START_TEST(sort_a_number_with_multiple_digits_out_of_order) {
   RomanNumber number = rnEncode("XCIX");
   ck_assert_str_eq(rnPrint(rnSortDigits(number)), "CXXI");
} END_TEST

/******** Sort a five digit number with multiple digits out of order ********/
START_TEST(sort_a_number_with_multiple_digits_out_of_order_after_first) {
   RomanNumber number = rnEncode("CXCIX");
   ck_assert_str_eq(rnPrint(rnSortDigits(number)), "CCXXI");
} END_TEST

/********** Concatinate Two Single Digit Values into a Single Value *********/
START_TEST(concatinate_two_single_digit_numbers) {
   RomanNumber number1 = rnEncode("X");
   RomanNumber number2 = rnEncode("V");
   ck_assert_str_eq(rnPrint(rnConcatinate(number1, number2)), "XV");
} END_TEST

/************** Sort two Multi-Digit Values into a Single Value *************/
START_TEST(concatinate_two_multidigit_values) {
   RomanNumber number1 = rnEncode("XV");
   RomanNumber number2 = rnEncode("VIII");
   ck_assert_str_eq(rnPrint(rnConcatinate(number1, number2)), "XVVIII");
} END_TEST

/************ Remove Subtractive Notation from Single Digit Value ***********/
START_TEST(remove_subtractive_notation_single_digit) {
   RomanNumber number = rnEncode("V");
   ck_assert_str_eq(rnPrint(rnRemoveSubtractiveNotation(number)), "V");
} END_TEST

/************* Remove Subtractive Notation from MultiDigit Value ************/
START_TEST(remove_subtractive_notation_multi_digit) {
   RomanNumber number = rnEncode("XX");
   ck_assert_str_eq(rnPrint(rnRemoveSubtractiveNotation(number)), "XX");
} END_TEST

/***** Remove Subtractive Notation from MultiDigit Value, Single Change *****/
START_TEST(remove_subtractive_notation_multi_digit_single_change) {
   RomanNumber number = rnEncode("LIX");
   ck_assert_str_eq(rnPrint(rnRemoveSubtractiveNotation(number)), "LVIIII");
} END_TEST

/**** Remove Subtractive Notation from MultiDigit Value, Multiple Changes ***/
START_TEST(remove_subtractive_notation_multi_digit_multiple_changes) {
   RomanNumber number = rnEncode("XCIX");
   ck_assert_str_eq(rnPrint(rnRemoveSubtractiveNotation(number)), "LXXXXVIIII");
} END_TEST

/****** Remove Subtractive Notation from MultiDigit Value, Mixed Values *****/
START_TEST(remove_subtractive_notation_mixed_values) {
   RomanNumber number = rnEncode("CXCIX");
   ck_assert_str_eq(rnPrint(rnRemoveSubtractiveNotation(number)), "CLXXXXVIIII");
} END_TEST

/******** Simply Roman Number with only One digit (return value only) *******/
START_TEST(simplify_value_single_digit) {
   RomanNumber number = rnEncode("I");
   ck_assert_str_eq(rnPrint(rnSimplifyDigits(number)), "I");
} END_TEST

/************** Simplify value with five ones into a single five ************/
START_TEST(simplify_value_five_ones_equals_five) {
   RomanNumber number = rnEncode("IIIII");
   ck_assert_str_eq(rnPrint(rnSimplifyDigits(number)), "V");
} END_TEST

/************* Simplify a value with two fives into a single ten ************/
START_TEST(simplify_value_two_fives_equals_ten) {
   RomanNumber number = rnEncode("VV");
   ck_assert_str_eq(rnPrint(rnSimplifyDigits(number)), "X");
} END_TEST

/************ Simplify a value with five tens into a single fifty ***********/
START_TEST(simplify_value_five_tens_equals_fifty) {
   RomanNumber number = rnEncode("XXXXX");
   ck_assert_str_eq(rnPrint(rnSimplifyDigits(number)), "L");
} END_TEST

/********** Simplify a single value with two fifties into a hundred *********/
START_TEST(simplify_value_two_fifty_equals_one_hundred) {
   RomanNumber number = rnEncode("LL");
   ck_assert_str_eq(rnPrint(rnSimplifyDigits(number)), "C");
} END_TEST

/**** Simplify a value with five one hundreds into a single five hundred ****/
START_TEST(simplify_value_five_one_hundred_equals_five_hundred) {
   RomanNumber number = rnEncode("CCCCC");
   ck_assert_str_eq(rnPrint(rnSimplifyDigits(number)), "D");
} END_TEST

/**** Simplify a value with two five hundreds into a single one thousand ****/
START_TEST(simplify_value_two_five_hundred_equals_one_thousand) {
   RomanNumber number = rnEncode("DD");
   ck_assert_str_eq(rnPrint(rnSimplifyDigits(number)), "M");
} END_TEST

/******** Combine several elements above into a single simplification *******/
START_TEST(simplify_value_complex_value) {
   RomanNumber number = rnEncode("MMDDLLVII");
   ck_assert_str_eq(rnPrint(rnSimplifyDigits(number)), "MMMCVII");
} END_TEST

/********** Converting a single digit should just return that digit *********/
START_TEST(convert_to_subtractive_notation_single_digit) {
   RomanNumber number = rnEncode("I");
   ck_assert_str_eq(rnPrint(rnConvertToSubtractiveNotation(number)), "I");
} END_TEST

/*********** Convert a value with a five and four ones into a nine **********/
START_TEST(convert_to_subtractive_notation_nine) {
   RomanNumber number = rnEncode("VIIII");
   ck_assert_str_eq(rnPrint(rnConvertToSubtractiveNotation(number)), "IX");
} END_TEST

/**************** Convert a value with four ones into a four ****************/
START_TEST(convert_to_subtractive_notation_four) {
   RomanNumber number = rnEncode("XIIII");
   ck_assert_str_eq(rnPrint(rnConvertToSubtractiveNotation(number)), "XIV");
} END_TEST

/********* Convert a value with a fifty and four tens into a ninety *********/
START_TEST(convert_to_subtractive_notation_ninety) {
   RomanNumber number = rnEncode("CLXXXXVII");
   ck_assert_str_eq(rnPrint(rnConvertToSubtractiveNotation(number)), "CXCVII");
} END_TEST

/*************** Convert a value with four tens into a fourty ***************/
START_TEST(convert_to_subtractive_notation_fourty) {
   RomanNumber number = rnEncode("XXXXXIII");
   ck_assert_str_eq(rnPrint(rnConvertToSubtractiveNotation(number)), "XLXIII");
} END_TEST

/* Convert a value with a five-hundred and four one-hundreds into four-hund */
START_TEST(convert_to_subtractive_notation_nine_hundred) {
   RomanNumber number = rnEncode("DCCCCXII");
   ck_assert_str_eq(rnPrint(rnConvertToSubtractiveNotation(number)), "CMXII");
} END_TEST

/************** Convert four one-hundreds into a four-houndred **************/
START_TEST(convert_to_subtractive_notation_four_hundred) {
   RomanNumber number = rnEncode("CCCCLXII");
   ck_assert_str_eq(rnPrint(rnConvertToSubtractiveNotation(number)), "CDLXII");
} END_TEST

/****************** Convert using multiple rules from above *****************/
START_TEST(convert_to_subtractive_notation_complex_value) {
   RomanNumber number = rnEncode("DCCCCLXXXXVIIII");
   ck_assert_str_eq(rnPrint(rnConvertToSubtractiveNotation(number)), "CMXCIX");
} END_TEST

/**************** Remove Common Digits: two identical numbers ***************/
START_TEST(remove_common_digits_from_two_identical_numbers) {
   RomanNumber number1 = rnEncode("I");
   RomanNumber number2 = rnEncode("I");

   rnRemoveCommonDigits(&number1, &number2);
   ck_assert_str_eq(rnPrint(number1), "");
   ck_assert_str_eq(rnPrint(number2), "");
} END_TEST

/******* Remove Common Digits: all of seconds digits included in first ******/
START_TEST(remove_common_digits_where_second_included_in_first) {
   RomanNumber number1 = rnEncode("III");
   RomanNumber number2 = rnEncode("II");

   rnRemoveCommonDigits(&number1, &number2);
   ck_assert_str_eq(rnPrint(number1), "I");
   ck_assert_str_eq(rnPrint(number2), "");
} END_TEST

/*** Remove Common Digits: second digits only parcially included in first ***/
START_TEST(remove_common_digits_where_second_partly_in_first) {
   RomanNumber number1 = rnEncode("VI");
   RomanNumber number2 = rnEncode("II");

   rnRemoveCommonDigits(&number1, &number2);
   ck_assert_str_eq(rnPrint(number1), "V");
   ck_assert_str_eq(rnPrint(number2), "I");
} END_TEST

/****** Remove Common Digits: none of seconds digits included in first ******/
START_TEST(remove_common_digits_where_no_digits_in_common) {
   RomanNumber number1 = rnEncode("LX");
   RomanNumber number2 = rnEncode("VI");

   rnRemoveCommonDigits(&number1, &number2);
   ck_assert_str_eq(rnPrint(number1), "LX");
   ck_assert_str_eq(rnPrint(number2), "VI");
} END_TEST


/*****************************************************************************
 * Main Function Calls (Core)
 * 
 * This is the actual Add and Subtract Calls
 *
 ****************************************************************************/

/************************** Add I + I = II (1+1=2) **************************/
START_TEST(one_plus_one_equals_two) {
   RomanNumber number1 = rnEncode("I");
   RomanNumber number2 = rnEncode("I");
   ck_assert_str_eq(rnPrint(rnAdd(number1, number2)), "I");
} END_TEST

/************************* Add II + II = IV (2+2+4) *************************/
START_TEST(two_plus_two_equals_four) {
   RomanNumber number1 = rnEncode("II");
   RomanNumber number2 = rnEncode("II");
   ck_assert_str_eq(rnPrint(rnAdd(number1, number2)), "IV");
} END_TEST

/********************** Add XLVI + LIV = C (46+54=100) **********************/
START_TEST(add_two_complex_numbers) {
   RomanNumber number1 = rnEncode("XLVI");
   RomanNumber number2 = rnEncode("LIV");
   ck_assert_str_eq(rnPrint(rnAdd(number1, number2)), "C");
} END_TEST

/****************************************************************************/
Suite * roman_number_math_suite(void) {
   Suite *s;
   TCase *tc_digits, *tc_numbers, *tc_library, *tc_core;

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

   /* Testing Creating of Roman Numbers */
   tc_numbers = tcase_create("RomanNumbers");

   tcase_add_test(tc_numbers, create_roman_number_from_I);
   tcase_add_test(tc_numbers, create_roman_number_from_XX);
   tcase_add_test(tc_numbers, create_roman_number_from_LIC);
   tcase_add_test(tc_numbers, create_roman_number_from_XCIX);
   tcase_add_test(tc_numbers, create_roman_number_from_CXCIX);

   tcase_add_test(tc_numbers, display_properties_for_roman_number_V);
   tcase_add_test(tc_numbers, display_properties_for_roman_number_XX);
   tcase_add_test(tc_numbers, display_properties_for_roman_number_LIX);
   tcase_add_test(tc_numbers, display_properties_for_roman_number_XCIX);
   tcase_add_test(tc_numbers, display_properties_for_roman_number_CXCIX);

   suite_add_tcase(s, tc_numbers);

   /* Testing Library Functions (algoritm steps) */
   tc_library = tcase_create("Library");
   tcase_add_test(tc_library, sort_a_single_digit_value);
   tcase_add_test(tc_library, sort_a_two_digit_value);
   tcase_add_test(tc_library, sort_a_number_with_digits_out_of_order);
   tcase_add_test(tc_library, sort_a_number_with_multiple_digits_out_of_order);
   tcase_add_test(tc_library, sort_a_number_with_multiple_digits_out_of_order_after_first);

   tcase_add_test(tc_library, concatinate_two_single_digit_numbers);
   tcase_add_test(tc_library, concatinate_two_multidigit_values);

   tcase_add_test(tc_library, remove_subtractive_notation_single_digit);
   tcase_add_test(tc_library, remove_subtractive_notation_multi_digit);
   tcase_add_test(tc_library, remove_subtractive_notation_multi_digit_single_change);
   tcase_add_test(tc_library, remove_subtractive_notation_multi_digit_multiple_changes);
   tcase_add_test(tc_library, remove_subtractive_notation_mixed_values);

   tcase_add_test(tc_library, simplify_value_single_digit);
   tcase_add_test(tc_library, simplify_value_five_ones_equals_five);
   tcase_add_test(tc_library, simplify_value_two_fives_equals_ten);
   tcase_add_test(tc_library, simplify_value_five_tens_equals_fifty);
   tcase_add_test(tc_library, simplify_value_two_fifty_equals_one_hundred);
   tcase_add_test(tc_library, simplify_value_five_one_hundred_equals_five_hundred);
   tcase_add_test(tc_library, simplify_value_two_five_hundred_equals_one_thousand);
   tcase_add_test(tc_library, simplify_value_complex_value);

   tcase_add_test(tc_library, convert_to_subtractive_notation_single_digit);
   tcase_add_test(tc_library, convert_to_subtractive_notation_nine);
   tcase_add_test(tc_library, convert_to_subtractive_notation_four);
   tcase_add_test(tc_library, convert_to_subtractive_notation_ninety);
   tcase_add_test(tc_library, convert_to_subtractive_notation_fourty);
   tcase_add_test(tc_library, convert_to_subtractive_notation_nine_hundred);
   tcase_add_test(tc_library, convert_to_subtractive_notation_four_hundred);
   tcase_add_test(tc_library, convert_to_subtractive_notation_complex_value);

   tcase_add_test(tc_library, remove_common_digits_from_two_identical_numbers);
   tcase_add_test(tc_library, remove_common_digits_where_second_included_in_first);
   tcase_add_test(tc_library, remove_common_digits_where_second_partly_in_first);
   tcase_add_test(tc_library, remove_common_digits_where_no_digits_in_common);

   suite_add_tcase(s, tc_library);

   /* Testing Creating of Roman Digits Mathmatical Functions*/
   tc_core = tcase_create("Core");

   tcase_add_test(tc_core, one_plus_one_equals_two);
   tcase_add_test(tc_core, two_plus_two_equals_four);
   tcase_add_test(tc_core, add_two_complex_numbers);

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
