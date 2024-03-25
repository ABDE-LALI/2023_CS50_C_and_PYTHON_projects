#include <cs50.h>
#include <stdio.h>
bool checsum(long long credit);
void brend(long long credit);
int main(void)
{
    long long credit;
    do
    {
        credit = get_long_long("please enter the cridit card number: ");
    }
    while (credit <= 0);
    if (checsum(credit))
    {
        brend(credit);
    }
    else
    {
        printf("INVALID\n");
    }
}
bool checsum(long long credit)
{
    int tot = 0, pos = 0, mud = 0;
    while (credit != 0)
    {
        if (pos % 2 == 0)
        {
            mud = credit % 10;
            tot += mud;
        }
        else
        {
            mud = (credit % 10) * 2;
            if (mud > 9)
            {
                tot += mud % 10 + 1;
            }
            else
            {
                tot += mud;
            }
        }
        pos++;
        credit /= 10;
    }
    if (tot % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void brend(long long credit)
{
    int len = 0;
    long long cre = credit;
    // calculating the length
    while (cre != 0)
    {
        len++;
        cre /= 10;
    }
    //MASTER
    if (len == 16 && (credit / 100000000000000 >= 51 && credit / 100000000000000 <= 55))
    {
        if (credit / 100000000000000 >= 51 && credit / 100000000000000 <= 55)
        {
            printf("the brend card is: MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //AMEX
    else if (len == 15)
    {
        if (credit / 10000000000000 == 34 || credit / 10000000000000 == 37)
        {
            printf("the brend card is: AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //VISA
    else if (len == 13 || len == 16)
    {
        if (credit / 1000000000000 == 4 || credit / 1000000000000000 == 4)
        {
            printf("the brend card is: VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //INVALID
    else
    {
        printf("INVALID\n");
    }
}