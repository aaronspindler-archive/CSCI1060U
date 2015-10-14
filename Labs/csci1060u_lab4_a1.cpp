//Author: Aaron Spindler
//Date: October 6th, 2015
//Purpose: Sort an array of 1000 strings from a file using call by reference and call by value


/*
Time to sort strings with call by reference
real	0m0.013s
user	0m0.012s
sys	0m0.000s

Time to sort strings with call by value
real	0m0.029s
user	0m0.024s
sys	0m0.000s
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//Function Declaration
void FillArray(string file_name);
void sortArray(string file_name);
bool swapNeeded(string& first, string& second);
//bool swapNeeded(string first, string second);
void swap(string& a, string& b);

//Variables
const string FILE_NAME = "test.txt";
const int NUM_ELEMENTS = 1000;
string stringArray[NUM_ELEMENTS];

int main() {
	//Calling the sortArray function to sort the data in stringArray
	sortArray(FILE_NAME);

	//Looping through the array to display the final array values
	for(int i = 0; i < NUM_ELEMENTS;i++){
		cout << stringArray[i] << endl;
	}
	return 0;
}

//Determining if the values need to be swapped using call by reference
bool swapNeeded(string& first, string& second) {
  if(second < first){
    return true;
  }
  return false;
}

/*
//Determining if the values need to be swapped using call by value
bool swapNeeded(string first, string second) {
  if(second < first){
    return true;
  }
  return false;
}
*/


//Swapping the two values with eachother
void swap(string& a, string& b){
  string temp = a;
	a = b;
	b = temp;
  return;
}

//Filling the array with data and then sorting said data
void sortArray(string file_name) {
	//Calling the function FillArray which populates the array stringArray with data
  FillArray(file_name);
  for (int x = 0; x < (NUM_ELEMENTS - 1); x++) {
		for (int y = (x + 1); y < NUM_ELEMENTS; y++) {
			if (swapNeeded(stringArray[x],stringArray[y])) {
				swap(stringArray[x], stringArray[y]);
			}
		}
	}
	return;
}

//Populates stringArray with data from a text file
void FillArray(string file_name){
  ifstream inputFile;
	//Opening the file
  inputFile.open(file_name.c_str());
  int i = 0;
	//Reading the file line by line until we reach the end of the file
  while(!inputFile.eof()) {
    inputFile >> stringArray[i];
    i++;
  }
	//Closing the file
  inputFile.close();

	//If there are not NUM_ELEMENTS in the array fill the empty space until NUM_ELEMENTS with empty strings
	if(i < NUM_ELEMENTS){
		for(int j = i; j < NUM_ELEMENTS;j++){
			stringArray[j] = "";
		}
	}
}
