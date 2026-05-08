#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for their name using get_string()
    // "name" is the variable where we store the user's input
    string name = get_string("What is your name? ");

    // Print "hello, " followed by their name using printf()
    // %s is the placeholder for the string variable
    printf("hello, %s\n", name);
}
