// Arup Guha
// 8/19/2020
// Solution to 2020 UCF Locals Round 1A Problem: Game of Mind

#include <stdio.h>

int main(void) {

    // Get number of players.
    int n;
    scanf("%d", &n);

    // Store cards here.
    int cards[6][9];

    // store # of cards here.
    int numcards[6];
    for (int i=0; i<6; i++) numcards[i] = 0;
    int total = 0;

    // Read data.
    for (int i=0; i<n; i++) {
        scanf("%d", &numcards[i]);
        total += numcards[i];
        for (int j=0; j<numcards[i]; j++)
            scanf("%d", & cards[i][j]);
    }

    // Store which card will play next in each hand.
    int index[6];
    for (int i=0; i<6; i++) index[i] = 0;

    // Do it!
    for (int i=0; i<total; i++) {

        int play = -1;

        // Go through each hand.
        for (int j=0; j<n; j++) {

            // Skip hands that are done.
            if (index[j] == numcards[j]) continue;

            // Card from player j is the best.
            if (play == -1 || cards[j][index[j]] < cards[play][index[play]])
                play = j;
        }

        // Print it.
        printf("%c", 'A'+play);

        // Update who we get this card from.
        index[play]++;
    }
    printf("\n");

    return 0;
}
