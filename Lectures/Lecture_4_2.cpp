#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  //Using cmath library
  cout << "sqrt(5.0) = " << sqrt(5.0) << endl;
  cout << "pow(2.0,3.0) = " << pow(2.0, 3.0) << endl;

  //Generating random numbers
  cout << "Time: " << time(0);
  srand(time(0)); /* sets the seed for random numbers, otherwise rand will return the same value*/
  cout << rand()%40 << endl;

  return 0;
}
