#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Please choose a number from 1 to 8:\n");
   
    while (height > 0 || height <= 8)
    {
        for (int rows = 0; rows <= height; rows++)
        {
            for (int ls = (height-rows); ls > 0; ls--)
            {
                printf(" ");
            }
            for (int lhash = 1; lhash <= rows; lhash++)
            {
                printf("#");
                
            }
            printf("  ");
            for (int rhash = 1; rhash <=rows; rhash++)
                {
                    printf("#");
                }
            printf("\n");  
        }  
        return 0;
    }
}
