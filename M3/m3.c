#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hashtagToken {
    int count;
    char *name;
};

struct hashtagToken hashtagList[30];
#define MAXCHAR 1000

int main(int argc, char const *argv[]) {
    FILE *fp;
    char str[1000];
    char *fname = malloc(MAXCHAR+1);
    scanf("%s", fname);
    fp = fopen(fname, "w");

    if (fp == NULL) {
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
                char *start = strstr(hashtag, ">");
                char *end = strstr(hashtag, "<");

                if (end != NULL && start != NULL)
                {   
                    start++;
                    *end = '\0';
                    printf("%s\n", start);
                }
            }
            hashtag = strtok(NULL, " ");
        }
        
    }

    fclose(fp);
    return 0;
}