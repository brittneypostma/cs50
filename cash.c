#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    
    
    float quarter = 25;
    float dime = 10;
    float nickle = 5;
    float penny = 1;
    int coins = 0;
    float owed;
    do
    {
        float change = get_float("How much change is owed?\n");
        owed = change;
    }
    while (owed < 0);
        owed = owed * 100;
        int cents = round(owed);
    
    while (cents >= 25)
            {
                cents = cents-25;
                coins++;
            }
            while (cents >= 10)
            {
                cents = cents-10;
                coins++;
            }
            while (cents >= 5)
            {
                cents = cents-5;
                coins++;
            }
            while (cents >= 1)
            {
                cents--;
                coins++;
            }
        
      printf("The least amount of coins is: %i\n", coins);
}
