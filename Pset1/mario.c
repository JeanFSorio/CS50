#include <cs50.h>
#include <stdio.h>

int main(void)
{
//     Prompting the user for height, a positive integer between 1 and 8
    int h;
    do
    {
        h = get_int("Pyramid Height:");    
    }
    while (h < 1 || h > 8);

//     Print the blocks
//     this For will print n spaces, than n hasshes, then newline and repeat
    for (int i = 1; i <= h; i++) //counting from 1 for next variables work prolperly
    {
//         print space loop
        for (int j = i; j < h; j++)
        {
            printf(" ");
        }
//         print hashes loop
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
//         print hashes loop
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
