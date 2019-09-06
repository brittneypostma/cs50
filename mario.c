#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
        height = get_int("Please choose a number from 1 to 8:\n");
    } while (height < 1 || height > 8);

    for (int r = 0; r <= height; r++)
    {
        for (int s = (height - r); s > 0; s--)
        {
            printf(" ");
        }
        for (int h = 1; h <= r; h++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}