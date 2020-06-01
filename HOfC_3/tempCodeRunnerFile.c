/**
 * Autor: Genaro Martinez A01566055
 * Date: 28/04/2020
 * Description: creates two parse files from a pre-sorted list of coordinates.
 * it generates two files, results1.txt displays the coordinates in:
 *              15°32′36″ North   53°55′20″ West 
 * and results2.txt in this format:
 *              36°26′17″ North   124°42′23″ West
 * in sorted data.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 150
#define MAX_STR 100
struct HOfC3
{
    double latitud, longitud;
    char ltD[20], lgD[20];
};

struct HOfC3 coordinates[MAX_LENGTH];

// swaps cooordinate structures
void swapCoords(int coord1, int coord2)
{
    struct HOfC3 temp = coordinates[coord1];
    coordinates[coord1] = coordinates[coord2];
    coordinates[coord2] = temp;
}

// sort coordinates
void quickSort()
{
    int min;

    for (int i = 0; i < MAX_STR-1; i++)
    {
        min = i;
        for (int j = i + 1; j < MAX_STR; j++)
        {
            if (coordinates[j].latitud < coordinates[min].latitud)
                min = j;
        }
        swapCoords(min, i);
    }
}

void parseCoordinates(FILE *degFile, FILE *coordFile)
{
    // pass every coordinate to each file
    for (int i = 0; i < MAX_STR; i++)
    {
        fprintf(degFile, "%f %f\n",
                coordinates[i].latitud,
                coordinates[i].longitud);
        char cd1 = coordinates[i].ltD[(strlen(coordinates[i].ltD) - 1)];
        char cd2 = coordinates[i].lgD[(strlen(coordinates[i].lgD) - 1)];

        // change cardinal points
        if (cd1 == 'N')
        {
            strcat(coordinates[i].ltD, "orth");
        }
        else
        {
            strcat(coordinates[i].ltD, "outh");
        }
        if (cd2 == 'W')
        {
            strcat(coordinates[i].lgD, "est");
        }
        else
        {
            strcat(coordinates[i].lgD, "ast");
        }

        fprintf(coordFile, "%s %s\n", coordinates[i].ltD, coordinates[i].lgD);
    }
    fclose(coordFile);
    fclose(degFile);
}

int main()
{
    FILE *fp, *fp2, *fp3;
    int fileIndex = 0;
    // generate and write file in first format
    fp2 = fopen("results1.txt", "w");
    // generate and write file in second format.
    fp3 = fopen("results2.txt", "w");
    // max length
    char *str[MAX_LENGTH];
    // Opens and verifies the file exists
    fp = fopen("coordinates_utf8.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open file the file");
        return 1;
    }
    while (!feof(fp) && fgets(str, MAX_LENGTH, fp)) 
    {
        char *tokens = strtok(str, " ");
        char *deg = strtok(NULL, " ");

        char *decimal = strtok(NULL, " ");

        // adds all coordinates to structures
        if (strcmp(tokens, "Latitude:") == 0)
        {
            strcpy(coordinates[fileIndex].ltD, deg);
            coordinates[fileIndex].latitud = atof(decimal);
        }
        else
        {
            strcpy(coordinates[fileIndex].lgD, deg);
            coordinates[fileIndex].longitud = atof(decimal);
            fileIndex++;
        }
    }
    fclose(fp);
    quickSort();
    parseCoordinates(fp2, fp3);
    return 0;
}
