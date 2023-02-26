// MatrixManipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Montana Nicholson
// Date: Feb 17, 2023
// Objective: To create a program the is able to fill a matrix, 
// calculate if it is reflexive, symmetric, and/or transitive, 
// find its transitive closure, and verify a path between two values.


#include "matrix.h"

/// <summary>
/// Does most of the funtion calls some of the outputs in order to make the program run
/// </summary>
/// <returns>int, but nothing is actually returned out of this function</returns>
int main() {
	int size;
	vector<vector<int>> v1, transClosure; // initialization of all vectors that we will use in this function
	
	fillMatrix(v1, size);
	cout << "\nThe current matrix is:\n";
	printMatrix(v1, size);

	if (isReflexive(v1, size))
	{
		cout << "The matrix is reflexive.\n";
	}
	else
	{
		cout << "The matrix is not reflexive.\n";
	}

	if (isSymmetric(v1, size))
	{
		cout << "The matrix is symmetric.\n";
	}
	else
	{
		cout << "The matrix is not symmetric.\n";
	}

	if (isTransitive(v1, size))
	{
		cout << "The matrix is transitive.\n";
	}
	else
	{
		cout << "The matrix is not transitive.\n";
	}
	
	calcTransClosure(v1, transClosure, size);
	cout << "\nThe transitive closure is:\n";
	printMatrix(transClosure, size);
	verifyPath(transClosure, size);
}