/**
 * MISSION - 03
 * Author: Genaro Martinez A01566055
 * Date: 26/04/2020
 * 
 * Description: read from Twitter a raw html file its number of hashtags and compare its repetitions
 * then save them in a list of structs.
 * 
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hashtagToken
{
    int count;
    char *name;
};

struct hashtagToken hashtagList[100];

#define MAXCHAR 1000
#define MAXFNAME 20
#define MAX_NUMBER_OF_LINES 10 // parse a maximum of 10 lines
#define MAX_LINE_SIZE 50       // parse a maximum of 50 chars per line

int main(int argc, char const *argv[])
{
    FILE *fp, *fp2;
    char str[1000];
    // char *fname = malloc(MAXFNAME + 1);
    char *fname = "index.html";
    int index = 0;
    // scanf("%s", fname);
    // reading custom file
    fp = fopen(fname, "r");
    fp2 = fopen("results.txt", "w");

    if (fp == NULL)
    {
        printf("The file %s could not be opened", fname);
        return -1;
    }

    while (fgets(str, MAXCHAR, fp) != NULL)
    {
        char *hashtag = strtok(str, " ");
        while (hashtag != NULL)
        {
            if (strchr(hashtag, '#') != NULL)
            {
                // token where each hashtag begins
                char *start = strstr(hashtag, "r-qvutc0\">");
                // token where each hashtag ends
                char *end = strstr(hashtag, "<");
                if (end != NULL && start != NULL)
                {
                    start += 9;
                    start++;
                    *end = '\0';
                    index++;
                    fprintf(fp2, "%s\n", start);
                }
            }
            hashtag = strtok(NULL, " ");
        }
    }
    printf("no. of hashtags found: %d\n", index);
    // use intermediate file to print the results and count repetitions using unique.
    fclose(fp);
    fclose(fp2);
    system("sort ./results.txt | uniq -c >> hashtags.txt");

    fp = fopen("hashtags.txt", "r");
    int d_out[MAX_NUMBER_OF_LINES];
    char temp[MAX_LINE_SIZE]; // some buffer storage for each line
    // max limit for each hashtag result.
    char s_out[MAX_NUMBER_OF_LINES][MAX_LINE_SIZE];
    // index for each column.
    int i = 0, di = 0, si = 0;
    // read the intermediate file by columns
    while (fgets(temp, MAX_LINE_SIZE, fp) != NULL)
    {   
        // create a string to compare within each column.
        temp[strlen(temp) - 1] = '\0';

        char *c = strtok(temp, " ");

        while (c != NULL)
        {
            // compare if its second or first line
            if (i == 0)
            {
                i = 1;
                // parse digits
                sscanf(c, "%d", &d_out[di++]);
                hashtagList[di++].count = d_out[di - 1];
            }
            else
            {
                // add string to struct name type
                i = 0;
                hashtagList[si++].name = c;
            }
            c = strtok(NULL, " ");
        }
        // print results in struct.
        printf("count: %d hashtag: %s\n", hashtagList[di - 1].count, hashtagList[si - 1].name);
    }
    // close and erase intermediate file.
    fclose(fp);
    remove("hashtags.txt");
    return 0;
}