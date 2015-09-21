#include <iostream>
#include <string>

using namespace std;

int main() {

  //Swapping
  int x = 5;
  int y = 3;

  cout << "x is: " << x << " y is: " << y << endl;
  x = x + y;
  y = x - y;
  x = x - y;
  cout << "x is: " << x << " y is: " << y << endl;

  //Boolean operators
  //x is equal to y
  //y is greater than x and less than z
  //x is less than y and y is less than z
  //Y is greater than z and y does not equal x
  //Not when x is greater than 6 or when x is less than or equal to 2

  //Branching
  bool test = true;
  x = 4;
  y = 3;
  bool test2 = false;

  if(x < y){
    cout << "X is less than y!" << endl;
    if (test) {
      cout << "Test is " << true << endl;
    }
  }
  else if(x > y){
    cout << "X is greater than y!" << endl;
  }
  else{
    cout << "X is equal to y!" << endl;
  }

  //Switch Statment
  char mark = 'A';
  cout << "Enter your course mark: ";
  cin >> mark;

  switch(mark){
    case 'A':
    case 'B':
      cout << "Great work."
           << endl;
      break;
    case 'C':
      cout << "Good work."
           << endl;
      break;
    case 'D':
    case 'F':
      cout << "Please see your professor after class."
           << endl;
      break;
    default:
      cout << "You did not enter a grade properly. "
           << "Are you sure you didn't make a mistake?"
           << endl;
      break;
  }
  
  return 0;
}
