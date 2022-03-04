/* Chapter 2 of Java How to Program: Fourth Edition
   Debugging Problem */
import java.util.Scanner;

public class Arithmetic {
   static public void main(String[] args)
   {
     
      int num2, num3, sum, product;
      double average;
      Scanner input = new Scanner(System.in);

      System.out.print("Enter first integer:");
      num1  =  input.nextInt();
      System.out.print("Enter second integer:");
      num2  = input.nextInt(  );
      System.out.print("Enter third integer:");
      num3 = input.nextInt(  );
      
      sum = num1 + num2 + num3;
      product = num1 * num2 * num3;
      average = ( num1 + num2 + num3 ) / 3;
      
      System.out.print( "The sum is " + sum + 
         "\nThe product is " + product +  "\nThe average is " 
          + average);
   }
} // end class Arithmetic

