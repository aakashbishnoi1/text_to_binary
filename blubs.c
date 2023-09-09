#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // asking for user input
    string message = get_string("Message: ");
    // initialising all the variables we might need
    int bit = 0;
    char c;
    int bits[8];

    // itreting through the string to get char ascii values
    for (int i = 0; i < strlen(message); i++)
    {
        //converting the user input in char to get ascii value
        c = message[i];

        //gives us 8 bits of binary
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            // remainder to get 1/0 for binary
            int modu = c % 2;
            //divind by 2 for 8 times to get 8 bits of 0's and 1's
            c = c / 2.0;
            // asigning values to bit accordingly
            if (modu >= 0 && modu < 1)
            {
                bit = 0;
            }
            else if (modu >= 1 && modu < 2)
            {
                bit = 1;
            }
            // storing all the bits in a array
            bits[j] = modu;

        }

        // reversing the array
        for (int r = 7; r >= 0; r--)
        {
            print_bulb(bits[r]);
        }

        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

