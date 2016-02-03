#include <iostream>
#include <string>

using namespace std;

int main(){
  int size = 10;
  int** array[size];

  //Creation
  for(int i = 0; i < size; i++){
    array[i] = new int*[size];
    for(int j = 0; j < size; j++){
      array[i][j] = new int();
    }
  }

  //Deletion
  for(int i = 0; i < size; i++){
    delete(array[i]);
  }
}
