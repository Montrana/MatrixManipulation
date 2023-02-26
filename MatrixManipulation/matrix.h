#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <iomanip>
using namespace std;

/// <summary>
/// This function fills a matrix with the values in a file or set hardcoded values.
/// </summary>
/// <param name="v1">The vector, which represents a matrix, 
/// which is passed by value, changes based on what we put in the vector.</param>
/// <param name="size">The size of the square vector, 
/// the number of values represented by the vector is size*size</param>
void fillMatrix(vector<vector<int>>& v1, int& size);

/// <summary>
/// Copies one matrix into another, in order to get around the inability to directly set one vector equal to another.
/// </summary>
/// <param name="v1">the vector that will be coppied</param>
/// <param name="v2">the vector that we will copy the values of v1 into</param>
/// <param name="size">the size of v1 and what will be v2</param>
void copyMatrix(vector<vector<int>> v1, vector<vector<int>>& v2, int size);

/// <summary>
/// Initiallizes a matrix with all 0s for its values
/// </summary>
/// <param name="v1">the matrix to be created with 0s for all values</param>
/// <param name="size">the size of the matrix squared to get the number of values</param>
void initializeEmptyMatrix(vector<vector<int>>& v1, int size);

/// <summary>
/// Prints a matrix
/// </summary>
/// <param name="v1">the matrix that gets printed</param>
/// <param name="size">the size of the matrix, used to loop through the matrix and print all values</param>
void printMatrix(vector<vector<int>> v1, int size);

/// <summary>
/// adds one matrix to another and outputs it using a third matrix: v1 + v2 = addM
/// </summary>
/// <param name="v1">the first matrix to be added</param>
/// <param name="v2">the second matrix to be added</param>
/// <param name="addM">the out put matrix that is passed by reference so it can be changed</param>
/// <param name="size">the size of each of these matrices, used to loop for the addition algorithm</param>
void addMatrix(vector<vector<int>> v1, vector<vector<int>> v2, vector<vector<int>>& addM, int& size);

/// <summary>
/// multiplies one matrix with another, and out puts a third matrix: v1 * v2 = multM
/// </summary>
/// <param name="v1">the first matrix to be added</param>
/// <param name="v2">the second matrix to be added</param>
/// <param name="multM">the output matrix, which is passed by reference so it could be changed</param>
/// <param name="size">the size of each of the 3 matrices</param>
void multMatrix(vector<vector<int>> v1, vector<vector<int>> v2, vector<vector<int>>& multM, int& size);

/// <summary>
/// calculates a summation of all matrices in matrices, in order to find the transitive closure
/// </summary>
/// <param name="matrices">the list of matrices to add together</param>
/// <param name="outMatrix">the matrix that the summation will be added into</param>
/// <param name="size">the size of each of the matrices</param>
void summationOfMatrices(vector<vector<vector<int>>> matrices, vector<vector<int>>& outMatrix, int size);

/// <summary>
/// Checks to see if a matrix is reflexive: if all values along the diagonal are 1
/// </summary>
/// <param name="v1">the matrix that is checked to see if it is transitive</param>
/// <param name="size">the size of the matrix</param>
/// <returns>a bool if the matrix is reflexive or not</returns>
bool isReflexive(vector<vector<int>> v1, int size);

/// <summary>
/// checks and sees if a matrix is symmetric or not: all values across the diagonal are the same: v1[i][j] == v1[j][i]
/// </summary>
/// <param name="v1">the matrix that is checked to see if it is symmetric or not</param>
/// <param name="size">the size of the matrix</param>
/// <returns>a bool whether or not the matrix is symmetric or not</returns>
bool isSymmetric(vector<vector<int>> v1, int size);

/// <summary>
/// checks to see if a matrix is transitive or not: 
/// if a value of a squared matrix is non zero while in the non squared matrix, it was zero, it is not reflexive
/// </summary>
/// <param name="v1">The vector that will be checked if it is transitive or not</param>
/// <param name="size">the size of the vector</param>
/// <returns>a bool of whether or not the matrix is transitive or not</returns>
bool isTransitive(vector<vector<int>> v1, int size);

/// <summary>
/// calculates a transitive closure of the matrix: summation of v1^x, where x starts at 1 and increases until size
/// </summary>
/// <param name="v1">the matrix that a transitive closure is created of</param>
/// <param name="transClosure">a matrix of the transitive closure output</param>
/// <param name="size">the size of each matrix</param>
void calcTransClosure(vector<vector<int>> v1, vector<vector<int>>& transClosure, int& size);

/// <summary>
/// checks and verifies a path from one point to another: 
/// in the transitive closure, if the value of [starting value] -> [ending value] is non 0, 
/// there is a path between starting value and ending value
/// </summary>
/// <param name="transClosure">the transitive closure that we check</param>
/// <param name="size">the size of the matrix, needed to output the max value through cout</param>
void verifyPath(vector<vector<int>> transClosure, int size);