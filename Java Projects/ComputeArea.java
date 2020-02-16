import java.util.Scanner;

public class ComputeArea {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        final double PI = 3.14159;
		
        System.out.print("Enter a radius: ");
		double radius = input.nextDouble();
        double area = radius * radius * 3.14159;
			 
        System.out.println("The area of a circle with radius " + radius + " is " + area);
    }
}