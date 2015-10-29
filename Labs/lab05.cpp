//Date: 10/19/2015

#include <iostream>
#include <cmath>

using namespace std;

//Function Declaration
void gatherFactoryInformation(int factoryArray[], int numberOfFactories);
void convertToThousands(int factoryArray[], int numberOfFactories);
void outputFinalReport(const int factoryArray[], int numberOfFactories);
void inputUnitsSold(int& sum);
int roundNumber(double number);
void printGraph(int length);

//Constant Variables
const int NUM_FACTORIES = 3;

//Main Function
int main() {
  int production[NUM_FACTORIES];
  //Printing program information text
  cout << "This program displays a graph showing production for each factory in the company." << endl;
  gatherFactoryInformation(production, NUM_FACTORIES);
  convertToThousands(production, NUM_FACTORIES);
  outputFinalReport(production, NUM_FACTORIES);
  return 0;
}

//Start of function definition
void gatherFactoryInformation(int factoryArray[], int numberOfFactories) {
  for (int factoryNumber = 1; factoryNumber <= numberOfFactories; factoryNumber++)
  {
    cout << endl << "Enter production data for plant number " << factoryNumber << endl;
    inputUnitsSold(factoryArray[factoryNumber - 1]);
  }
}

void convertToThousands(int factoryArray[], int numberOfFactories) {
  //Loops through the factory array and convert into 1000 base
  for (int index = 0; index < numberOfFactories; index++){
    factoryArray[index] = roundNumber(factoryArray[index]/1000.0);
  }
}

void outputFinalReport(const int anArray[], int numberOfFactories) {
  cout << "Units produced in thousands of units:" << endl;

  for (int factoryNumber = 1; factoryNumber <= numberOfFactories; factoryNumber++)
  {
    //Print the graph for each factory using the printGraph function
    cout << "Factory #" << factoryNumber << " ";
    printGraph(anArray[factoryNumber - 1]);
    cout << endl;
  }
}

//Gathers the input from all of the departments
void inputUnitsSold(int& sum) {
  cout << "Enter number of units produced by each department." << endl
  << "# Append a negative number to the end of the list. #" << endl;
  sum = 0;
  int next;
  cin >> next;

  //Gather integer data until a value less than 0 is recieved
  while (next >= 0) {
    sum = sum + next;
    cin >> next;
  }

  cout << "Total = " << sum << endl;
}

//Rounds a number down and converts it into an integer
int roundNumber(double number) {
  return static_cast<int>(floor(number + 0.5));
}
//Prints a * a defined length
void printGraph(int length) {
  for (int count = 1; count <= length; count++) {
    cout << "*";
  }
}
