#include <iostream>
#include <string>

using namespace std;

int main(){
  int count = 10;
  int step = 5;
  int position = 0;
  int slotsLeft = 10;

  string* courseCodes[count];
  string input;
  cout << "Please enter course codes (To finish type DONE)" << endl;
  cin >> input;

  while(input != "DONE"){
    courseCodes[position] = input;

    if(slotsLeft <= 5){
      string* tempArray[count + step];

      for(int i = 0; i < count - slotsLeft; i++){
        tempArray[i] = courseCodes[i];
      }

      count += step;
      slotsLeft += step;

      delete(courseCodes);

      courseCodes = tempArray;
    }

    cin >> input;
    slotsLeft--;
    position++;
  }
}
