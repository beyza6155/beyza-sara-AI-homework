person *create_family(int generations)
{
    // Allocate memory for a new person
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        return NULL;
    }

    // If there are still generations left to create
    if (generations > 1)
    {
        // Recursively create two parents for the current person
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);

        // Randomly inherit one allele from each parent
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }
    // Base case: the oldest generation
    else
    {
        // No parents to link to
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        // Randomly assign both alleles
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    // Return the newly created person
    return p;
}
