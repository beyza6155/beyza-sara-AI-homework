#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // STEP 1: Validate command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!is_valid_key(argv[1]))
    {
        // Specific error messages are often handled inside is_valid_key 
        // or just a general usage message for CS50
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string key = argv[1];

    // STEP 2: Get the plaintext from the user
    string plaintext = get_string("plaintext:  ");

    // STEP 3: Encrypt and print ciphertext
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            // Find alphabet position (0-25)
            int position = plaintext[i] - 'A';
            // Print key character in uppercase
            printf("%c", toupper(key[position]));
        }
        else if (islower(plaintext[i]))
        {
            // Find alphabet position (0-25)
            int position = plaintext[i] - 'a';
            // Print key character in lowercase
            printf("%c", tolower(key[position]));
        }
        else
        {
            // Non-alphabetic characters remain unchanged
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}

// Validation logic for the substitution key
bool is_valid_key(string key)
{
    // 1. Check length
    if (strlen(key) != 26)
    {
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        // 2. Check if alphabetic
        if (!isalpha(key[i]))
        {
            return false;
        }

        // 3. Check for duplicates (case-insensitive)
        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }

    return true;
}
