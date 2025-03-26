#include <stdio.h>

#define NLETTER 26

main()
{
    int c;
    int lengths[NLETTER] = {0};

    while ((c = getchar()) != EOF)
    {
        if (c >= 'A' && c <= 'Z')
        {
            ++lengths[c - 'A'];
        }
        else if (c >= 'a' && c <= 'z')
        {
            ++lengths[c - 'a'];
        }
    }

    for (int i = 0; i < NLETTER; i++)
    {
        printf("%c: ", i + 'A');
        for (int j = 0; j < lengths[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}