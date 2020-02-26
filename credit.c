#include <stdio.h>
#include <cs50.h>
#include <math.h>

// prompt for input
// calculate checkSum
// check card length and starting digits
// print amex, mc, visa, or invalid

void cardInput(void);
int length(long long n);
bool checkLength(int len);
void checkCard(long long cc);
bool checkSum(long long cc, int len);
void cardType(long long cc);

int main(void)
{
    cardInput();
    // valid cc numbers for testing
    // Amex - 378282246310005
    // MC - 5404000000000001
    // Visa - 4242424242424242
}

void cardInput(void)
{
    long long cardNumber;
    do
    {
        cardNumber = get_long_long("Enter Credit Card Number: ");
    } while (cardNumber < 0);
    checkCard(cardNumber);
}

int length(long long n)
{
    int len = 0;
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return len;
}

bool checkLength(int len)
{
    if (len == 13 || len == 15 || len == 16)
    {
        return true;
    }
    return false;
}

void checkCard(long long cc)
{
    int len = length(cc);

    if (!(checkLength(len) && checkSum(cc, len)))
    {
        printf("INVALID\n");
        return;
    }
    else
    {
        cardType(cc);
    }
}

bool checkSum(long long cc, int len)
{
    int sum = 0;
    // loop through the credit card
    for (int i = 0; i < len; i++, cc /= 10)
    {
        // when 1 is even
        if (i % 2 == 0)
        {
            sum += (cc % 10);
        }
        // when 1 is odd
        else
        {
            int digit = (2 * (cc % 10));
            sum += (digit / 10 + digit % 10);
        }
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

void cardType(long long cc)
{
    if ((cc >= 340000000000000 && cc < 350000000000000) || (cc >= 370000000000000 && cc < 380000000000000))
    {
        printf("AMEX\n");
    }
    else if (cc >= 5100000000000000 && cc < 5600000000000000)
    {
        printf("MASTERCARD\n");
    }
    else if ((cc >= 4000000000000 && cc < 5000000000000) || (cc >= 4000000000000000 && cc < 5000000000000000))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
