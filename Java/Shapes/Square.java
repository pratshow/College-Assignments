/**
Show Pratoomratana
Homework #3
CS 2235 S21 - Data Structures and Algorithms
02/04/2021
Square subclass
*/

//Square subclass; Shape is the Parent class
public class Square extends Shape{
  //Instance variables for both points
  protected Point pointOne;
  protected Point pointTwo;

  //Constructer
  public Square(String name, Point pointOne, Point pointTwo){
    super(name);
    this.pointOne = pointOne;
    this.pointTwo = pointTwo;
  }

  //Getter functions
  public Point getPointOne(){return pointOne;}
  public Point getPointTwo(){return pointTwo;}

  //Funtion to calculate the length of the Square
  public Integer getLength(){
    //absolute value for always positive since it's a length.
    return Math.abs(pointOne.getX() - pointTwo.getX());
  }

  //Calculate height
  public Integer getHeight(){
    return Math.abs(pointOne.getY() - pointTwo.getY());
  }

  //Calculate area
  public Integer getArea(){
    return (getHeight() * getLength());
  }

  //Calculate Perimeter
  public Integer getPerimeter(){
    return (getLength()*2) + (getHeight()*2);
  }
}
