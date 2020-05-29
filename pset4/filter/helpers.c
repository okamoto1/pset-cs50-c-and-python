#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float media = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            media = round(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = round(media);
            image[i][j].rgbtGreen = round(media);
            image[i][j].rgbtBlue = round(media);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int max = width - 1, tmp = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][max].rgbtRed;
            image[i][max].rgbtRed = tmp;
            tmp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][max].rgbtBlue;
            image[i][max].rgbtBlue = tmp;
            tmp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][max].rgbtGreen;
            image[i][max].rgbtGreen = tmp;
            max = max - 1;
        }
        max = width - 1;
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int somadorR = 0, somadorB = 0, somadorG = 0, a = 0, b = 0;
    float cnt;
    RGBTRIPLE copia[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copia[i][j] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            somadorR = 0, somadorB = 0, somadorG = 0, cnt = 0;
            if (i == 0)
            {
                if (j == 0)
                {
                    for (a = i; a <= i + 1 ; a ++)
                    {
                        for (b = j; b <= j + 1; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
                else if (j == width - 1)
                {
                    for (a = i; a <= i + 1; a ++)
                    {
                        for (b = j - 1; b <= j; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
                else
                {
                    for (a = i; a <= i + 1 ; a ++)
                    {
                        for (b = j - 1; b <= j + 1; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
            }
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    for (a = i - 1; a <= i ; a ++)
                    {
                        for (b = j; b <= j + 1; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
                else if (j == width - 1)
                {
                    for (a = i - 1; a <= i; a ++)
                    {
                        for (b = j - 1; b <= j; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
                else
                {
                    for (a = i - 1; a <= i; a ++)
                    {
                        for (b = j - 1; b <= j + 1; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
            }
            else
            {
                if (j == 0)
                {
                    for (a = i - 1; a <= i + 1; a ++)
                    {
                        for (b = j; b <= j + 1; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
                else if (j == width - 1)
                {
                    for (a = i - 1; a <= i + 1; a ++)
                    {
                        for (b = j - 1; b <= j; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
                else
                {
                    for (a = i - 1; a <= i + 1; a++)
                    {
                        for (b = j - 1; b <= j + 1; b++)
                        {
                            somadorR = somadorR + copia[a][b].rgbtRed;
                            somadorB = somadorB + copia[a][b].rgbtBlue;
                            somadorG = somadorG + copia[a][b].rgbtGreen;
                            cnt = cnt + 1;
                        }
                    }
                }
            }
            image[i][j].rgbtRed = round(somadorR / cnt);
            image[i][j].rgbtBlue = round(somadorB / cnt);
            image[i][j].rgbtGreen = round(somadorG / cnt);
        }
    }
    return;
}

