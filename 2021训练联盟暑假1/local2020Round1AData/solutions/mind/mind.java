// Arup Guha
// 8/6/2020
// Solution to 2020 UCF Locals Round 1A Problem: Game of Mind

import java.util.*;

public class mind {

	public static void main(String[] args) {
	
		// Get the input.
		Scanner stdin = new Scanner(System.in);
		int n = stdin.nextInt();
		
		// Make n queues.
		ArrayDeque<Integer>[] players = new ArrayDeque[n];
		for (int i=0; i<n; i++) players[i] = new ArrayDeque<Integer>();
		int total = 0;
		
		// Read in each.
		for (int i=0; i<n; i++) {
		
			// Read in each card for this player in order.
			int numCards = stdin.nextInt();	
			total += numCards;
			for (int j=0; j<numCards; j++)
				players[i].offer(stdin.nextInt());
		}
		
		// Find each best card.
		for (int i=0; i<total; i++) {
		
			// Will store who goes next.
			int next = -1;
			
			// Go through each hand.
			for (int j=0; j<n; j++) {
				if (players[j].size() == 0) continue;
				if (next == -1 || players[j].getFirst() < players[next].getFirst())
					next = j;
			}
			
			// Print the character, get rid of item.
			System.out.print( (char)('A'+next));
			players[next].pollFirst();
		}
		
		System.out.println();
	}
}