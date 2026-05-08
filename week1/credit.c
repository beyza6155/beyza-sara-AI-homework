#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for a credit card number
    long card_number = get_long("Number: ");

    // -----------------------------------------------------------------------
    // STEP 1: Count the number of digits
    // -----------------------------------------------------------------------
    int length = 0;
    long temp_number = card_number;
    while (temp_number > 0)
    {
        temp_number /= 10;
        length++;
    }

    // -----------------------------------------------------------------------
    // STEP 2: Apply Luhn's Algorithm
    // -----------------------------------------------------------------------
    int sum_doubled = 0;
    int sum_rest = 0;
    temp_number = card_number;

    for (int i = 0; i < length; i++)
    {
        int digit = temp_number % 10;
        temp_number /= 10;

        // If position i is ODD (starting from 0 at the end), it's every other digit starting from second-to-last
        if (i % 2 != 0)
        {
            int product = digit * 2;
            // Add digits of product (e.g., 12 becomes 1 + 2)
            sum_doubled += (product / 10) + (product % 10);
        }
        else
        {
            sum_rest += digit;
        }
    }

    // -----------------------------------------------------------------------
    // STEP 3: Check validity
    // -----------------------------------------------------------------------
    if ((sum_doubled + sum_rest) % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // -----------------------------------------------------------------------
    // STEP 4: Identify card type
    // -----------------------------------------------------------------------
    // Get the first two digits
    long start_digits = card_number;
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    // Check AMEX: 15 digits, starts with 34 or 37
    if (length == 15 && (start_digits == 34 || start_digits == 37))
    {
        printf("AMEX\n");
    }
    // Check MASTERCARD: 16 digits, starts with 51-55
    else if (length == 16 && (start_digits >= 51 && start_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    // Check VISA: 13 or 16 digits, starts with 4
    else if ((length == 13 || length == 16) && (start_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
