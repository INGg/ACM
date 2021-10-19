
/* *****
   
   2020 UCF Local Contest (Round 1A) -- bills

   ***** */

#include <stdio.h>

int all_denom[6] = {1, 5, 10, 20, 50, 100};

int max_denom;
int max_total_amount;

void process_one_denom(int);

/* ************************************************************ */

int main()
{
   int k, d;

   max_total_amount = -1;
   for (d = 0;  d <= 5;  ++d)
      process_one_denom(all_denom[d]);

   printf("%d\n", max_denom);

   return(0);

}/* end main() */

/* ************************************************************ */

void process_one_denom(int curr_denom)
{
   int num_of_bills, new_total;

   scanf("%d", &num_of_bills);

   new_total = curr_denom * num_of_bills;

   // printf("[%d * %d] = %d \n", curr_denom, num_of_bills, new_total);

   if (new_total >= max_total_amount)
     {
      max_total_amount = new_total;
      max_denom = curr_denom;
     }

}/* end process_one_denom() */

/* ************************************************************ */

