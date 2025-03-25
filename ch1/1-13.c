#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 10

main()
{
    int c, n = 0, state = OUT;
    int lengths[MAX_WORD_LENGTH] = {0};

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
            {
                if (n > MAX_WORD_LENGTH)
                {
                    fprintf(stderr, "Error: Word length exceeds maximum of %d characters\n", MAX_WORD_LENGTH);
                    return -1;
                }
                ++lengths[n - 1];
                n = 0;
            }
            state = OUT;
        }
        else
        {
            state = IN;
            n++;
        }
    }

    for (int i = 0; i < MAX_WORD_LENGTH; i++)
    {
        printf("%2d: ", i + 1);
        for (int j = 0; j < lengths[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}