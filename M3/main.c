#include <stdio.h>
#include <string.h>

struct hashtag
{
    char name[20];
    int count;
};

struct hashtag hashtagList[20];

#define MAXCHAR 1000
int main()
{
    FILE *fp;
    char str[MAXCHAR];
    char *filename = malloc(100 + 1);

    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
    {
        // Extract the first token
        char *token = strtok(str, " ");
        // loop through the string to extract all other tokens
        while (token != NULL)
        {
            if (strchr(token, '#') != NULL)
            {
                char *start = strstr(token, ">");
                char *end = strstr(token, "<");

                if (end != NULL && start != NULL)
                {
                    start++;
                    *end = '\0';
                    for (int i = 0; i < 20; i++)
                    {
                        if (strcmp(hashtagList[i].name, start) == 0)
                        {
                            hashtagList[i].count++;
                            break;
                        }
                        if (hashtagList[i].name[0] == '\0')
                        { // Found empty entry, last of list
                            strcpy(hashtagList[i].name, start);
                            hashtagList[i].count = 1;
                            break;
                        }
                    }
                }
            }
            token = strtok(NULL, " ");
        }
    }

    for (int i = 0; i < 20; i++)
    {
        if (hashtagList[i].name[0] != '\0')
            printf("%s: %i\n", hashtagList[i].name, hashtagList[i].count);
    }

    fclose(fp);
    return 0;
}