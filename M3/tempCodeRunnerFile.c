   fp = fopen("hashtags.txt", "r");
    int d_out[MAX_NUMBER_OF_LINES];
    char temp[MAX_LINE_SIZE]; // some buffer storage for each line

    // storage for MAX_NUMBER_OF_LINES strings each MAX_LINE_SIZE chars long
    char s_out[MAX_NUMBER_OF_LINES][MAX_LINE_SIZE];

    // i is a special variable that tells us if we're parsing a number or a string (0 for num, 1 for string)
    // di and si are indices to keep track of which line we're currently handling
    int i = 0, di = 0, si = 0;

    while (fgets(temp, MAX_LINE_SIZE, fp) != NULL) // read the input file and parse the string
    {
        temp[strlen(temp) - 1] = '\0'; // get rid of the newline in the buffer

        char *c = strtok(temp, " "); // set the delimiters

        while (c != NULL)
        {
            if (i == 0) // i equal to 0 means we're parsing a number
            {
                i = 1; // next we'll parse a string, let's indicate that
                sscanf(c, "%d", &d_out[di++]);
            }
            else // i must be 1 parsing a string
            {
                i = 0; // next we'll parse a number
                sprintf(s_out[si++], "%s", c);
            }
            c = strtok(NULL, " ");
        }
        printf("%d %s\n", d_out[di - 1], s_out[si - 1]); // print what we've extracted
    }

    fclose(fp);