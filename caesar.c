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
            if isdigit(argv[1][i])
            {
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    // if not digit if only one argument print for the right usage and exit
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    // prompt for text
    string text = get_string("Plaintext:");
    string c = text;

    // k is the key and need a int, so use atoi to make the string [1] from argv be a int
    int k = atoi(argv[1]);


    // encypher; for loop to pick every digit, then a if condition to se if is uppercase or lowercase, than do the math.
    //for the math is need to convert ASCII to alphaIndex, by  substract for the number of 'A' and 'a'
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if isupper(text[i])
        {
            text[i] -= 65;
            c[i] = (text[i] + k) % 26;
            c[i] += 65;
        }
        else if islower(text[i])
        {
            text[i] -= 97;
            c[i] = (text[i] + k) % 26;
            c[i] += 97;
        }
    }
    // print the ciphertext
    printf("ciphertext: %s\n", c);
}
