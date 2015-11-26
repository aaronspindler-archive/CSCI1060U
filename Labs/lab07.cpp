#include <iostream>

using namespace std;

typedef int* IntPtr;

int main() {
  const int INCREMENT = 5;
  int size = 5;
  int spacesLeft = size;
  IntPtr intArray = new int[size];
  int val = 0;

  cout << "Enter postive integers (-1 when done): " << endl;

  //Taking input of unknown length
  while (val > -1) {
    cin >> val;
    if (val > -1) {
      intArray[size-spacesLeft] = val;
      //The next statement used to debug
      cout << "intArray[" << (size-spacesLeft) << "] = "
           << intArray[size-spacesLeft] << endl;
      spacesLeft--;
      if (spacesLeft == 0) {
        //make bigger array
        IntPtr tempArray = new int[size+INCREMENT];
        for (int i=0; i < size; i++) {
          tempArray[i] = intArray[i];
        }
        delete[] intArray;
        intArray = tempArray;
        size += INCREMENT;
        spacesLeft = INCREMENT;
      }
    }
  }

  //Displaying array
  for (int j=0; j < (size-spacesLeft); j++) {
    if (j != (size-spacesLeft-1)) {
      cout << intArray[j] << ", ";
    } else {
      cout << intArray[j] << "." << endl;
    }
  }

  int numTimesArray[size - spacesLeft];
  for(int i = 0; i < (size - spacesLeft); i++){
    numTimesArray[intArray[i]] += 1;
  }

  for(int i = 0; i < (size - spacesLeft);i++){
    if(numTimesArray[i] > 0){
      cout << (i + 1) << " -> " << numTimesArray[i] << " times." << endl;
    }
  }

  delete[] intArray;

  return 0;
}
