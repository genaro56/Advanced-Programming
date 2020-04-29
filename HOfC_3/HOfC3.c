/**
 * Autor: Genaro Martinez A01566055
 * Date: 28/04/2020
 * Description: creates two parse files from a pre-sorted list of coordinates.
 * it generates two files, results1.txt displays the coordinates in:
 *              15°32′36″ North   53°55′20″ West 
 * and results2.txt in this format:
 *              36°26′17″ North   124°42′23″ West
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 150

void parseNullChar(char *coord) {
    while(*coord && 
          *coord != '\n' && 
          *coord != '\r'
        ) coord++;
    *coord = 0;
}

int main(){
    FILE *fp, *fp2, *fp3;
    // open pre-sorted data file
    fp = fopen("sorted_data.txt", "r");
    // generate and write file in first format
    fp2 = fopen("results1.txt", "w");
    // generate and write file in second format.
    fp3 = fopen("results2.txt", "w");
    // max length
    char *str[MAX_LENGTH];
    int secondFileIndex = 0, firstFileIndex = 0;
    while(!feof(fp)){
        fgets(str, 150, fp);
        char *cSToken = strtok(str, " ");
        // restart token indexation.
        int i = 1;
        
        // find each direction token.
        while(cSToken != NULL){
            if (i == 2){
                if(strchr(cSToken, 'N') != NULL)
                    fprintf(fp2, "%sorth ", cSToken);
                if(strchr(cSToken, 'W') != NULL)
                    fprintf(fp2, "%sest ", cSToken);
                if(strchr(cSToken, 'S') != NULL)
                    fprintf(fp2, "%south ", cSToken);
                if(strchr(cSToken, 'E') != NULL)
                    fprintf(fp2, "%sast ", cSToken);
                secondFileIndex++;
            }
            if (i == 3){
                parseNullChar(cSToken);
                fprintf(fp3, "%s ", cSToken);
                firstFileIndex++;
            }

            if (firstFileIndex == 2){
                fprintf(fp3, "\n");
                firstFileIndex = 0;
            }

            if (secondFileIndex == 2){
                fprintf(fp2, "\n");
                secondFileIndex = 0;
            } i++;
            // erase token and change to next line.
            cSToken = strtok(NULL, " ");
        }   
    }





    

    return 0;
}
