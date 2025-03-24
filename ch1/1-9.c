#include <stdio.h>

main()
{
    int c, last = 0;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || last != ' ')
        {
            putchar(c);
        }
        last = c;
    }
}