#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  //Variables
  string firstName;
  string lastName;
  int birthYear;
  float hourlyWage;

  //Input for firstName
  cout << "First name: ";
  cin >> firstName;

  //Input for lastName
  cout << "Last name: ";
  cin >> lastName;

  //Input for birthYear
  cout << "Birth year: ";
  cin >> birthYear;

  //Input for hourlyWage
  cout << "Hourly wage ($): ";
  cin >> hourlyWage;

  //Putting a line gap inbetween input and output
  cout << endl;

  //Calculating the age
  int age = 2015 - birthYear;

  //Outputting Strings and Integers
  cout << firstName << " " << lastName << " is " << age << " and requests an hourly wage of $";

  //Setting up float decimal points
  cout << fixed << setprecision(2);
  //Outputting floats
  cout << hourlyWage << endl;

  return 0;
}
