import java.util.Scanner;

public class Temperature {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    double fahrenheit;
    double celsius;
    char measure;

    System.out.print("celsius or fahrenheit (c/f): ");
    measure = input.next().charAt(0);

    if (measure == 'c') {
      System.out.print("Enter deg in celsius: ");

      celsius = input.nextDouble();
      fahrenheit = 9.0 / 5.0 * celsius + 32;

      System.out.printf("Fahrenheit: %.2f%n", fahrenheit);
    } else if (measure == 'f') {
      System.out.print("Enter deg in fahrenheit: ");

      fahrenheit = input.nextDouble();
      celsius = 5.0 / 9.0 * ( fahrenheit - 32 );

      System.out.printf("Celsius: %.2f%n", celsius);
    } else {
      System.out.println("Wrong input!");
    }

    System.exit(0);
  }
}