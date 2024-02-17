// Program created by Tommy Trinh
// February 17, 2024
// This program sorts a list of numbers using bubble and selection sorting
#include <iomanip>
#include <iostream>
#include <array>
using namespace std;

// define constants
const int SIZE = 14;	// size of the number arrays

// define function prototypes
void header();							// display program info
void bubbleSort(array<int, SIZE>&);		// sorts an array by bubble sort
void selectionSort(array<int, SIZE>&);	// sorts an array by selection sort
void arraySwap(int&, int&);				// swaps two int elements

int main()
{
	// define variables
	array<int, SIZE> numList1 = { 98,78,102,67,45,83,29,184,2,68,-7,56,121,5 };
	array<int, SIZE> numList2 = { 98,78,102,67,45,83,29,184,2,68,-7,56,121,5 };
	int tempcounter;		// temporary counter variable

	// call function header
	header();

	// display unsorted numList1
	cout << "\nBefore Bubble Sort:\n";
	tempcounter = 1;	// initialize temporary counter
	for (auto it = numList1.begin(); it != numList1.end(); it++)
	{
		cout << setw(8) << " " << "Number" << setw(3) << tempcounter
			<< " = " << *it << endl;
		tempcounter++;
	}

	// sort numList1 using a bubble sorting function
	bubbleSort(numList1);
	
	// display sorted numList1
	cout << "\nAfter Selection Sort:\n";
	tempcounter = 1;	// initialize temporary counter
	for (auto it = numList1.begin(); it != numList1.end(); it++)
	{
		cout << setw(8) << " " << "Number" << setw(3) << tempcounter
			<< " = " << *it << endl;
		tempcounter++;
	}

	// display unsorted numList2
	cout << "\nBefore Selection Sort:\n";
	tempcounter = 1;	// initialize temporary counter
	for (auto it = numList2.begin(); it != numList2.end(); it++)
	{
		cout << setw(8) << " " << "Number" << setw(3) << tempcounter
			<< " = " << *it << endl;
		tempcounter++;
	}

	// sort numList2 using a selection sorting function
	selectionSort(numList2);

	// display sorted numList2
	cout << "\nAfter Selection Sort:\n";
	tempcounter = 1;	// initialize temporary counter
	for (auto it = numList2.begin(); it != numList2.end(); it++)
	{
		cout << setw(8) << " " << "Number" << setw(3) << tempcounter
			<< " = " << *it << endl;
		tempcounter++;
	}

	// end of main
	system("pause");
	return 0;
}

// display program title, copyright, and info 
void header()
{
	cout << "CE - Sort\n"
		<< "Copyright 2024 - Howard Community College All rights reserved; "
		<< "Unauthorized duplication prohibited.\n\n"
		<< "\tWelcome to CMSY-171 Starter Review Program\n\n";
}

// Sort an array using the bubble sort method to sort in ascending order
// from lowest to highest
void bubbleSort(array<int,SIZE>& list)
{
	int maxElement;
	int index;

	for (maxElement = list.size() - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (list[index] > list[index + 1])
				arraySwap(list[index], list[index + 1]);
		}
	}
}

// Sort an array using the selection sort method to sort in descending order
// from highest to lowest
void selectionSort(array<int, SIZE>& list)
{
	int maxIndex, maxValue;

	for (int start = 0; start < list.size() - 1; start++)
	{
		maxIndex = start;
		maxValue = list[start];
		for (int index = start + 1; index < list.size(); index++)
		{
			if (list[index] > maxValue)
			{
				maxValue = list[index];
				maxIndex = index;
			}
		}
		arraySwap(list[maxIndex], list[start]);
	}
}

// swap two arrays
void arraySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}