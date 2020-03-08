/**
 * Author: Genaro Martínez S.
 * id: A01566055
 * 
 * program that generates 10 random numbers. 
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int usePowerResidue(unsigned int topNumber, unsigned int lowNumber)
{
    /* Using a memory address. */
    static unsigned int rand = 0xACE1U; 
    rand += 0x3AD;
    rand%=topNumber;
    while (rand < lowNumber) 
    {
        /* code */
    rand = rand % (topNumber + 1 - lowNumber) + lowNumber;
    }
    return rand;
}

int main()
{
    int topNumber, lowNumber;
    printf("provide the top number\n");
    scanf("%d", &topNumber);
    printf("provide the lower number\n");
    scanf("%d", &lowNumber);
    
    if (topNumber < lowNumber)
    {
        printf("the top number should be bigger than the lower number\n");
    }
    else if (lowNumber > topNumber)
    {
        printf("the lower number should be smaller than the top number\n");
    } else {
        for (int i = 0; i < 10; i++) {
            printf("random number #%d: %d\n", i+1, usePowerResidue(topNumber, lowNumber));
        }
        printf("\n");
    }
    return 0;
}
