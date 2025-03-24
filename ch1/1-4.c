#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 140;
    step = 10;

    celsius = lower;
    printf("celsius fahr\n");
    while (celsius <= upper)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%6.0f  %3.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}