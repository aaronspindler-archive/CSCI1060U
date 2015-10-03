#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  //Variables
  int roundNum = 1;
  int numLimit = 5;

  int numTries = 5;

  int guessedNum = 0;
  int randomNum = 0;

  //Print game header
  cout << "----------------------------------" << endl;
  cout << "Welcome to Guess That Number!" << endl;
  cout << "----------------------------------" << endl;
  cout << endl;

  //Infinite loop to run the games infinite amout of times
  while(true){
    numTries = 5;
    cout << "Round " << roundNum << endl;

    //Seeding the random number generator with the current time
    srand(time(NULL));
    //Getting a random number
    randomNum = rand()%numLimit;

	//Allows 5 tries
    for(int i = 0; i < 5; i++){
      cout << "Guess a number less than " << numLimit << ": ";
	  //Asking for input from the user for their guessed number
      cin >> guessedNum;

	  /*
		If their guessed number matches the random number
		output that they are correct and break the for loop
	  */
      if(guessedNum == randomNum){
        cout << "Correct! The number was " << guessedNum << endl;
        break;
      }
      else{
		//Otherwise reduce their tries by 1
        numTries--;
        if(numTries > 0){
          cout << "Incorrect! try again (" << numTries << " tries remaining)"
          << endl;
        }
        else{
          cout << "Incorrect! Out of guesses :(" << endl;
          cout << endl;
          cout << "Game Over!!!";
          cout << endl;
        }
      }
    }

	//If they run out of tries break the while loop at the beginning and end the game.
    if(numTries <= 0)
    {
      break;
    }
    roundNum++;
    numLimit = numLimit * 2;

    cout << endl;
  }
  return 0;
}
