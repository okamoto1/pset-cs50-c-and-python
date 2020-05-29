// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"

int *tamanho = 0, cnt = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 14009;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int key = hash(word);
    if(strcasecmp(table[key]->word, word) == 0)
    {
        return true;
    }
    else
    {
        node *cursor = table[key];
        while(strcasecmp(cursor->word, word) != 0)
        {
            if(cursor -> next == NULL)
            {
                return false;
            }
            cursor = cursor -> next;
        }
        return true;
    }
    return false;
}

// Hashes word to a number
// https://stackoverflow.com/questions/7700400/whats-a-good-hash-function-for-english-words
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c = 0;

    while (c == *word++)
        hash = ((hash << 5) + hash) + c;

    return hash%N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dicionario = fopen(dictionary, "r");
    char *buffer = malloc(sizeof(char));
    if (dicionario == NULL || buffer == NULL )
    {
        return false;
    }
    else
    {
        while(fscanf(dicionario, "%s", buffer) != EOF)
        {
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }
            strcpy(n->word, buffer);
            int key = hash(n->word);
            if (table[key] == NULL)
            {
                n->next = NULL;
                table[key] = n;
            }
            else
            {
                 n->next = table[key];
                 table[key] = n;
            }
            cnt++;
        }
        free(buffer);
        tamanho = &cnt;
        return true;
    }
    fclose(dicionario);
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return *tamanho;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int key = 0; key < N; key++)
    {
        node *cursor = table[key];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
        }
        free(cursor);
    }
    return true;
}
