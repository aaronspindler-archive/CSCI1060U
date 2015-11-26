#include <iostream>

using namespace std;

typedef int* IntPtr;

int main() {
  const int INCREMENT = 5;
  int size = 5;
  int spacesLeft = size;

  IntPtr intArray = new int[INCREMENT];

  cout << "Enter positive integers (-1 when done): " << endl;

  int val = 0;

  while(val > -1){
    cin >> val;
    if(val > -1){
      intArray[size-spacesLeft] = val;
      spacesLeft--;

      if(spacesLeft == 0){
        IntPtr tempArray = new int[size+INCREMENT];
        for(int i = 0; i < size;i++){
          tempArray[i] = intArray[i];
        }
        delete[] intArray;
        intArray = tempArray;
        size += INCREMENT;
        spacesLeft = INCREMENT;
      }
    }
  }

  delete[] intArray;

  return 0;
}
