#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAXBIN 8
#define MAXHEX 8
#define MAXOCT 8

/*
Author: Genaro Martínez S.
id: A01566055
date: 27/03/2020

use the routines to display several types of data from strings.
*/

unsigned int hexToInt(const char *hex)
  {
    unsigned int result = 0;
    while (*hex)
      {
        if (*hex > 47 && *hex < 58)
          result += (*hex - 48);
        else if (*hex > 64 && *hex < 71)
          result += (*hex - 55);
        else if (*hex > 96 && *hex < 103)
          result += (*hex - 87);
        else
        {
            printf("wrong character detected");
            break;
        }
        if (*++hex)
          result <<= 4;
      }
    return result;
  }

int stringBinToInt(const char *str)
{
    // initialize result.
    unsigned int result = 0;
    for (int i = strlen(str) - 1, j = 0; i >= 0; i--, j++)
    {
        char k = str[i] - '0'; // assuming ASCII
        // pointer operator to shift and multiply base.
        k <<= j;
        result += k;
    }
    return result;
}

long octalToDecimal(const char *octalString)
{
    long decimalNumber = 0, i = 0;
    char *eptr;
    long octalDecimal = strtol(octalString, &eptr, 10);
    while (octalDecimal != 0)
    {
        decimalNumber += (octalDecimal % 10) * pow(8, i);
        ++i;
        octalDecimal /= 10;
    }

    i = 1;

    return decimalNumber;
}

int divideByTwo(int *i) {
    int result = *i >> 1;
    return result;
}
int multiplyByTwo(int *i) {
    int result = *i << 1;
    return result;
}

int stringBinToInt(const char *str);
unsigned int hexToInt(const char *hex);
long octalToDecimal(const char *oct);

int main(int argc, char const *argv[])
{
    char hex[MAXBIN];
    char bin[MAXHEX];
    char oct[MAXOCT];

    int *divide;
    int *multiply;

    // 0101010101
    // FFFFF
    printf("bin: \n");
    scanf("%s", &bin);
    printf("hex: \n");
    scanf("%s", &hex);
    printf("oct: \n");
    scanf("%s", &oct);
    printf("digit to divide: \n");
    scanf("%d", &divide);
    printf("digit to multiply\n");
    scanf("%d", &multiply);

    printf("Binary value in decimal = %d \n", stringBinToInt(bin));
    printf("\n");
    printf("Hexadecimal value in decimal = %lu\n", hexToInt(hex));
    printf("\n");
    printf("Octaldecimal value in decimal = %ld\n", octalToDecimal(oct));
    printf("\n");
    printf("Decimal value divided = %d\n", divideByTwo(&divide));
    printf("\n");
    printf("Decimal value multiplied = %d\n", multiplyByTwo(&multiply));
    printf("\n");
    return 0;
}
