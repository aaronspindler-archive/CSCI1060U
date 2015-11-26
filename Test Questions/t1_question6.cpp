#include <iostream>
#include <string>

using namespace std;

bool checkIfEqual(string a, string b);

int main(){
  string stringA, stringB;
  cout << "Enter a string: ";
  cin >> stringA;

  cout << "Enter another string: ";
  cin >> stringB;

  cout << checkIfEqual(stringA, stringB) << endl;
  return 0;
}

bool checkIfEqual(string a, string b){
  if(a == b){
    return true;
  }
  return false;
}
