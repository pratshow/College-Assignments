/**
Show Pratoomratana
Homework #3
CS 2235 S21 - Data Structures and Algorithms
02/04/2021
Circle subclass
*/

//Circle subclass; Shape is parent class
public class Circle extends Shape{
  //Instance variables
  protected Point center;
  protected Integer radius;

  //Constructer
  public Circle(String name, Point center, Integer radius){
    super(name);
    this.center = center;
    this.radius = radius;
  }

  //Getter function
  public Point getCenter(){return center;}
  public Integer getRadius(){return radius;}

  //calculates the area of the circle
  public double getArea(){
    double rad = getRadius();
    return (3.14 * (rad * rad));
  }

  //calculates the circumference of the circle
  public double getCircumference(){
    double rad = getRadius();
    return (2 * 3.14 * rad);
  }
}
