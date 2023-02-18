#include "matrix.h"
using namespace std;

void fillMatrix(ifstream& inFile, int arr[3][3], int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            inFile >> arr[r][c];
        }
    }
}

void fillMatrix(ifstream& inFile, vector<vector<int>>& v1, int& size) {
    inFile >> size;
    vector<int> tempRow;
    int tempValue;

    for (int r = 0; r < size; r++) {
        tempRow.clear();
        for (int c = 0; c < size; c++) {
            inFile >> tempValue;
            tempRow.push_back(tempValue);
        }
        v1.push_back(tempRow);
    }
}

void printMatrix(int arr[3][3], int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
}

void printMatrix(vector<vector<int>> v1, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cout << setw(5) << right << v1[r][c];
        }
        cout << endl;
    }
}

int minMatrix(int arr[3][3], int size) {
    int min =
        INT_MAX; // Geeks for geeks:
    // https://www.geeksforgeeks.org/int_max-int_min-cc-applications/
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (arr[r][c] < min) {
                min = arr[r][c];
            }
        }
    }
    return min;
}

int minMatrix(vector<vector<int>> v1, int size) {
    int min =
        INT_MAX; // Geeks for geeks:
    // https://www.geeksforgeeks.org/int_max-int_min-cc-applications/
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (v1[r][c] < min) {
                min = v1[r][c];
            }
        }
    }
    return min;
}

void addMatrix(vector<vector<int>> v1, vector<vector<int>> v2,
    vector<vector<int>>& addM, int& size) {
    vector<int> tempRow;
    int tempValue;
    for (int r = 0; r < size; r++) {
        tempRow.clear();
        for (int c = 0; c < size; c++) {
            tempValue = v1[r][c] + v2[r][c];
            tempRow.push_back(tempValue);
        }
        addM.push_back(tempRow);
    }
}
void multMatrix(vector<vector<int>> v1, vector<vector<int>> v2,
    vector<vector<int>>& multM, int& size) {
    vector<int> tempRow;
    int tempValue;
    for (int r = 0; r < size; r++) {
        tempRow.clear();
        for (int c = 0; c < size; c++) {
            tempValue = 0;
            for (int k = 0; k < size; k++) {
                tempValue += v1[r][c] + v2[r][c];
            }
            tempRow.push_back(tempValue);
        }
        multM.push_back(tempRow);
    }
}