#include <iostream>
#include <cstdlib>

using namespace std;
int numsArray[10];
int main(){
  int numLength = sizeof(numsArray)/sizeof(numsArray[0]);
  srand(time(NULL));
  for(int i = 0; i < numLength;i++){
    numsArray[i] = rand()%151;
    cout << numsArray[i] << endl;
  }
  return 0;
}
