/*
  Output: 67 83 67 73 32 49 48 54 48 85
*/

#include <iostream>

using namespace std;

int main() {
  //Declarating of char array containing word
  char word[] = {'C','S','C','I',' ','1','0','6','0','U'};

  //Get the number of elements in the array;
  int numChars = sizeof(word)/sizeof(word[0]);

  //Loop to go through the array
  for(int i = 0; i < numChars; i++)
  {
    //Outputting the ASCII value of the chars in the array
    cout << (int)word[i] << " ";
  }

  cout << endl;
}
