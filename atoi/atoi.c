#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input, int signe);

int main(void)
{
    string input = get_string("Enter an integer: ");
    int signe;
    if (isdigit(input[0]))
    {
        for (int i = 0, n = strlen(input); i < n; i++)
        {
            if (!isdigit(input[i]))
            {
                printf("Invalid Input1!\n");
                return 1;
            }
        }
    }
    else if (input[0] == '-')
    {
        for (int j = 1, n = strlen(input); j < n; j++)
        {
            if (!isdigit(input[j]))
            {
                printf("Invalid Input1!\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Invalid Input\n");
    }

    // Convert string to int
    if (isdigit(input[0]))
    {
        signe = 1;
        printf("%i\n", convert(input, signe));
    }
    else if (input[0] == '-')
    {
        signe = 2;
        printf("%i\n", -1 * convert(input, signe));
    }
    else
    {
        printf("Invalid Input3!\n");
        return 1;
    }
}

int convert(string input, int signe)
{
    // TODO
    int len = strlen(input), output = 0;
    switch (signe)
    {
        case 1:
            for (int i = 0; i < len; i++)
            {
                output += (input[i] - 48) * pow(10, len - 1 - i);
            }
            break;
        case 2:
            for (int j = 1; j < len; j++)
            {
                output += (input[j] - 48) * pow(10, len - 1 - j);
            }
            break;
    }
    return output;
}
