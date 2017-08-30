package eagles;

public class ArithmeticTest {     // Save as "ArithmeticTest.java"
	   public static void main(String[] args) {
	      int number1 = 98; // Declare an int variable number1 and initialize it to 98
	      int number2 = 5;  // Declare an int variable number2 and initialize it to 5
	      int number3 = 77;
	      int newsum = number1*31 + number2*17 + number3*87;
	      int sum, difference, product, quotient, remainder;  // Declare 5 int variables to hold results
	   
	      // Perform arithmetic Operations
	      sum = number1 + number2 + number3;
	      difference = number1 - number2;
	      product = number1 * number2 * number3;
	      quotient = number1 / number2;
	      remainder = number1 % number2;
	  
	      // Print results
	      System.out.println("The sum, difference, product, quotient and remainder of " + number1 + " and " + number2 + " are " + sum + " , " + difference + " , " + product + " , " + quotient + " and " + remainder);  // Print description
	      System.out.println("Sum of 31 times number1 and 17 times of number2 and 87 times of number3 is........" + newsum);
	   
	      ++number1;  // Increment the value stored in the variable "number1" by 1
	                  // Same as "number1 = number1 + 1"
	      --number2;  // Decrement the value stored in the variable "number2" by 1
	                  // Same as "number2 = number2 - 1"
	      System.out.println("number1 after increment is " + number1);  // Print description and variable
	      System.out.println("number2 after decrement is " + number2);
	      quotient = number1 / number2; 
	      System.out.println("The new quotient of " + number1 + " and " + number2 
	            + " is " + quotient);
	   }
	}