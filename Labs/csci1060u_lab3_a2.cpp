/*
Time to sort 1000 numbers
real	0m0.006s
user	0m0.004s
sys	0m0.000s

Time to sort 10,000 numbers
real	0m0.443s
user	0m0.384s
sys	0m0.032s
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Variables
const int NUM_ELEMENTS = 1000;
int numsArray[NUM_ELEMENTS];

//Functions Declaration
void sortArray(int(&numsArray)[NUM_ELEMENTS]);
void swap(int& a, int& b);

int main()
{
	//Getting the start time before running any other code
	clock_t startTime = clock();

	//Seeding random number generator
	srand(time(NULL));

	//Loop to fill my array with random values
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		//Getting a random number for slot "i" in my array
		numsArray[i] = rand();
		//Outputting the random number that has been stored in the array
		cout << numsArray[i] << endl;
	}

	//Execute the sort on the array
	sortArray(numsArray);

	//Getting the end time after sorting the array
	clock_t endTime = clock();
	//Computing the time difference between startTime and endTime
	float timeDiff = float(endTime - startTime) / CLOCKS_PER_SEC;

	//Outputting the time it took to sort the array
	cout << "The time it took to sort: " << NUM_ELEMENTS << " elements is " << timeDiff << " seconds." << endl;

	return 0;
}

//Functions Definition
//Swap the values in a and b with eachother
void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;

	return;
}

void sortArray(int(&numsArray)[NUM_ELEMENTS])
{
	for (int x = 0; x < (NUM_ELEMENTS - 1); x++)
	{
		for (int y = (x + 1); y < NUM_ELEMENTS; y++)
		{
			/*
				Checks if the value in numsArray[x] is larger than numsArray[y],
				if it is larger proceed into the if statment
			*/
			if (numsArray[x] > numsArray[y])
			{
				//Uses the swap function to swap the numbers in the array
				swap(numsArray[x], numsArray[y]);
			}
		}
	}
	return;
}
