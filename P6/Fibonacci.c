/*
Author: Genaro Martínez S.
id: A01566055
date: 22/02/2020

print a fibonacci and calculate factorial digit
using recursion.
*/

#include <stdio.h>

int printFibonacci(int n)
{
    static int n1 = 0, n2 = 1, n3, factorial = 1;
    if (n > 0)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d ", n3);
        printFibonacci(n - 1);
        factorial = factorial * n;
    }

    return factorial;
}

int main(int argc, char const *argv[])
{

    int n;
    printf("Enter the N number of elements: ");
    scanf("%d", &n);
    int count = printFibonacci(n);
    printf("\n");
    printf("The N numbers in a fibonacci sequence are: %d \n", n);
    printf("The factorial of %d is: %d\n", n, count);
    return 0;
}
