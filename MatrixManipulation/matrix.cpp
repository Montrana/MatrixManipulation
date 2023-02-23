#include "matrix.h"
using namespace std;

void fillMatrix(vector<vector<int>>& v1, int& size) {
    
    vector<int> tempRow;
    int tempValue;
    int inputType;
    cout << "Enter the type of input to use:\n";
    cout << "0 - File\n";
    cout << "1 - Use set values\n";
    cout << "Enter your choice: ";
    cin >> inputType;
    if (inputType == 0)
    {
        ifstream inFile;
        inFile.open("vector.txt");
        if (!inFile.is_open()) {
            cout << "Unable to open file\n";
        }
        inFile >> size;
        for (int r = 0; r < size; r++) {
            tempRow.clear();
            for (int c = 0; c < size; c++) {
                inFile >> tempValue;
                tempRow.push_back(tempValue);
            }
            v1.push_back(tempRow);
        }
    }
    else if (inputType == 1)
    {
        int dimension;
        cout << "Which vector dimension (2-4) do you prefer? ";
        cin >> dimension;
        switch (dimension)
        {
        case 2:
            size = 2;
            v1 = { {1,0},
                    {0,1} };
            break;
        case 3:
            size = 3;
            v1 = { {1,1,0},
                    {0,1,0},
                    {1,0,1} };
            break;
        case 4:
            size = 4;
            v1 = { {1,1,1,0},
                    {1,1,0,1},
                    {1,0,0,0},
                    {0,1,0,1} };
            break;
        default:
            break;
        }
    }
}

void copyMatrix(vector<vector<int>> v1, vector<vector<int>>& v2, int size)
{
    vector<int> tempRow;
    int tempValue;
    v2.clear();
    for (int r = 0; r < size; r++) {
        tempRow.clear();
        for (int c = 0; c < size; c++) {
            tempValue = v1[r][c];
            tempRow.push_back(tempValue);
        }
        v2.push_back(tempRow);
    }
}

void initializeEmptyMatrix(vector<vector<int>>& v1, int size)
{
    vector<int> tempRow;
    for (int r = 0; r < size; r++) {
        tempRow.clear();
        for (int c = 0; c < size; c++) {
            tempRow.push_back(0);
        }
        v1.push_back(tempRow);
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
    for (int i = 0; i < size; i++) {
        tempRow.clear();
        for (int j = 0; j < size; j++) {
            tempValue = 0;
            for (int k = 0; k < size; k++) {
                tempValue += (v1[i][k] * v2[k][j]);
            }
            tempRow.push_back(tempValue);
        }
        multM.push_back(tempRow);
    }
}
void summationOfMatrices(vector<vector<vector<int>>> matrices, vector<vector<int>>& outMatrix, int size)
{
    vector<vector<int>> tempMatrix;
    vector<vector<int>> tempMatrix2;
    initializeEmptyMatrix(tempMatrix, size);
    
    for (int i = 0; i < size; i++) {
        addMatrix(matrices[i], tempMatrix, tempMatrix2, size);
        //cout << "Summation after " << i + 1 << " loops:\n";
        //printMatrix(tempMatrix2, size);
        copyMatrix(tempMatrix2, tempMatrix, size);
        tempMatrix2.clear();
    }
    copyMatrix(tempMatrix, outMatrix, size);
}
bool isReflexive(vector<vector<int>> v1, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (v1[i][i] != 1)
        {
            return false;
        }
    }
    return true;
}
bool isSymmetric(vector<vector<int>> v1, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && v1[i][j] != v1[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
bool isTransitive(vector<vector<int>> v1, int size)
{
    vector<vector<int>>vectorSquared;
    multMatrix(v1, v1, vectorSquared, size);
    for (int r = 0; r < size; r++) 
    {
        for (int c = 0; c < size; c++) 
        {
            if (vectorSquared[r][c] != 0 && v1[r][c] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
void calcTransClosure(vector<vector<int>> v1, vector<vector<int>>& transClosure, int& size)
{
    vector<vector<int>> tempMatrix;
    copyMatrix(v1, tempMatrix, size);
    vector<vector<int>> outMatrix;
    vector<vector<vector<int>>> matrixList;
    matrixList.push_back(v1);
    for (int i = 2; i <= size; i++)
    {
        /*
        cout << "Temp matrix:\n";
        printMatrix(tempMatrix, size);
        cout << "V1:\n";
        printMatrix(v1, size);*/
        multMatrix(tempMatrix, v1, outMatrix, size);
        cout << "\nThe result of the matrix to the power of " << i << " is:\n";
        printMatrix(outMatrix, size);
        copyMatrix(outMatrix, tempMatrix, size);
        matrixList.push_back(outMatrix);
        outMatrix.clear();
    }
    summationOfMatrices(matrixList, transClosure, size);
}
void verifyPath(vector<vector<int>> transClosure, int size) {
    int start;
    int end;
    char checkRoutes;
    cout << "\nWould you like to check routes? (Y if so): ";
    cin >> checkRoutes;
    checkRoutes = toupper(checkRoutes);
    while (checkRoutes == 'Y') {
        cout << "\nGreat! Enter Values between 0 and " << size - 1 << ":\n";
        cout << "Enter the starting value: ";
        cin >> start;
        cout << "Enter the ending value: ";
        cin >> end;
        if (transClosure[start][end] != 0)
        {
            cout << "There is a path between " << start << " and " << end << "!\n";
        }
        else
        {
            cout << "There is not a path between " << start << " and " << end << "!\n";
        }
        cout << "\nWould you like to try again (Y): ";
        cin >> checkRoutes;
        checkRoutes = toupper(checkRoutes);
    } 
}