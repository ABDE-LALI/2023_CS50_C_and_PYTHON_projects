#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string text;
    int i = 0, char_int;
    text = get_string("Enter a text to convert it to binary: ");
    string conv = text;
    while (text[i] != '\0')
    {
        char_int = (int)conv[i];
        int bit = 1, cond = 0, bit_arr[8], j = 0;
        while (cond != BITS_IN_BYTE)
        {
            bit = char_int % 2;
            bit_arr[j] = bit;
            char_int /= 2;
            cond++;
            j++;
        }
        for (int k = 7; k >= 0; k--)
        {
            print_bulb(bit_arr[k]);
        }
        printf("\n");
        i++;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
