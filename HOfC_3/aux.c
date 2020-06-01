/** This program reads a text file
 * And passes the coordinate pairs into two distinct files
 * Ricardo Garza Gerhard - A00816705
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Holds information of each coordinates
struct coord {
    double lat;
    double longi;
    char latDeg[20];
    char longDeg[20];
};

// Holds all the coordinates
struct coord coordinateList[100];


// function to sort all coordinates based on latitude and longitud
void sortCoordinates() {
    int min;

    for (int i = 0; i < 99; i++) {
        min = i;
        for (int j = i + 1; j < 100; j++) {
            if (coordinateList[j].lat < coordinateList[min].lat)
                min = j;
        }
        swapCoords(min, i);
    }
}

#define MAXCHAR 1000
int main()
{
    FILE *fp;
    char str[MAXCHAR]; // Used to hold the line read from the file
    char *filename = "coordinates_utf8.txt";

    // Opens and verifies the file exists
    fp = fopen(filename, "r");
    if (fp == NULL ){
        printf("Could not open file %s", filename);
        return 1;
    }

    int coordPos = 0;

    // reads the file line by line 
    while (fgets(str, MAXCHAR, fp) != NULL) {
        char *tokens = strtok(str, " ");
        char *deg = strtok(NULL, " ");

        char *decimal = strtok(NULL, " ");

        // adds all coordinates to structures
        if (strcmp(tokens, "Latitude:") == 0) {
            strcpy(coordinateList[coordPos].latDeg, deg);
            coordinateList[coordPos].lat = atof(decimal);
        } else {
            strcpy(coordinateList[coordPos].longDeg, deg);
            coordinateList[coordPos].longi = atof(decimal);
            coordPos++;
        }
    }
    fclose(fp);

    sortCoordinates();

    // Holds files to be printed out
    FILE *degFile, *coordFile;
    degFile = fopen("degFiles.txt", "w");
    coordFile = fopen("coordFiles.txt", "w");

    // pass every coordinate to each file
    for (int i = 0; i < 100; i++) {
        fprintf(degFile, "%f %f\n", coordinateList[i].lat, coordinateList[i].longi);

        char cardPoint1 = coordinateList[i].latDeg[(strlen(coordinateList[i].latDeg) - 1)], 
        cardPoint2 = coordinateList[i].longDeg[(strlen(coordinateList[i].longDeg) - 1)];

        // change cardinal points
        if (cardPoint1 == 'N') {
            strcat(coordinateList[i].latDeg, "orth");
        } else {
            strcat(coordinateList[i].latDeg, "outh");
        }
        if (cardPoint2 == 'W') {
            strcat(coordinateList[i].longDeg, "est");
        } else {
            strcat(coordinateList[i].longDeg, "ast");
        }

        fprintf(coordFile, "%s %s\n", coordinateList[i].latDeg, coordinateList[i].longDeg);
    }

    printf("Finished writing files\n");

    // Close all files
    fclose(coordFile);
    fclose(degFile);
}
