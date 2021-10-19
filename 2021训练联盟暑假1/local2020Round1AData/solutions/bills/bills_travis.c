
#include <stdio.h>

// macro for reading in an integer
#define in32(x) scanf("%d", &x)

// macro for printing out an integer (on it's own line)
#define out32(x) printf("%d\n", x)

// The main function
int main() 
{
    // Variable that will store the amount of some bill type
    int a;

    // Array that stores the values of the bills
    int b[6] = {1, 5, 10, 20, 50, 100};

    // Variable to store the value of a case
    int value;

    // Variable to store the maximum value of a case
    int max = 0;

    // Variable to store the answer
    int ans = 1;

    // Loop through and read in the number of bills in each brief case
    for (int i = 0; i < 6; i++) 
    {
        // Read in the number of bills
        in32(a);

        // Update the answers by the product of the bills and the value
        value = a * b[i];

        // check if we found a better answer
        if (max <= value) {
            max = value;
            ans = b[i];
        }
    }

    // Print out the total value
    out32(ans);

    // Return a success
    return 0;
}
