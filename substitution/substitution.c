#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int confkey(string conf);
void transform(string key, string text);

int main(int teste, string argv[])
{
    if (teste != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        if (confkey(argv[1]) == 0)
        {
            string text = get_string("plaintext: ");
            printf("ciphertext: ");
            transform(argv[1], text);
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

int confkey(string conf)
{
    int teste = 0;

    if (strlen(conf) != 26)
    {
        printf("Key must contain 26 letters \n");
        teste = 1;
    }

    else
    {
        for (int i = 0 ; i < strlen(conf) ; i++)
        {
            if (tolower(conf[i]) < 'a' ||  tolower(conf[i]) > 'z')
            {
                teste = 2;
            }
            for (int j = 0 ; j < i ; j++)
            {
                if (conf[i] == conf[j])
                {
                    teste = 3;
                }
            }
        }
        if (teste == 2)
        {
            printf("Only letters\n");
        }
        else if (teste == 3)
        {
            printf("No duplicate or multiple letters\n");
        }
    }
    return teste;
}

void transform(string key, string text)
{
    int posi = 0;
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] >= 'a' && text [i] <= 'z')
        {
            posi = text[i] - 97;
            printf("%c", tolower(key[posi]));
        }
        else if (text[i] >= 'A' && text [i] <= 'Z')
        {
            posi = text[i] - 65;
            printf("%c", toupper(key[posi]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}