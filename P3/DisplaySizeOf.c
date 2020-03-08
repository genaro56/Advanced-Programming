/*
Author: Genaro Martínez S.
id: A01566055
date: 20/02/2020

display the size of types and use the function sizeof().
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int intType;
    float floatType;
    double doubleType;
    char charType;

    printf("int type\n");
    scanf("%d", &intType);

    printf("float type\n");
    scanf("%f", &floatType);

    printf("double type\n");
    scanf("%lf", &doubleType);

    printf("char type\n");
    scanf(" %c", &charType);

    // sizeof evaluates the size of a variable
    printf("Your integer <%d> storage size is => %ld bytes\n", intType, sizeof(intType));
    printf("Your float <%f> storage size is => %ld bytes\n", floatType, sizeof(floatType));
    printf("Your double <%f> storage size is => %ld bytes\n", doubleType, sizeof(doubleType));
    printf("Your char <%c> storage size is => %ld byte\n", charType, sizeof(charType));

    return 0;
}
