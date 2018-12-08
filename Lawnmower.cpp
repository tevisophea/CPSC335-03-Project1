// Assignment 1: Alternating disks problem, lawnmower algorithm                                                                                                          
// Joshua Marvel, Tevisophea Heng 
// Given 2n alternating disks (dark, light)  the program reads the number of single color disks 
// (light or dark), arranges the disks in the correct order and outputs the number of swaps 
// INPUT: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark 
// OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark, 
// and an integer m representing the number of moves to move the dark ones after the light ones  
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void print_disks(int n, char *disks) {
	for (int i = 0; i < 2 * n; i++) {
		if (disks[i] == 1)
			cout << "d ";
		else if (disks[i] == 0)
			cout << "l ";
	}
}

int main() {
	//int n, m, k, i, j;
	int n, i, k, m = 0;
	char *disks;
	// display the header 
	cout << endl << "CPSC 335-03 - Programming Assignment #1" << endl;
	cout << "The alternating disks problem: lawnmower algorithm" << endl;
	cout << "Enter the number of single color disks (light or dark)" << endl;
	// read the number of disks 
	cin >> n;
	// allocate space for the disks
	disks = new char[2 * n];
	// set the initial configurations for the disks to alternate 
	for (i = 0; i < n; i++) {
		disks[2 * i] = 1;
		disks[2 * i + 1] = 0;
	}
	// print the initial configuration of the list of disks
	cout << "Initial configuration" << endl;
	cout << "List of disks\n";
	print_disks(n, disks);

	// PART OF CODE MISSING
	// loop to push light one before darks ones 
	for (k = 0; k < n / 2 + 1; k++) {
		// DEVELOP ONE FOR LOOP FOR GOING LEFT TO RIGHT
		for (int j = 0; j < n * 2 - 1; j++) {
			if ((disks[j] == 1) && (disks[j] != disks[j + 1])) {
				int temp = disks[j];
				disks[j] = disks[j + 1];
				disks[j + 1] = temp;
				m++;
			}
		}

		// DEVELOP ANOTHER FOR LOOP FOR GOING RIGHT TO LEFT  
		for (int q = n * 2 - 1; q > n - 3; q--) {
			if (disks[q] == 1) {
			}
			else if ((disks[q] != 1) && (disks[q] != disks[q - 1])) {
				int temp = disks[q];
				disks[q] = disks[q - 1];
				disks[q - 1] = temp;
				m++;
			}
		}
	}

	// after shuffling them
	cout << endl << "After moving darker ones to the right" << endl;
	cout << "List of disks\n";
	print_disks(n, disks);
	
	// print the total number of moves
	cout << endl << "Number of swaps is " << m << endl;
	// de-allocate the dynamic memory space

	system("PAUSE");
	delete[] disks;

	return EXIT_SUCCESS;
}