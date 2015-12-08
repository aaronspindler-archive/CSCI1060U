
#include <iostream>
using namespace std;

int main(){
  int size = 10;
  int* array[10];
  for(int i = 0; i < size; i++){
    array[i] = new int;
    array[i] = 0;
    
    cout << array[i];
  }
  delete array[size];
}
