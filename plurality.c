#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // for loop to compare if the names is equal to one of candidates and doing a plus vote for then
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // some declarations used in the function
    string winner1;
    int w;
    string winner2[candidate_count];
    int current_winner = 0;
    int two_winners[candidate_count];

    // here we calculate the first winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= current_winner)
        {
            winner1 = candidates[i].name;
            w = i;
            current_winner += candidates[i].votes;
        }
    }

    // for loop to sign others winners to the array winner2
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == candidates[w].votes && candidates[i].name != candidates[w].name)
        {
            winner2[i] = candidates[i].name;
            two_winners[i] = 1;
        }
    }



    // print the first winner
    if (winner1 != 0)
    {
        printf("%s\n", winner1);

    }

    //if more winners print that array
    for (int j = 0; j < candidate_count; j++)
    {
        if (two_winners[j] == 1)
        {
            printf("%s\n", winner2[j]);
        }
    }


    return;
}
