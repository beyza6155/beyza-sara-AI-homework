// Update vote totals given a new vote
bool vote(string name)
{
    // Loop through candidates to find a matching name
    for (int i = 0; i < candidate_count; i++)
    {
        // Use strcasecmp for a case-insensitive comparison
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    // If loop finishes without finding the name, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // 1. Find the maximum number of votes
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // 2. Print every candidate who has that maximum number
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}
