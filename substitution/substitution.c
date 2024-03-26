#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char enc(string key, char plain);
int main(int argc, string argv[])
{
    string k = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (strlen(k) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int j = 0, len = strlen(k); j < len; j++)
    {
        if (!isalpha(k[j]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    for (int j = 0, len = strlen(k); j < len; j++)
    {
        for (int i = 0; i < len; ++i)
        {
            if (toupper(k[j]) == toupper(k[i]) && i != j)
            {
                printf("the key should not have a repetitf characters\n");
                return 1;
            }
        }
    }
    string plain_txt = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int j = 0, len = strlen(plain_txt); j < len; j++)
    {
        int plain[len];
        plain[j] = plain_txt[j];
        printf("%c", enc(k, plain[j]));
    }
    printf("\n");
    return 0;
}
char enc(string key, char plain)
{
    char ciph;
    if (isalpha(plain))
    {
        if (islower(plain))
        {
            ciph = tolower(key[plain - 97]);
        }
        else
        {
            ciph = toupper(key[plain - 65]);
        }
    }
    else
    {
        ciph = plain;
    }
    return ciph;
}