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

		//Get the number of characters entered in the palindrome
		int size = combinedString.length();

		//Integer that will start at the back of the string for comparison
		int j = size - 1;

		//Loop through the string
		for(int i = 0; i < (size / 2); i ++) {

			//If the two characters do not equal each other
			if(combinedString.charAt(i) != combinedString.charAt(j)) {
				//Print out not a palindrome and exit the program
				System.out.println("String is not a Palindrome");
				System.exit(1);
			} else {
				//Bring J closer to the center
				j--;
			}
		}

		//Print out string is a palindrome if code gets through loop
		System.out.println("String is a Palindrome");
	}
}
