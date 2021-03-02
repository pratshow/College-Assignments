/**
Show Pratoomratana
Homework #5
CS 2235 S21 - Data Structures and Algorithms
02/23/2021
DLL class, pretty much the same as the book but with some new functions
for printing the players and computing scores.
*/

public class DoublyLinkedList<E>{
  //Nested class
  private static class Node<E>{
    // Instance Variables
    private E element;
    private Node<E> next;
    private Node<E> prev;
    //Constructor
    public Node(E e, Node<E> n, Node<E> p){
      element = e;
      next = n;
      prev = p;
    }
    //Methods
    public E getElement(){return element;}
    public Node<E> getNext(){return next;}
    public Node<E> getPrev(){return prev;}
    public void setNext(Node<E> n){next=n;}
    public void setPrev(Node<E> p){prev = p;}
  }

  //Instance variables for DLL class
  private Node<E> header; //Sentinals at the front and back of LL.
  private Node<E> trailer;
  private int size = 0;

  //Constructor
  public DoublyLinkedList(){
    header = new Node<>(null, null, null);  //Setting header and trailer
    trailer = new Node<>(null, null, header);
    header.setNext(trailer);
  }

  //Methods
  //Access Methods
  public int getSize(){return size;}
  public boolean isEmpty(){return size == 0;}

  //Retruns the head of DLL
  public E First(){
    if(isEmpty()){return null;}
    return header.getNext().getElement(); // Element after header sentinal
  }
  //Returns tail
  public E Last(){
    if(isEmpty()){return null;}
    return trailer.getPrev().getElement(); // Element before trailer sentinal
  }

  // addition methods;
  // Add element to head of list
  public void addFirst(E e){
    addBetween(e, header.getNext(), header);
  }
  // Adds element to tail of list
  public void addLast(E e){
    addBetween(e, trailer, trailer.getPrev());
  }

  // Remove functions
  // Removes first element
  public E removeFirst(){
    if(isEmpty()){return null;}
    return remove(header.getNext());
  }
  //Removes last element
  public E removeLast(){
    if(isEmpty()){return null;}
    return remove(trailer.getPrev());
  }

  //Adds a elements between 2 nodes
  private void addBetween(E e, Node<E> next, Node<E> previous) {
    // Make the new node with the current, next, and previous nodes
    Node<E> newest = new Node<>(e, next, previous);
    next.setPrev(newest); // Change the references
    previous.setNext(newest);
    size++;
  }

  // Removes the given element form the DLL
  private E remove(Node<E> node) {
    Node<E> previous = node.getPrev();
    Node<E> next = node.getNext();
    previous.setNext(next);
    next.setPrev(previous);
    size--;
    return node.getElement();
  }

  //Prints all the element in the SLL
   public void printBoardDLL(){
     Node<E> curE = header.getNext();
     for (int i = 0; i < (getSize()); i++){// Iderate through whole LL
       System.out.println(curE.getElement());
       curE = curE.getNext();
     }
   }

   //Prints various stats about the scoreboard
   public void scoreBoardSummeryDLL(){
     System.out.println("Some stats of the scoreboard are:");
     System.out.println("The scoreboard shows the top " + getSize() + " players");
     System.out.println("The highest score is: " + highScoreDLL());
     System.out.println("The lowest score is: " + lowScoreDLL());
     System.out.println("The range of the scores is: " + (highScoreDLL() - lowScoreDLL()));
     System.out.println("The average Score is: "+ averageScoreDLL());
   }

  //Iderates throught the LL and return the highest score
  public int highScoreDLL(){
    // Instance variables for method
    Node<E> curE = header.getNext();
    GameEntry curGameEntry;
    int curScore;
    int highScore = 0;
    for (int i = 0; i < (getSize()); i++){
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
  public int lowScoreDLL(){
    Node<E> curE = header.getNext();
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
  public double averageScoreDLL(){
    Node<E> curE = header.getNext();
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
