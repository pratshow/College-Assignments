/**
Show Pratoomratana
Homework #5
CS 2235 S21 - Data Structures and Algorithms
02/23/2021
Modified SLL class from lecture
*/

public class SinglyLinkedList<E>{
  //Nested class
  private static class Node<E>{
    //Instane Varaibles
    private E element;
    private Node<E> next;
    //Constructor
    public Node(E e, Node<E> n){
      element=e;
      next=n;
    }
    //Methods
    public E getElement(){return element;}
    public Node<E> getNext(){return next;}
    public void setNext(Node<E> n){next=n;}
  }
  //End Nested Node class
  //Instance Variables for the SLL class
  private Node<E> head =null;
  private Node<E> tail =null;
  private int size =0;

  //Constructor
  public SinglyLinkedList(){}//Just create empty SLL

  //Method for the Singly Linked List class
  //Access Methods
  public int getSize(){return size;}
  public boolean isEmpty(){return size==0;}
  //First method returns the element at the head of the list
  public E first(){
    if(isEmpty()) {return null;}
    return head.getElement();
  }
  //Last method: return the element at the tail of list
  public E last(){
    if(isEmpty()){ return null;}
    return tail.getElement();
  }
  //Update methods
  //addFirst Method: add new element as the head of the SLL
  public void addFirst(E e){
    head = new Node<>(e, head);
    if(size==0){
      tail=head;
    }
    size++;
  }
  //addLast Method: add new element as the tail of SLL
  public void addLast(E e){
    Node<E> newest = new Node<>(e, null);
    if(isEmpty()){
      head=newest;
    }
    else{
      tail.setNext(newest);
    }
    tail= newest;
    size++;
  }
  //removeFirst method: This return and remove the head element of the SLL
  public E removeFirst(){
    if(isEmpty()){return null;}
    E answer = head.getElement();
    head= head.getNext();
    size--;
    if(size==0){
      tail=null;
    }
    return answer;
  }

 //Prints all the element in the SLL
  public void printBoard(){
    Node<E> curE = head;
    for (int i = 0; i < (getSize() - 1); i++){// Iderate through whole LL
      System.out.println(curE.getElement());
      curE = curE.getNext();
    }
  }

  //Prints various stats about the scoreboard
  public void scoreBoardSummery(){
    System.out.println("Some stats of the scoreboard are:");
    System.out.println("The scoreboard shows the top " + getSize() + " players");
    System.out.println("The highest score is: " + highScore());
    System.out.println("The lowest score is: " + lowScore());
    System.out.println("The range of the scores is: " + (highScore() - lowScore()));
    System.out.println("The average Score is: "+ averageScore());
  }

  //Iderates throught the LL and return the highest score
  public int highScore(){
    // Instance variables for method
    Node<E> curE = head;
    GameEntry curGameEntry;
    int curScore;
    int highScore = 0;
    for (int i = 0; i < (getSize() - 1); i++){
      curGameEntry = (GameEntry) curE.getElement(); // Changing from generic to GameEntry
      curScore = (int) curGameEntry.getScore(); // Then from GameEntry to int
      if (curScore > highScore) {
        highScore = curScore;
      }
      curE = curE.getNext();
    }
    return highScore;
  }

  // Pretty much identical to highScore but for the lowest score.
  public int lowScore(){
    Node<E> curE = head;
    GameEntry curGameEntry;
    int curScore;
    int lowestScore = 1000;
    for (int i = 0; i < (getSize() - 1); i++){
      curGameEntry = (GameEntry) curE.getElement();
      curScore = (int) curGameEntry.getScore();
      if (curScore < lowestScore) {
        lowestScore = curScore;
      }
      curE = curE.getNext();
    }
    return lowestScore;
  }

  // Returns the average score. Again pretty similar to high/lowScore except I increment and divide
  public double averageScore(){
    Node<E> curE = head;
    GameEntry curGameEntry;
    int totalScore = 0;
    int curScore;
    for (int i=0; i < (getSize() - 1); i++) {
      curGameEntry = (GameEntry) curE.getElement();
      curScore = (int) curGameEntry.getScore();
      totalScore += curScore;
    }
    double average = (double) totalScore/getSize();
    return average;
  }
}
