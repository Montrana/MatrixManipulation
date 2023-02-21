#include "matrix.h"
using namespace std;

void fillMatrix(vector<vector<int>>& v1, int& size) {
    
    vector<int> tempRow;
    int tempValue;
    int inputType;
    do
    {
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
            bool validInput = false;
            do
            {
                cout << "Which vector dimension (2-4) do you prefer? ";
                cin >> dimension;
                switch (dimension)
                {
                case 2:
                    size = 2;
                    v1 = { {1,0},
                          {0,1} };
                    validInput = true;
                    break;
                case 3:
                    size = 3;
                    v1 = { {1,1,0},
                          {0,1,0},
                          {1,0,1} };
                    validInput = true;
                    break;
                case 4:
                    size = 4;
                    v1 = { {1,1,1,0},
                          {1,1,0,1},
                          {1,0,0,0},
                          {0,1,0,1} };
                    validInput = true;
                    break;
                default:
                    cout << "Please enter a valid input.\n";
                    break;
                }
            } while (validInput == false);
        }
        else
        {
            cout << "Please enter a valid choice\n";
        }
    } while (inputType != 0 && inputType != 1);
    
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
    vector<vector<int>> tempMatrix = v1;
    vector<vector<int>> outMatrix;
    for (int i = 2; i <= size; i++)
    {
        cout << "Temp matrix:\n";
        printMatrix(tempMatrix, size);
        cout << "V1:\n";
        printMatrix(tempMatrix, size);
        multMatrix(tempMatrix, v1, outMatrix, size);
        cout << "The result of the matrix to the power of " << i << " is:\n";
        printMatrix(outMatrix, size);
        tempMatrix = outMatrix; 
    }
    multMatrix(tempMatrix, v1, transClosure, size);
}