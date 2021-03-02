/**
Show Pratoomratana
Homework #3
CS 2235 S21 - Data Structures and Algorithms
02/04/2021
Main file
*/

//Define program class
public class testMain{
  //Main function
  public static void main(String[] args){
    //Making point objects
    Point firstPoint = new Point(4, 8);
    Point secondPoint = new Point();

    //Printing the coordinates of the points
    System.out.println("The coordinate of firstPoint is: (" + firstPoint.getX() + "," + firstPoint.getY() + ")");
    System.out.println("The coordinate of secondPoint: (" + secondPoint.getX() + "," + secondPoint.getY() + ")");

    //Demonstrating the set functions
    secondPoint.setX(15);
    secondPoint.setY(16);
    System.out.println("The coordinate of secondPoint changed to: (" + secondPoint.getX() + "," + secondPoint.getY() + ")");

    //New line
    System.out.println("");

    //Square object
    Square mySquare = new Square("mySquare", firstPoint, secondPoint);
    //Circle's characteristics
    System.out.println("Your squares' characteristics are:");
    System.out.println("Name: " + mySquare.getName());
    //Bit long print statement but it looks nice when printed
    System.out.println("Points: (" + mySquare.getPointOne().getX() + "," + mySquare.getPointOne().getY() +
    ") (" + mySquare.getPointTwo().getX() + "," + mySquare.getPointTwo().getY() + ")");
    //Calculation functions using the square
    System.out.println("Length: " + mySquare.getLength());
    System.out.println("Height: " + mySquare.getHeight());
    System.out.println("Area: " + mySquare.getArea());
    System.out.println("Perimeter: " + mySquare.getPerimeter());

    //New line
    System.out.println("");

    //Making a circle object
    Circle myCircle = new Circle("I'm a circle!", firstPoint, 1);
    //Circle's characteristics
    System.out.println("Your circles' characteristics are:");
    System.out.println("Name: " + myCircle.getName());
    System.out.println("Center: (" + myCircle.getCenter().getX() + "," + myCircle.getCenter().getY() + ")");
    System.out.println("Radius: " + myCircle.getRadius());
    System.out.println("Area: " + myCircle.getArea());
    System.out.println("Circumference: " + myCircle.getCircumference());
  }
}
