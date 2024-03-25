// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int words = 0;
unsigned int checkha;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TOD
    checkha = hash(word);
    node *curser = table[checkha];
    while (curser != NULL)
    {
        if (strcasecmp(word, curser->word) == 0)
        {
            return true;
        }
        curser = curser->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long tot = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        tot += tolower(word[i]);
    }
    return tot % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        printf("the dictionary did not opened sucsessfully.");
        return false;
    }
    char buffer[LENGTH + 1];
    while (fscanf(infile, "%s", buffer) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(infile);
            return false;
        }
        checkha = hash(buffer);
        strcpy(new_node->word, buffer);
        new_node->next = table[checkha];
        table[checkha] = new_node;
        words++;
    }
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (words > 0)
    {
        return words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *curser = table[i];
        while (curser)
        {
            node *tmp = curser;
            curser = curser->next;
            free(tmp);
        }
    }
    return true;
}
