/*
Author: Genaro Martínez S.
id: A01566055
date: 22/02/2020

use pointers to manipulate data stored in an array of characters.
*/

#include <stdio.h>
#include <string.h>
int main()
{

    char address[] = "eioua";
    char c, *ptr;
    ptr = address;
    for (c = 0; c < 5; c++)
    {
        if(*ptr == 'a') {
            *ptr = 4;
        } else if (*ptr == 'e'){   
            *ptr = 3;
        } else if(*ptr == 'i') {
            *ptr = 1;
        } else if(*ptr == 'o') {
            *ptr = 0;
        } else if(*ptr == 'u') {
            *ptr = 2;
        }
        // change location of vowel.
        if(*ptr != '\0') {
            printf("ptr[%d] => %s\n", c, ptr);
            printf("value[%c] => %d\n", c, *ptr);
            ptr++;
        }
    }
    printf("\n");
    printf("%s", address);
    return 0;
}
