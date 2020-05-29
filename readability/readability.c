#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void contagem(string text);



int main(void)
{
    string text = get_string("Text: ");
    contagem(text);
}


void contagem(string text)
{
    int letras = 0, palavras = 0, pontos = 0;
    float index = 0, L = 0, S = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        char teste = tolower(text[i]);
        if (teste >= 'a'  && teste <= 'z')
        {
            letras++;
        }
        else if (teste == ' ' || teste == '\0')
        {
            palavras++;
        }
        else if (teste == '.' || teste == '?' || teste == '!')
        {
            pontos++;
        }
    }
    L = ((float) letras / (float)palavras) * 100.0;
    S = ((float) pontos / (float)palavras) * 100.0;
    index = (0.0588 * L) - (0.296 * S) - 15.8;
    printf("%i letter(s)\n%i word(s)\n%i period(s)\n", letras, palavras, pontos);
    
    if (round(index) <= 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", (int)round(index));
    }

}

