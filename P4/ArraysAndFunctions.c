/*
Author: Genaro Martínez S.
id: A01566055
date: 20/02/2020

display the matrix mutliplication, addition and substraction.
*/

#include <stdio.h>

void input_data(int (*data)[2], int size)
{
    int value = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &value);
            data[i][j] = value;
            /* code */
        }
    }
}

void print_data(int (*data)[2])
{
    int value = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", data[i][j]);
            /* code */
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    int arrA[2][2];
    int arrB[2][2];

    int matMultiply[2][2],
        matSubstract[2][2],
        matSum[2][2];

    int c, sum = 0;

    input_data(arrA, 2);
    input_data(arrB, 2);

    for (int c = 0; c < 2; c++)
    {
        for (int d = 0; d < 2; d++)
        {
            matSum[c][d] = arrA[c][d] + arrB[c][d];
        }
    }

    sum = 0;

    for (int c = 0; c < 2; c++)
    {
        for (int d = 0; d < 2; d++)
        {
            matSubstract[c][d] = arrA[c][d] - arrB[c][d];
        }
    }

    sum = 0;

    for (int c = 0; c < 2; c++)
    {
        for (int d = 0; d < 2; d++)
        {
            for (int k = 0; k < 2; k++)
            {
                sum = sum + arrA[c][k] * arrB[k][d];
            }

            matMultiply[c][d] = sum;
            sum = 0;
        }
    }
    printf("Matrix A\n");
    print_data(arrA);
    printf("Matrix B\n");
    print_data(arrB);


    printf("Sum: \n");
    print_data(matSum);
    printf("Substract: \n");
    print_data(matSubstract);
    printf("Multiplication: \n");
    print_data(matMultiply);
    return 0;
}
