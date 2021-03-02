/**
Show Pratoomratana
Homework #3
CS 2235 S21 - Data Structures and Algorithms
02/04/2021
Shape file
*/

//Main class
public class Shape{
  //Variable
  protected String name;

  //Constructer takes a String name
  public Shape(String name){
    this.name = name;
  }

  //Getter and setter methods
  public String getName(){return name;}
  public void setName(String name){this.name = name;}
}
