#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt for height until a valid integer between 1 and 8 is provided
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Iterate through each row
    for (int row = 1; row <= height; row++)
    {
        // 1. Print leading spaces (height - row)
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        // 2. Print left-side hashes (row)
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // 3. Print the two-space gap
        printf("  ");

        // 4. Print right-side hashes (row)
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
