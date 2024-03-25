#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
char rotate(int key, char plai);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string k = argv[1];
    int key_arr[strlen(k)], key = 0;

    for (int p = 0, len = strlen(k); p < len; p++)
    {
        if (!isdigit(k[p]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        key_arr[p] = (int)k[p] - 48;
        key += key_arr[p] * pow(10, len - 1 - p);
    }
    string plain_txt = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int j = 0, len = strlen(plain_txt); j < len; j++)
    {
        int ciph[len];
        if (islower(plain_txt[j]))
        {
            char plai[len];
            plai[j] = plain_txt[j];
            printf("%c", rotate(key, plai[j]));
        }
        else if (isupper(plain_txt[j]))
        {
            char plai[len];
            plai[j] = plain_txt[j];
            printf("%c", rotate(key, plai[j]));
        }
        else
        {
            printf("%c", plain_txt[j]);
        }
    }
    printf("\n");
    return 0;
}
char rotate(int key, char plai)
{
    char ciph;
    if (islower(plai))
    {
        ciph = (plai - 97 + key) % 26 + 97;
    }
    if (isupper(plai))
    {
        ciph = (plai - 65 + key) % 26 + 65;
    }
    return ciph;
}