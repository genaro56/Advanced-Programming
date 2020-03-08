/*
Author: Genaro Martínez S.
id: A01566055
date: 20/02/2020

insert data into a struct.
*/

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <ctype.h>

typedef struct
{
    char *name;
    char *lName;
    int age;
    char gender;
    char *(missionId);
} MISSION;

int main(int argc, char const *argv[])
{
    char name[20];
    char lName[20];
    char missionId[20];
    int age, intErrors = 0, charErrors = 0, stringSize = 0;
    char gender;
    MISSION mission;

    printf("name: ");
    scanf("%s", &name);
    printf("last name: ");
    scanf("%s", &lName);
    printf("age (integer): ");
    scanf("%d", &age);
    printf("gender (character => F or M): ");
    scanf(" %c", &gender);
    printf("enter the mission id: ");
    scanf(" %s", &missionId);

    for (int i = 0; missionId[i] != '\0'; i++)
    {
        if (i < 3 && isalpha(missionId[i]) == 0)
        {
            charErrors++;
        }
        if (i > 2 && isalnum(missionId[i]) == 0)
        {
            intErrors++;
        }
        stringSize++;
    }

    if (stringSize > 9)
    {
        printf("the mission id is longer than the maximum limit.\n");
    }
    else if (charErrors > 0)
    {
        printf("the mission id has integer errors.\n");
        if (intErrors > 0)
        {
            printf("the mission id has character errors.\n");
        }
    }
    else {
        mission = (MISSION){name, lName, age, gender, missionId};
        printf("\n");
        printf("mission data correctly created!");
        return 0;
    }
    printf("\n");
    printf("unable to create the mission with the requested data!\n");
    return 0;
}
