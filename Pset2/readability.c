#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    //prompt for the text
    string text = get_string("text:");
    printf("%s\n", text);



    //select only alpha
    //count number of letter, sentences and words
    int l = 0;
    int s = 0;
    int w = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            l++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
            w++;
        }
        if (isalpha(text[i - 1]) && (isblank(text[i]) || text[i] == ';' || text[i] == ':' || text[i] == ','))
        {
            w++;
        }
    }

    //  letter per 100 words / sentences per 100 words
    float lw = (float) l * 100 / (float) w;
    float sw = (float) s * 100 / (float) w;

    // index = 0.0588 * Letters - 0.296 * Sentences - 15.8
    float index = 0.0588 * lw - 0.296 * sw - 15.8;

    // use round for the index
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }


}
