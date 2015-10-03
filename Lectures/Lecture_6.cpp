#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string fileName;
  string data[5];

  cout << "Enter a filename: ";
  cin >> fileName;

  //Creating the output file stream
  ofstream outputFileOdd;
  outputFileOdd.open(fileName.c_str(), ios::app);

  cout << "Enter in 5 words to store in a file!" << endl;
  for(int i = 0; i < 5; i++){
    cin >> data[i];
  }

  for(int i = 0; i < 5; i = i+2){
    outputFileOdd << data[i];
  }
  outputFileOdd.close();

  //Input Stream
  ifstream inputFile;
  inputFile.open(fileName.c_str());

  string line;
  while(!inputFile.eof()) {
    inputFile >> line;
    cout << line << endl;
  }
  inputFile.close();
  return 0;
}
