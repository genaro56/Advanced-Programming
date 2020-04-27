#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#define MAXBIN 32
#define MAXHEX 8
#define MAXDBL 100

/*
Author: Genaro Martínez S.
id: A01566055
date: 13/03/2020

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
        // pointer operator to assign new position.
        k <<= j;
        result += k;
    }
    return result;
}
double pointerToDouble(const char *str) {
    double a = atof(str);
    return a;
}

unsigned int hexToInt(const char *hex);
int stringBinToInt(const char *str);
int main(int argc, char const *argv[])
{
    char hex[MAXBIN];
    char bin[MAXHEX];
    char dbl[MAXDBL];
    double a, b;

    // 0101010101
    // FFFFF
    printf("bin: \n");
    scanf("%s", &bin);
    printf("hex: \n");
    scanf("%s", &hex);
    printf("dbl: \n");
    scanf("%s", &dbl);

    printf("Binary value in int = %d \n", stringBinToInt(bin));
    printf("\n");
    printf("Hexadecimal value in decimal = %lu\n", hexToInt(hex));
    printf("\n");

	printf ("double point number in dbl = %f\n" ,pointerToDouble(dbl));
    return 0;
}
