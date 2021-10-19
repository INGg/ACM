// Arup Guha
// 8/6/2020
// Solution to 2020 UCF Locals Round 1A Problem: Sum of a Function

import java.util.*;

public class sumfunc {

	public static void main(String[] args) {
	
		// Get the input.
		Scanner stdin = new Scanner(System.in);
		long s = stdin.nextLong();
		long e = stdin.nextLong();
		int k = stdin.nextInt();
		
		// Set up array for prime sieve.
		int size = (int)(e-s+1);
		boolean[] sieve = new boolean[size];
	
		// Probably okay if this is an int...
		long sum = 0;
		
		// Stores current divisor and # of terms seen so far.
		int div = 2;
		int numT = 0;
		
		// Keep going till we have enough terms.
		while (numT < k) {
		
			// First index that matters.
			long start = (int)(s%div);
			if (start != 0)
				start = (div-start);
				
			// Just a straight prime sieve. Mark off new terms divisible by div.
			int tempTerms = 0;
			for (long i=start; i<sieve.length; i+= div) {
				if (!sieve[(int)i]) {
					sieve[(int)i] = true;
					tempTerms++;
				}
			}
			
			// The number of terms we will use here.
			tempTerms = Math.min(tempTerms, k-numT); 
				
			// Update all relevant terms.	
			sum += ((long)tempTerms)*div;
			numT += tempTerms;
			div++;
		}
		
		// Ta da!
		System.out.println(sum);
	}
}