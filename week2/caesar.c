#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // STEP 1: Validate command-line arguments
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // STEP 2: Convert the key from string to int
    int key = atoi(argv[1]);

    // STEP 3: Get the plaintext from the user
    string plaintext = get_string("plaintext:  ");

    // STEP 4: Encrypt and print the ciphertext
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Rotate and print each character one by one
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// Check if a string consists only of decimal digits
bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Rotate character c by n positions, preserving case
char rotate(char c, int n)
{
    if (isupper(c))
    {
        // Shift to 0-25 range, rotate, wrap, and shift back to ASCII
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        // Shift to 0-25 range, rotate, wrap, and shift back to ASCII
        return (c - 'a' + n) % 26 + 'a';
    }
    
    // Return unchanged if not a letter
    return c;
}
