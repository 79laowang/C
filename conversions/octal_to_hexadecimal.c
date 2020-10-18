/**
 * @brief Octal to hexadecimal conversion by scanning user input
 * @details
 * The octalToHexadecimal function take the octal number as long
 * return a string hexadecimal value after conversion
 * @author [Rachit Bhalla](https://github.com/rachitbhalla)
 */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Convert octal number to decimal number
 * @param octalValue is the octal number that needs to be converted
 * @returns a decimal number after conversion
 */
long octalToDecimal(long octalValue){
    long decimalValue = 0;
    int i = 0;
    while (octalValue) {
        // Extracts right-most digit, multiplies it with 8^i, and increment i by 1
        decimalValue += (long)(octalValue % 10) * pow(8, i++);
        // Shift right in base 10
        octalValue /= 10;
    }
    return decimalValue;
}

/**
 * @brief Convert octal number to hexadecimal number
 * @param octalValue is the octal number that needs to be converted
 * @returns a hexadecimal value as a string after conversion
 */
char *octalToHexadecimal(long octalValue){
    char *hexadecimalValue = malloc(256 * sizeof(char));
    sprintf(hexadecimalValue, "%lX", octalToDecimal(octalValue));
    return hexadecimalValue;
}

/**
 * @brief Test function
 * @returns void
 */
static void test() {
    /* test that hexadecimal value of octal number 213 is 8B */
    assert(strcmp(octalToHexadecimal(213), "8B") == 0);

    /* test that hexadecimal value of octal number 174 is 7C */
    assert(strcmp(octalToHexadecimal(174), "7C") == 0);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    //execute the tests
    test();

    int octalValue;
    printf("Enter an octal number: ");
    scanf("%d", &octalValue);

    //Calling the function octalToHexadecimal
    char *hexadecimalValue = octalToHexadecimal(octalValue);
    printf("\nEquivalent hexadecimal number is: %s", hexadecimalValue);
    free(hexadecimalValue);
    return 0;
}
