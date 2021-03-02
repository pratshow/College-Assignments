/**
Show Pratoomratana
Homework #5
CS 2235 S21 - Data Structures and Algorithms
02/23/2021
Main program to populate the LL and use print fucntions.
*/
import java.util.Random;

// Main program class
public class Main{
  //main to run
  public static void main(String[] args){
    //New SinglyLinkedList for the top 20
    SinglyLinkedList topScores = new SinglyLinkedList();
    //Creates 20 players with scores and adds it to the topScores
    for(int i=0; i <= 19; i++) {
      String player = ("player " + i); //player 0, player 1, ... player i
      Random ranScore = new Random(); // Random object
      int newScore = ranScore.nextInt(1000);
      GameEntry newEntry = new GameEntry(player, newScore);
      topScores.addLast(newEntry);
    }
      System.out.println("Singly Linked List scoreboard:");
      topScores.printBoard();
      topScores.scoreBoardSummery();


      // Line to make it clear where the DLL starts
      System.out.println("-----------------------------------------------");
      //Same thing but with the DoublyLinkedList
      DoublyLinkedList topScoresDLL = new DoublyLinkedList();
      for(int i=0; i <= 19; i++){
        String player = ("player " + i); //player 0, player 1, ... player i
        Random ranScore = new Random(); // Random object
        int newScore = ranScore.nextInt(1000);
        GameEntry newEntry = new GameEntry(player, newScore);
        topScoresDLL.addLast(newEntry);
      }
      System.out.println("Doubly Linked List scoreboard:");
      topScoresDLL.printBoardDLL();
      topScoresDLL.scoreBoardSummeryDLL();
    }
  }
