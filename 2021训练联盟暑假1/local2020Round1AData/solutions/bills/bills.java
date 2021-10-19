import java.util.*;

public class bills {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int [] bills = {1, 5, 10, 20, 50, 100};

        // total amount for $1 bills
        int amount = in.nextInt();
        // current index
        int index = 0;

        // starts with $5 as $1 is used above
        for (int i = 1; i < 6; i++) {
            // total amount for the next bill
            int nextAmount = in.nextInt() * bills[i];

            // set the current index if the next amount is 
            // equal or greater than current amount
            if(amount <= nextAmount) {
                amount = nextAmount;
                index = i;
            } 
        }

        System.out.println(bills[index]);
    }
}