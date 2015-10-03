#include <iostream>
#include <string>

using namespace std;

//Declaration of functions
void hello(string name);
//Declaration of call-by-value function
int valueSquared(int a);
//Declaration of call-by-reference function
int refSquared(int& a);

int main() {
  int num = 8;
  int squareNum = 0;
  cout << "call-by-value example" << endl;
  squareNum = valueSquared(num);
  cout << "The square of " << num << " is " << squareNum << endl;

  cout << "call-by-reference example" << endl;
  squareNum = refSquared(num);
  cout << "The square of " << num << " is " << squareNum << endl;

  return 0;
}

//Definition of functions
void hello(string name){
  cout << "Hello " << name << endl;
}

//Definition of call-by-value functio
int valueSquared(int a){
  a = a * a;
  return a;
}

//Definition of call-by-reference functio
int refSquared(int& a){
  a = a * a;
  return a;
}
