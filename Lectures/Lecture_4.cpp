#include <iostream>
#include <string>

using namespace std;

int main() {
  //Loops
  //For Loop
  for(int i = 0; i < 10; i++){
    cout << "For: " << i << endl;
  }

  //While Loop
  int x = 100;
  while (x > 0){
    cout << "While: " << x << endl;
    x = x - 1;
  }

  //Do-While
  int input;
  do{
    cout << "Enter a positive number: ";
    cin >> input;
  } while(input > 0);
    cout << "You entered a non-positive number!" << endl;
}
