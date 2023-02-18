// MatrixManipulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "matrix.h"

int main() {
    int size = 3;
    int arr[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    ifstream inFile;
    inFile.open("array.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file\n";
        return 1;
    }
    fillMatrix(inFile, arr, size);
    inFile.close();
    printMatrix(arr, size);
    cout << "Minimum: " << minMatrix(arr, size) << endl;

    vector<vector<int>> v1, v2, addM, multM;
    ifstream inFile2;
    inFile2.open("vector.txt");
    if (!inFile2.is_open()) {
        cout << "Unable to open file\n";
        return 1;
    }
    fillMatrix(inFile2, v1, size);
    fillMatrix(inFile2, v2, size);
    addMatrix(v1, v2, addM, size);
    multMatrix(v1, v2, multM, size);
    printMatrix(v1, size);
    cout << "Minimum: " << minMatrix(v1, size) << endl;
    cout << endl;
    printMatrix(v2, size);
    cout << "Minimum: " << minMatrix(v2, size) << endl;
    cout << endl;
    printMatrix(addM, size);
    cout << "Minimum: " << minMatrix(addM, size) << endl;
    cout << endl;
    printMatrix(multM, size);
    cout << "Minimum: " << minMatrix(multM, size) << endl;
}