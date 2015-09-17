#include <iostream>
#include <string>

using namespace std;

int main() {
  //Doubles
  double x = 2.0;
  cout << x << endl;

  //Type Casting
  //Integer to float
  int y1 = 2;
  int y2 = 3;

  //Wrong!
  float x1 = y1/y2;
  float x2 = float(y1)/y2;
  //May not work on all compilers
  float x3 = (float)y1/y2;

  cout << "y1/y2\t" << x1 <<endl;
  cout << "float(y1)/y2\t" << x2 <<endl;
  cout << "(float)y1/y2\t" << x3 <<endl;

  //Works on all compilers
  float x4 = static_cast<float>(y1)/y2;
  cout << "static_cast<float>y1/y2\t" << x4 <<endl;

  int c1 = 82;
  int c2 = 32;
  int c3 = 23;
  int c4 = 1000;
  
  return 0;
}
