#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int getCandidate(string name);
int getStrengthOfVictory(int i);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int candidateIndex = getCandidate(name);

    if (candidateIndex < 0)
    {
        return false;
    }

    ranks[rank] = candidateIndex;

    return true;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // i=vote order ranks[i]=candidateIndex
            // printf("%s is prefered over %s\n", candidates[ranks[i]], candidates[ranks[j]]);
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i != j && preferences[i][j] > 0 && preferences[i][j] > preferences[j][i])
            {
                // printf("%s is prefered %i times over %s (%i times).\n", candidates[i], preferences[i][j], candidates[j], preferences[j][i]);
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int j, currentV;
    pair currentPair;

    // I've decided to implement the Insertion Sort just because it is the smallest sort algorithm to implement, making this whole code (Tideman prob. set) more readable.
    for (int i = 1; i < pair_count; i++)
    {
        currentV = getStrengthOfVictory(i);
        currentPair = pairs[i];
        j = i;

        while (j > 0 && getStrengthOfVictory(j - 1) < currentV)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }

        pairs[j] = currentPair;
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Locks every set pair to true
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }

    // Bool aray that stores if any of the pairs' winning candidates lose in another pair
    bool lost[candidate_count];

    // Repeats removing last candidate's lock (the one with the smallest win margin) until there are no cycles (or no candidates are left)

    for (int i = (pair_count - 1); i >= 0; i--)
    {
        // For every new turn of the above loop, this at the start sets the lost defaults for every candidate to false
        for (int l = 0; l < pair_count; l++)
        {
            lost[l] = false;
        }
        // This 'no_undefeated' bool will soon be linked to the lost bool array
        bool no_undefeated = true;
        // Checks if the j-th pair's winner is the k-th pair's loser, if so sets the 'lost' bool of the j-th pair's winner to be true
        for (int j = 0; j < pair_count; j++)
        {
            for (int k = j + 1; k < pair_count; k++)
            {
                if (pairs[j].winner == pairs[k].loser)
                {
                    lost[j] = true;
                }
            }
        }

        // Checks how many pairs' winners have lost, if there's one who hasn't lost, sets the 'no_undefeated' bool to false
        for (int l = 0; l < pair_count; l++)
        {
            if (lost[l] == false)
            {
                no_undefeated = false;
            }
        }

        // Finally, if the 'no_undefeated' bool is true—i.e., there are no candidates who have been undefeated and the graph is cyclical
        // this condition unlocks the least strong existing pair

        if (no_undefeated == true)
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    bool lost = true;
    int interations = 0;

    for (int i = 0; i < candidate_count; i++) // i = victories
    {
        for (int j = 0; j < candidate_count; j++) // j = loses
        {
            interations++;
            if (locked[j][i])
            {
                lost = true;
                break;
            }
            else
            {
                lost = false;
            }
        }

        if (!lost)
        {
            printf("%s\n", candidates[i]);
        }
    }

    return;
}

// ---------------

int getStrengthOfVictory(int i)
{
    return preferences[pairs[i].winner][pairs[i].loser];
}

int getCandidate(string name)
{
    // Linear search. O(n) Ω(1)
    for (int i = 0; i < candidate_count ; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            return i;
        }
    }

    return -1;
}
