// Arup Guha
// 8/25/2020
// Solution to 2020 UCF Locals Round 1A Problem: Median Inversion String

import java.util.*;

public class median_arup {

	public static int n;
	public static int inv;
	public static long[][][] memo;
	
	public static void main(String[] args) {
	
		Scanner stdin = new Scanner(System.in);
		n = stdin.nextInt();
		inv = stdin.nextInt();
		
		// Set up memo table.
		memo = new long[n+1][n+1][inv+1];
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				Arrays.fill(memo[i][j], -1);
				
		// Get memo table filled. 
		// Note: memo[n][numb][inv] stores the number of strings of length n,
		//       with numb B's and exactly inv inversions.
		long numAns = 0;
		for (int numb=0; numb<=n; numb++) numAns += f(n, numb, inv);

		// We always want to print this rank.
		go(0, 0, inv, (numAns-1)/2);
		
		// If it's even, we also want this one.
		if (numAns%2 == 0)
			go(0, 0, inv, numAns/2);
	}

	// Returns the number of strings of length n with numb Bs and exactly inv inversions.
	public static long f(int n, int numb, int inv) {
		
		// Can't do this.
		if (inv < 0 || numb < 0) return 0;
	
		// No letters left to place, so either this is valid or invalid.
		if (n == 0) return numb == 0 && inv == 0 ? 1 : 0;
		
		// Did this before.
		if (memo[n][numb][inv] != -1) return memo[n][numb][inv];
	
		// Number of ways to get this many inversions adding a B at the end.
		long addB = f(n-1, numb-1, inv);
		
		// Number of ways to get this many inversions adding an A at the end.
		long addA = inv >= numb ? f(n-1, numb, inv-numb) : 0;
		
		// Ta da!
		return memo[n][numb][inv] = addA + addB;
	}
	
	// Prints out the answer for rank, given that we've already printed out k characters, of which
	// bCnt are Bs, and we need inv more inversions.
	public static void go(int k, int bCnt, int inv, long rank) {
		
		// Done!
		if (k == n) {
			System.out.println();
			return;
		}
		
		// See if we have enough items placing an A here.
		long placeA = 0;
		
		// We just have to try every possible number of Bs for the future slots.
		// If we have some As in future slots, we have to account for the inversions caused
		// by the bCnt B's we've already placed and those future As. The first -bCnt is for the
		// current A that is getting placed. I could do math to simplify, but I wanted to show
		// my thinking here.
		for (int mybs = 0; mybs<=n-k-1; mybs++)
			placeA += f(n-k-1, mybs, inv-bCnt-(n-k-1-mybs)*bCnt);
			
		// We have enough items that have an A in the place to print it, then we want the same
		// exact rank of what's left.
		if (placeA > rank) {
			System.out.print("A");
			go(k+1, bCnt, inv-bCnt, rank);
		}
		
		// We must place a B. Then we want a new updated rank.
		else {
			System.out.print("B");
			go(k+1, bCnt+1, inv, rank - placeA);
		}
	}
}