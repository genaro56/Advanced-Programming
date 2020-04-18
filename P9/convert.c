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


int hexToInt(const char *s, unsigned long *result)
{
    if ((*s == '0') && (s[1] == 'x' || s[1] == 'X')) {
        s += 2;
    }
    for (*result = 0; *s; ++s) {
        int n = 0;
        if (*s >= 'a' && *s <= 'f') {
            n = *s - 'a' + 10;
        } else if (*s >= 'A' && *s <= 'F') {
            n = *s - 'A' + 10;
        } else if (*s >= '0' && *s <= '9') {
            n = *s - '0';
        }
        else if (*result > (ULONG_MAX/16)) {
            errno = ERANGE;
            return -1;
        } else {
            errno = EINVAL;
            return -1;
        }
        *result *= 16;
        *result += (unsigned long) n;
    }
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

int hexToInt(const char *s, unsigned long *res);
int stringBinToInt(const char *str);

int main(int argc, char const *argv[])
{
    unsigned long result;
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
    a = atof(dbl);

    printf("Binary value in int = %d \n", stringBinToInt(bin));
    printf("\n");
    if (0 > hexToInt(&hex[1], &result))
        return EXIT_FAILURE;
    else
        printf("Hexadecimal value in integer = %lu\n", result);
        printf("\n");

	printf ("double point number in dbl = %f\n" , a);
    return 0;
}
