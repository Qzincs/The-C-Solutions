#include <stdio.h>

/* Use Ctrl+D to send EOF */
main()
{
    char c;
    c = (getchar() != EOF);
    printf("The value of 'getchar() != EOF' is %d\n", c);
}