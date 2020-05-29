#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void transform(string alo, int key);

int main(int arg, string argv[])
{
    string conf = argv[1];
    if (arg != 2 || atoi(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0 ; i < strlen(conf) ; i++)
        {
            if (tolower(conf[i]) >= 'a' && tolower(conf[i]) <= 'z')
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        string teste = get_string("plaintext: ");
        printf("ciphertext: ");
        transform(teste, atoi(argv[1]));
        return 0;
    }
}


void transform(string alo, int key)
{

    for (int i = 0 ; i < strlen(alo) ; i++)
    {
        if ('a' <= alo[i] && alo[i] <= 'z') 
        {
            if (alo[i] + key > 122)
            {
                int dif = (alo[i] + key) - 122;
                while (96 + dif > 122)
                {
                    dif = 96 + dif - 122;
                }
                printf("%c", 96 + dif);
            }
            else
            {
                printf("%c",  alo[i] + key);
            }
        }
        else
        {
            if ('A' <= alo[i] && alo[i] <= 'Z')
            {
                if (alo[i] + key > 90)
                {
                    int dif = (alo[i] + key) - 90;
                    while (64 + dif > 90)
                    {
                        dif = 64 + dif - 90;
                    }
                    printf("%c", 64 + dif);
                }
                else
                {
                    printf("%c",  alo[i] + key);
                }
            }
            else
            {
                printf("%c", alo[i]);
            }
        }
    }
    printf("\n");
}
