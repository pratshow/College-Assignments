/**
Show Pratoomratana
Homework #4
CS 2235 S21 - Data Structures and Algorithms
02/16/2021
Modified Scoreboard with new functions.
*/
//Scoreboard class for Homework 4
//Define program class
public class Scoreboard{
  //Instance Variables
  private int numEntries =0;
  private GameEntry[] board;

  //Constructor
  //Making an Empty Scoreboard
  public Scoreboard(int capacity){
    board = new GameEntry[capacity];
  }
  //Method
  public void add(GameEntry e){
    //Check to see if the score is high enough
    int newScore =e.getScore();
    //This assumes our array is already sorted from highest to lowest
    if(numEntries < board.length || newScore > board[numEntries-1].getScore()){
      if(numEntries < board.length){//No score needs to be dropped
        numEntries++;
      }
      int j = numEntries-1;
      while(j>0 && board[j-1].getScore()< newScore){
        board[j]=board[j-1];
        j--;
      }
      board[j]=e;
    }
  }
  //Remove Element Method
  //This method will return and remove the element
  public GameEntry remove(int i) throws IndexOutOfBoundsException{
    if(i <0 || i>=numEntries){
      throw new IndexOutOfBoundsException("Invalid index: " + i);
    }
    GameEntry temp = board[i];
    for(int j=i; j<numEntries-1; j++){
      board[j]=board[j+1];
    }
    board[numEntries-1]=null;
    numEntries--;
    return temp;
  }

  //Method to print the elements in the array
  //I changed "k<=19" to "k<=(numEntries-1)" otherwise a runtime
  //NullPointerException error after removing a element
  public void printBoard(){
    for(int k=0; k<=(numEntries-1); k++){//Iderates through all 20 players and prints
      System.out.println(board[k].toString());
    }
  }

  //Prints various stats about the scoreboard
  public void scoreBoardSummery(){
    System.out.println("Some stats of the scoreboard are:");
    System.out.println("The scoreboard shows the top " + numEntries + " players");
    // I made all of these methods within Scoreboard. The pdf said "Demonstrate that both methods work." So I hope this is okay.
    // I thought that it would be better form to make more methods rather than one long scoreBoardSummery method.
    System.out.println("The highest score is: " + highScore(board));
    System.out.println("The lowest score is: " + lowScore(board));
    System.out.println("The range of the scores is: " + (highScore(board) - lowScore(board)));
    System.out.println("The average of the scores is: " + getAverage(board));
  }

  // Need a parameter for these functions since I haven't constructed any GameEntry object in this class.
  // Compares each score in the array and returns the highest.
  public int highScore(GameEntry[] board){
    this.board = board;
    int highScore = 0; // Initalize both index and score to 0
    int curHSIndex = 0;
    while(curHSIndex < numEntries){//Iterate through the whole list
      if (board[curHSIndex].getScore() > highScore){
        highScore = board[curHSIndex].getScore();
      }
      curHSIndex++; //Next entry
    }
    return highScore;
  }

  //Same idea as high Score exept for the lowest score
  public int lowScore(GameEntry[] board){
    this.board = board;
    int lowScore = 1000; // Initalize lowScore as 1000 since 1000 is the highest the score can be.
    int curLSIndex = 0;
    while(curLSIndex < numEntries){
      if (board[curLSIndex].getScore() < lowScore){
        lowScore = board[curLSIndex].getScore();
      }
      curLSIndex++;
    }
    return lowScore;
  }

  //Return the average
  public double getAverage(GameEntry[] board) {
    this.board = board;
    int curIndex = 0;
    int total = 0;
    while(curIndex < numEntries){
      total = board[curIndex].getScore() + total; //Add together every score
      curIndex++;
    }
    // Got to type cast this double to make a decimal(Thanks stackoverflow for telling me about typcasting!)
    double average = (double) total/numEntries;
    return average;
  }

}
