#include "matrix.h"
using namespace std;

/// <summary>
/// This function fills a matrix with the values in a file or set hardcoded values.
/// </summary>
/// <param name="v1">The vector, which represents a matrix, 
/// which is passed by reference, changes based on what we put in the vector.</param>
/// <param name="size">The size of the square vector, 
/// the number of values represented by the vector is size*size</param>
void fillMatrix(vector<vector<int>>& v1, int& size) 
{
    vector<int> tempRow;
    int tempValue;
    int inputType;
    cout << "Enter the type of input to use:\n";
    cout << "0 - File\n";
    cout << "1 - Use set values\n";
    cout << "Enter your choice: ";
    cin >> inputType;
    if (inputType == 0) // choice of inputing the matrix from a file
    {
        ifstream inFile;
        inFile.open("vector.txt");
        if (!inFile.is_open()) // checks to see if the file is open
        {
            cout << "Unable to open file\n";
        }
        else
        {
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
        inFile.close();
    }
    else if (inputType == 1) // inputing the matrix using a set set of values
    {
        int dimension;
        cout << "Which vector dimension (2-4) do you prefer? ";
        cin >> dimension;
        switch (dimension) {
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

/// <summary>
/// Copies one matrix into another, in order to get around the inability to directly set one vector equal to another.
/// </summary>
/// <param name="v1">the vector that will be copied</param>
/// <param name="v2">the vector that we will copy the values of v1 into</param>
/// <param name="size">the size of v1 and what will be v2</param>
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

/// <summary>
/// Initializes a matrix with all 0s for its values
/// </summary>
/// <param name="v1">the matrix to be created with 0s for all values, 
/// passed by reference so it can be changed</param>
/// <param name="size">the size of the matrix squared to get the number of values</param>
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

/// <summary>
/// Prints a matrix
/// </summary>
/// <param name="v1">the matrix that gets printed</param>
/// <param name="size">the size of the matrix, used to loop through the matrix and print all values</param>
void printMatrix(vector<vector<int>> v1, int size) 
{
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cout << setw(5) << right << v1[r][c];
        }
        cout << endl;
    }
}

/// <summary>
/// adds one matrix to another and outputs it using a third matrix: v1 + v2 = addM
/// </summary>
/// <param name="v1">the first matrix to be added</param>
/// <param name="v2">the second matrix to be added</param>
/// <param name="addM">the output matrix that is passed by reference so it can be changed</param>
/// <param name="size">the size of each of these matrices</param>
void addMatrix(vector<vector<int>> v1, vector<vector<int>> v2, 
    vector<vector<int>>& addM, int& size)
{
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

/// <summary>
/// multiplies one matrix with another, and outputs a third matrix: v1 * v2 = multM
/// </summary>
/// <param name="v1">the first matrix to be added</param>
/// <param name="v2">the second matrix to be added</param>
/// <param name="multM">the output matrix, which is passed by reference so it could be changed</param>
/// <param name="size">the size of each of the 3 matrices</param>
void multMatrix(vector<vector<int>> v1, vector<vector<int>> v2,
    vector<vector<int>>& multM, int& size) 
{
    vector<int> tempRow;
    int tempValue;
    for (int i = 0; i < size; i++) {
        tempRow.clear();
        for (int j = 0; j < size; j++) {
            tempValue = 0;
            for (int k = 0; k < size; k++) {
                tempValue += (v1[i][k] * v2[k][j]); // the matrix multiplication formula
            }
            tempRow.push_back(tempValue);
        }
        multM.push_back(tempRow);
    }
}

/// <summary>
/// calculates a summation of all matrices in matrices, in order to find the transitive closure
/// </summary>
/// <param name="matrices">the list of matrices to add together</param>
/// <param name="outMatrix">the matrix that the summation will be added into</param>
/// <param name="size">the size of each of the matrices</param>
void summationOfMatrices(vector<vector<vector<int>>> matrices, 
    vector<vector<int>>& outMatrix, int size)
{
    vector<vector<int>> tempMatrix;
    vector<vector<int>> tempMatrix2;
    initializeEmptyMatrix(tempMatrix, size);
    
    for (int i = 0; i < size; i++) {
        addMatrix(matrices[i], tempMatrix, tempMatrix2, size);
        
        // used for testing:
        //cout << "Summation after " << i + 1 << " loops:\n";
        //printMatrix(tempMatrix2, size);

        // this assignes the summation in tempMatrix2 to tempMatrix,         
        // so that tempMatrix keeps the summation so it can continue to add to matrices[i]
        copyMatrix(tempMatrix2, tempMatrix, size); 
        tempMatrix2.clear();
    }
    copyMatrix(tempMatrix, outMatrix, size);
}

/// <summary>
/// Checks to see if a matrix is reflexive: if all values along the diagonal are 1
/// </summary>
/// <param name="v1">the matrix that is checked to see if it is transitive</param>
/// <param name="size">the size of the matrix</param>
/// <returns>a bool if the matrix is reflexive or not</returns>
bool isReflexive(vector<vector<int>> v1, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (v1[i][i] != 1)
        {
            return false; //returns false if one value along the diagonal is not 1
        }
    }
    return true; //returns true if the full matrix has been checked and every value along the diagonal is true
}

/// <summary>
/// checks and sees if a matrix is symmetric or not: 
/// all values across the diagonal are the same: v1[i][j] == v1[j][i]
/// </summary>
/// <param name="v1">the matrix that is checked to see if it is symmetric or not</param>
/// <param name="size">the size of the matrix</param>
/// <returns>a bool whether or not the matrix is symmetric or not</returns>
bool isSymmetric(vector<vector<int>> v1, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && v1[i][j] != v1[j][i])
            {
                return false; // if one of the cases fail, the matrix is not symmetric
            }
        }
    }
    return true; // if all tests pass, the matrix is symmetric
}

/// <summary>
/// checks to see if a matrix is transitive or not: 
/// if a value of a squared matrix is non zero while in the non squared matrix, it was zero, it is not reflexive
/// </summary>
/// <param name="v1">The vector that will be checked if it is transitive or not</param>
/// <param name="size">the size of the vector</param>
/// <returns>a bool of whether or not the matrix is transitive or not</returns>
bool isTransitive(vector<vector<int>> v1, int size)
{
    vector<vector<int>> vectorSquared;
    multMatrix(v1, v1, vectorSquared, size);
    for (int r = 0; r < size; r++) 
    {
        for (int c = 0; c < size; c++) 
        {
            if (vectorSquared[r][c] != 0 && v1[r][c] == 0)
            {
                return false; // if one of the cases fail, the matrix is not transitive
            }
        }
    }
    return true; // if all tests pass, the matrix is transitive
}

/// <summary>
/// calculates a transitive closure of the matrix: summation of v1^x, where x starts at 1 and increases until size
/// </summary>
/// <param name="v1">the matrix that a transitive closure is created of</param>
/// <param name="transClosure">a matrix of the transitive closure output</param>
/// <param name="size">the size of each matrix</param>
void calcTransClosure(vector<vector<int>> v1, vector<vector<int>>& transClosure, int& size)
{
    vector<vector<int>> tempMatrix;
    copyMatrix(v1, tempMatrix, size);
    vector<vector<int>> outMatrix;
    vector<vector<vector<int>>> matrixList; // initiallizes a list of matrices in order 
    matrixList.push_back(v1); // v1 = v1^x when x = 1; this line is the first value in the summation
    for (int i = 2; i <= size; i++) // this for loop calculates all powers of v1 up to size, and puts them into matrixList to sum up
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

/// <summary>
/// checks and verifies a path from one point to another: 
/// in the transitive closure, if the value of [starting value] -> [ending value] is non 0, 
/// there is a path between starting value and ending value
/// </summary>
/// <param name="transClosure">the transitive closure that we check</param>
/// <param name="size">the size of the matrix, needed to output the max value through cout</param>
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