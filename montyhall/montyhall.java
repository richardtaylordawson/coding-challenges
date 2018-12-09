import java.util.*;

class MontyHall {
    public static void main(String[] args) {
        Random rn = new Random();

        int games = 0;
        double stayChoiceWins = 0;
        double switchChoiceWins = 0;
        double stayPercent = 0.0;
        double switchPercent = 0.0;

        //Play the game 100,000 times
        do {
            //Randomly Choose the Winning Door
            int door = rn.nextInt(3);

            //Randomly Choose the Contestant Guess
            int choice = rn.nextInt(3);

            //If you choose the correct door, then the stay wins
            //increment instead of the switch wins
            //Otherwise, you will always win by switching
            if(door == choice) {
                stayChoiceWins++;
            } else {
                switchChoiceWins++;
            }

            //Increment Games to Break Loop
            games++;

        } while (games < 100000);

        stayPercent = (stayChoiceWins/100000) * 100;
        switchPercent = (switchChoiceWins/100000) * 100;

        System.out.println("Monty Hall Game Results for 100,000 games:");
        System.out.println("Stay Wins: " + stayChoiceWins + " Stay Percentage: " + stayPercent);
        System.out.println("Switch Wins: " + switchChoiceWins + " Switch Percentage: " + switchPercent);
    }
}
