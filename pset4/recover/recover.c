#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    int cnt = 0, n = 1, i = 0;
    char filename [3];
    unsigned char byte[512];
    FILE *file = fopen(argv[1], "r");
    FILE *imagem = fopen(filename, "w");
    while (fread(byte, 512, 1, file) == 1)
    {
        if (byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff && (byte[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", cnt);
            if (cnt == 0)
            {
                fclose(imagem);
                fopen(filename, "w");
                fwrite(byte, 1, 512, imagem);
            }
            else
            {
                fclose(imagem);
                fopen(filename, "w");
                fwrite(byte, 1, 512, imagem);
                
            }
            cnt = cnt + 1;
            printf("%s\n", filename);
        }
        else
        {
            fwrite(byte, 1, 512, imagem);
        }
    }
    return 0;
}