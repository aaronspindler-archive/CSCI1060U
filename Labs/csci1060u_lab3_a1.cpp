#include <iostream>

using namespace std;

//Functions Declaration
void sortArray(int(&numsArray)[7]);
void swap(int& a, int& b);

//Variables
int numsArray[7];

int main()
{
	//Input / Output
	cout << "Enter 7 integers:" << endl;

	//Getting the 7 integers from user input
	for (int i = 0; i < 7; i++)
	{
		cin >> numsArray[i];
	}

	cout << endl;

	//Calling the sortArray Functions
	sortArray(numsArray);

	//Outputting the sorted array
	cout << "The array of integers sorted in ascending order is:" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << numsArray[i] << " ";
	}

	cout << endl;

	return 0;
}


//Functions Definition
void swap(int& a, int& b)
{
	//Swapping the values of a and b with eachother
	a = a + b;
	b = a - b;
	a = a - b;

	return;
}

void sortArray(int(&numsArray)[7])
{
	const int SIZEOFARRAY = (sizeof(numsArray) / sizeof(numsArray[0]));

	for (int x = 0; x< (SIZEOFARRAY - 1); x++)
	{
		for (int y = (x + 1); y < SIZEOFARRAY; y++)
		{
			if (numsArray[x] > numsArray[y])
			{
				swap(numsArray[x], numsArray[y]);
			}
		}
	}
}
