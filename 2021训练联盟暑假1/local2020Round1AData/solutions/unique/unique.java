// Arup Guha
// 8/14/2020
// Solution to 2020 UCF Locals Round 1A Problem: Unique Values

import java.util.*;

public class unique {

	public static void main(String[] args) {
	
		// Read in the input.
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		int[] vals = new int[n];
		for (int i=0; i<n; i++)
			vals[i] = stdin.nextInt();
		
		// Store result and low ptr for sweep.
		long res = 0;
		int low = 0;
		
		// Stores current items in unique set.
		HashSet<Integer> curSet = new HashSet<Integer>();
		
		// Sweep high pointer of range.
		for (int high=0; high<n; high++) {
		
			// Keep on removing items until high can be added.
			while (curSet.contains(vals[high])) curSet.remove(vals[low++]);
			
			// Now, we can add this in.
			curSet.add(vals[high]);
			
			// Add in all contiguous subsequences ending at high.
			res = res + (high-low+1);
		}
		
		// Ta da!
		System.out.println(res);
	}
}