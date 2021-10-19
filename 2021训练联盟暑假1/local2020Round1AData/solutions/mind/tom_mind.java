import java.util.*;

public class mind {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        char [] players = {'A', 'B', 'C', 'D', 'E', 'F'};
        // auto key ordering
        TreeMap<Integer, Character> results = new TreeMap<>();

        int numPlayers = in.nextInt();

        for (int i = 0; i < numPlayers; i++) {
            int numCards = in.nextInt();

            for (int j = 0; j < numCards; j++) {
                // add card number and player pair to ordered map
                results.put(in.nextInt(), players[i]);
            }
        }

        // print output
        for (Map.Entry<Integer, Character> entry : results.entrySet()) {
            System.out.print(entry.getValue());
        }

        System.out.println();
    }
}
