#include <stdio.h>

float fahr_to_celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("fahr celsius\n");
    while (fahr <= upper)
    {
        printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
        fahr = fahr + step;
    }
}