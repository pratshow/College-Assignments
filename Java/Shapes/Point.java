/**
Show Pratoomratana
Homework #3
CS 2235 S21 - Data Structures and Algorithms
02/04/2021
Main file
Point.java file
*/

//Main class
public class Point{
  //Create a object x and y to make a Point.

  //Variables
  protected Integer x;
  protected Integer y;

  //User definded constructer
  public Point(Integer x, Integer y){
    this.x = x;
    this.y = y;
  }

  //Default constructer
  public Point(){
    this.x = 0;
    this.y = 0;
  }

  //Getter functions
  public Integer getX(){return x;}
  public Integer getY(){return y;}

  //Setter functions
  public void setX(Integer x){this.x = x;}
  public void setY(Integer y){this.y = y;}
}
