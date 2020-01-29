#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    // testing if is argc has just two arguments and the second argument is just numerical, then go to the code
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if isalpha(argv[1][i])
            {
            }
            // else if (n != 26)
            // {
            //     printf("Key must contain 26 characters.\n");
            //     return 0;
            // }
            else
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    // if not digit if only one argument print for the right usage and exit
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int q = 0; q < 26; q++)
    {
        for (int w = 0; w < q; w++)
        {
            if (argv[1][q] == argv[1][w])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }



    // prompt for text
    string text = get_string("Plaintext:");
    string c = text;



    // alphaindex must be the i from argv[i]
    // if lowercase text, argv toupper, else argv tolower
    // cipher[i] text gonna be argv[i]
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                // text to alphaindex
                int x = text[i] - 65;
                c[i] = toupper(argv[1][x]);

            }
            else
            {
                // text to alphaindex
                int x = text[i] - 97;
                c[i] = tolower(argv[1][x]);
            }
        }
    }
    printf("ciphertext: %s\n", c);


}
