#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <iomanip>
using namespace std;

void fillMatrix(vector<vector<int>>& v1, int& size);
void copyMatrix(vector<vector<int>> v1, vector<vector<int>>& v2, int size);
void initializeEmptyMatrix(vector<vector<int>>& v1, int size);
void printMatrix(vector<vector<int>> v1, int size);
void addMatrix(vector<vector<int>> v1, vector<vector<int>> v2, vector<vector<int>>& addM, int& size);
void multMatrix(vector<vector<int>> v1, vector<vector<int>> v2, vector<vector<int>>& multM, int& size);
void summationOfMatrices(vector<vector<vector<int>>> matrices, vector<vector<int>>& outMatrix, int size);
bool isReflexive(vector<vector<int>> v1, int size);
bool isSymmetric(vector<vector<int>> v1, int size);
bool isTransitive(vector<vector<int>> v1, int size);
void calcTransClosure(vector<vector<int>> v1, vector<vector<int>>& transClosure, int& size);
void verifyPath(vector<vector<int>> transClosure, int size);