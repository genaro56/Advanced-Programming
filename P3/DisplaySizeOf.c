/*
Author: Genaro Martínez S.
id: A01566055
date: 13/03/2020

display the size of union types and use the function sizeof().
*/

#include <stdio.h>

// initialize data union to store data types.
union Data {
   int i;
   double d;
   char str[100];
} data;  

int main(int argc, char const *argv[])
{
    char str[100];
    printf("int type\n");
    scanf("%d", &data.i);

    printf("double type\n");
    scanf("%lf", &data.d);

    printf("string type:\n");
    scanf("%s", &str);
    strcpy(data.str, str);
    // sizeof evaluates the size of a variable
    printf("Your integer <%d> storage size is => %ld bytes\n", data.i, sizeof(data.i));
    printf("Your double <%f> storage size is => %ld bytes\n", data.d, sizeof(data.d));
    printf("Your string <%s> storage size is => %ld byte\n", data.str, sizeof(data.str));
    printf("Your data union storage size => %ld bytes\n", sizeof(data));

    return 0;
}
