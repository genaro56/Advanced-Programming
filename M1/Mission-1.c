/*
Author: Genaro Martínez S.
id: A01566055
date: 01/03/2020

DOCUMENT 01: creating a new document registry system.
*/

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>

// crea la estructura del documento.
typedef struct
{
    char *name;
    char *lName;
    int age;
    char *(activeId);
    char *(missionId);
} DOCUMENT;

void remove_element(DOCUMENT *array, int index, int array_length)
{
   int i;
   for(i = index; i < array_length - 1; i++) array[i] = array[i + 1];
}

// Revisa que el id de la misión funcione correctamente
bool checkMission(char missionId[])
{
    int intErrors = 0, charErrors = 0, stringSize = 0;

    for (int i = 0; missionId[i] != '\0'; i++)
    {
        // revisa el tipo de dato.
        if (i < 4 && isalpha(missionId[i]) == 0)
        {
            charErrors++;
        }
        if (i > 3 && isalnum(missionId[i]) == 0)
        {
            intErrors++;
        }
        stringSize++;
    }

    if (stringSize > 12)
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
    else
    {
        printf("\n");
        printf("mission data correctly created!");
        return true;
    }
    return false;
}

// revisa cada caracter de un active id creado
bool checkActive(char activeId[])
{
    int intErrors = 0, charErrors = 0, stringSize = 0;

    for (int i = 0; activeId[i] != '\0'; i++)
    {
        if (i < 5 && isalpha(activeId[i]) == 0)
        {
            charErrors++;
        }
        if (i > 4 && isalnum(activeId[i]) == 0)
        {
            intErrors++;
        }
        stringSize++;
    }

    if (stringSize > 13)
    {
        printf("the active id is longer than the maximum limit.\n");
    }
    else if (charErrors > 0)
    {
        printf("the active id has integer errors.\n");
        if (intErrors > 0)
        {
            printf("the active id has character errors.\n");
        }
    }
    else
    {
        printf("\n");
        printf("active data correctly created!");
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    char name[20];
    char lName[20];
    char missionId[20];
    char activeId[20];
    char *activesArr[20];
    int entry, age, activesNo = 0, intErrors = 0, charErrors = 0, stringSize = 0;
    char gender;
    bool allCheck, missionCheck, activeCheck;
    DOCUMENT mission;
    DOCUMENT* missions = malloc(5 * sizeof *missions);

printf("________________________\n");
printf("    `'-.,________,,..-  ___ \________      \n");
printf("       > `'-.,_____,,.-`<_>\ )__     `\    \n");
printf("         >            `'-._    _)____  \   \n");
printf("          >          _.-'`  _______  `\ |  \n");
printf("           >   _,,..--'''```       `'-.\|  \n");
printf("          >-'``                        `'    \n");
printf("       ----ADVANCED PROGRAMMING SEMINARY----     ");
printf("\n");

printf("Options (1 or 2): \n");
printf("1 create entry \n");
printf("2 delete entry \n");
scanf("%d", &entry);
    if (entry == 1)
    {
        printf("name: ");
        scanf("%s", &name);
        printf("last name: ");
        scanf("%s", &lName);
        printf("age (integer): ");
        scanf("%d", &age);
        printf("enter number of mission actives: ");
        scanf(" %d", &activesNo);
        for (int i = 0; i < activesNo; i++)
        {
            printf("enter active %d: ", i + 1);
            scanf("%s", activeId);
            if (checkActive(activeId))
            {
                activesArr[i] = activeId;
                /* code */
            }
            else
            {
                printf("unable to create the active with the requested data!\n");
            }
        }

        printf("enter the mission id: ");
        scanf(" %s", &missionId);
        if (checkMission(missionId))
        {
            missionCheck = true;
        }

        if (missionCheck && activeCheck)
        {
            mission = (DOCUMENT){name, lName, age, gender, missionId};
            printf("\n");
            printf("mission data correctly created!");
            missions[0] = mission;
            return 0;
        }
        else
        {
            printf("\n");
            printf("unable to create the document with the requested data!\n");
        }
    }
    else
    {
        char *deleteDocId[10];
        printf("choose name of mission document to delete");
        scanf("%s", &deleteDocId);
        /* missing code to delete an agent registry */
        for (int i = 0; i < sizeof *missions; i++)
        {
            if(missions[i].name == deleteDocId) {
                remove_element(missions, i, sizeof *missions);
                printf("element successfully removed");
            }
        }
        
    }
    return 0;
}
