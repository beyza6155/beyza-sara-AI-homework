#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Use a do-while loop to prompt for height.
    // Keep re-prompting until height is between 1 and 8 (inclusive).
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop through each row
    for (int row = 1; row <= height; row++)
    {
        // Print (height - row) spaces
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // Print (row) hashes
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Print a newline to end the row.
        printf("\n");
    }

    return 0;
}
