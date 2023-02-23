// MatrixManipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "matrix.h"

int main() {
    int size;
    vector<vector<int>> v1, transClosure;
    
    fillMatrix(v1, size);
    cout << "\nThe current matrix is:\n\n";
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
    /*
    cout << endl;
    printMatrix(addM, size);
    cout << endl;
    printMatrix(multM, size);
    */
    calcTransClosure(v1, transClosure, size);
    cout << "\nThe transitive closure is:\n";
    printMatrix(transClosure, size);
    verifyPath(transClosure, size);
}