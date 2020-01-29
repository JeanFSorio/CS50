#include <stdio.h>
#include <cs50.h>
#include <math.h>

// declaring some variable before because of some conflicts if declaring in the code
long long card;
int sortnum(void);
int z = 0;

int main(void)
{
    // prompt the user for the card number
    card = get_long("Insert the credit number: ");
    
    // all that is to reduze the card for 2 digits for check further ahead 
    int check13 = card / pow(10, 11);
    int check15 = card / pow(10, 13);
    int check16 = card / pow(10, 14);  
    
    // there I call the sortsum for se if luhn algorithm is equal to 0. the letter z is representing the luhn result
    sortnum();   
    if (z % 10 == 0)
    {
        //checking the 2 digits is from AMEX and printing
        if (check15 == 34 || check15 == 37)
        {
            printf("AMEX\n");
        }
        //checking the 2 digits is from MASTERCARD and printing
        else if (check16 == 51 || check16 == 52 || check16 == 53 || check16 == 54 || check16 == 55)
        {
            printf("MASTERCARD\n");
        }
        //checking the 2 digits is from VISA and printing
        else if (check13 / 10 == 4 || check16 / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}






//luhn algorithm int output for returning z
int sortnum(void)
{
    //16 loops for checking every number, if the credit card has less then 16 digits the final ones will return 0 for the sum of z
    for (int i = 1 ; i <= 17; i++)
    {
        //y is the pow of 10 needed for targeting every single digit at once 
        long y = pow(10, i - 1);
        // this calculantion will return the target number stated be 'i', so will give from every single position. The calculation will see the remainder of the division of the card by a power of 10, the power sinalize the digit targered and the remainder will collet only that number
        int x = (card / y) % 10;
        // check parity position, if even multiply x for 2
        if (i % 2 == 0)
        {
            x *= 2;
            // when 10 or more we need to sum the two digits, whats equals to subtract 9
            if (x >= 10)
            {
                x -= 9;
            }
        }
        // every loop, starting from 0, z will sum with the value of z
        z += x;
    }
    return z;
}
