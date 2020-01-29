#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
//     Prompt the user for the change owed
    float c;
    int coins, quarters, dimes, nickels, pennies;
    // c is to get the money, being a float positive with 2 decimal
    do
    {
        c = get_float("Money:");
    }
    while (c <= 0.009999999);
    //d will make c an intenger to make divisions further ahead
    int d = round(c * 100);
    // here divide the money by the quarters value, and the remainder go to the next coin over and over until every is done
    quarters = d / 25;
    dimes = d % 25 / 10;
    nickels = d % 25 % 10 / 5;
    pennies = d % 25 % 10 % 5;
    // coins is a sum of all coins
    coins = quarters + dimes + nickels + pennies;
    // printing all the coins for be easy to take then if you want
    printf("%i coins\n%i quarters\n%i dimes\n%i niquels\n%i pennies\n", coins, quarters, dimes, nickels, pennies);
}
