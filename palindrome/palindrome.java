/*
    Challenge: Ask user for input of a potential palindrome and print whether or not it is a palindrome.
*/
import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {

        String palindrome = "";

        Scanner input = new Scanner(System.in);

        if(args.length == 0) {
            System.out.print("Please enter a potential palindrome: ");
            palindrome = input.nextLine();
        } else {
            for(int i = 0; i < args.length; i++) {
                palindrome += args[i];
            }
        }

        //Replace the spaces with no space using regex
        String combinedString = palindrome.replaceAll("\\s","");

        int size = combinedString.length();

        int j = size - 1;

        for(int i = 0; i < (size / 2); i ++) {
            if(combinedString.charAt(i) != combinedString.charAt(j)) {
                System.out.println("String is not a Palindrome");
                System.exit(1);
            } else {
                j--;
            }
        }

        System.out.println("String is a Palindrome");
    }
}
