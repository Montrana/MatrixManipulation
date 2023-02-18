#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <iomanip>
using namespace std;

void fillMatrix(ifstream& inFile, int arr[3][3], int size);
void fillMatrix(ifstream& inFile, vector<vector<int>>& v1, int& size);
void printMatrix(int arr[3][3], int size);
void printMatrix(vector<vector<int>> v1, int size);
int minMatrix(int arr[3][3], int size);
int minMatrix(vector<vector<int>> v1, int size);
void addMatrix(vector<vector<int>> v1, vector<vector<int>> v2,
    vector<vector<int>>& addM, int& size);
void multMatrix(vector<vector<int>> v1, vector<vector<int>> v2,
    vector<vector<int>>& multM, int& size);