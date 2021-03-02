/**
Show Pratoomratana
Homework #4
CS 2235 S21 - Data Structures and Algorithms
02/16/2021
Main program
*/
import java.util.Random;

// Main program class
public class Main{
  //main to run
  public static void main(String[] args){
    //New scoreboard class for the top 20
    Scoreboard topScores = new Scoreboard(20);

    //Creates 20 players with scores and adds it to the topScores array
    for(int i=0; i <= 19; i++) {
      String player = ("player " + i); //player 0, player 1, ... player i
      Random ranScore = new Random(); // Random object
      int newScore = ranScore.nextInt(1000);
      GameEntry newEntry = new GameEntry(player, newScore);
      topScores.add(newEntry);
      }

      //Simply prints the board and summary
      topScores.printBoard();
      topScores.scoreBoardSummery();

      //New line
      System.out.println();

      //Removes second entry and prints it all again
      topScores.remove(1);
      System.out.println("Removed second place.");
      topScores.printBoard();
      topScores.scoreBoardSummery();
    }
  }
