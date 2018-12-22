/*
 * Developer : Naveen Rohilla
 * Objective : Sudoku solver
 */

#include <bits/stdc++.h>
using namespace std;
#define N 9

//	enter values of grid
void enterGrid(int arr[N][N]) {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

//	display sudoku grid
void displayGrid(int arr [N][N]) {
	cout << "-------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < N; i++) {
		cout << "|\t";
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << "\t";
			if (j % 3 == 2) {
			cout << "|\t";
			}
		}
		cout << endl;
		if (i % 3 == 2) {
			cout << "-------------------------------------------------------------------------------------------------\n";
		}
	}
}

//	find unassigned position in the grid
bool findUnassigned(int arr[N][N], int & row, int & col) {
	bool flag = true;
	for (row = 0; flag && row < N; row++) {
		for (col = 0; flag && col < N; col++) {
			if (arr[row][col] == 0) {
				flag = false;
			}
		}
	}
	row--;
	col--;
	return (! flag);
}

//	checks that row if the number is used or not
bool usedInRow(int arr[N][N], const int & row, const int & num) {
	bool flag = true;
	for (int i = 0; flag && i < N; i++) {
		if (arr[row][i] == num) {
			flag = false;
		}
	}
	return ! flag;
}

//	checks that column if the number is used or not
bool usedInCol(int arr[N][N], const int & col, const int & num) {
	bool flag = true;
	for (int i = 0; flag && i < N; i++) {
		if (arr[i][col] == num) {
			flag = false;
		}
	}
	return ! flag;
}

//	checks that 3 x 3 grid if the number is used or not
bool usedInGrid(int arr[N][N], const int & row, const int & col, const int & num) {
	bool flag = true;
	for (int i = 0; flag && i < 3; i++) {
		for (int j = 0; flag && j < 3; j++) {
			if (arr[i + row][j + col] == num) {
				flag = false;
			}
		}
	}
	return ! flag;
}

//	check if that number has been used in that row, col, and grid(3 x 3)
bool isSafe(int arr[N][N], const int & row, const int & col, const int & num) {
	
	return ((! usedInRow(arr, row, num))
			&& (! usedInCol(arr, col, num))
			&& (! usedInGrid(arr, row - row % 3, col - col % 3, num)));
}

bool sudokuSolver(int arr[N][N]) {
	int row, col;
	if (! findUnassigned(arr, row, col)) {
		cout << "Solution : \n";
		displayGrid(arr);
		return true;
	}
	
	bool flag = false;
	
	for (int num = 1; num <= 9; num++) {
		if (isSafe(arr, row, col, num)) {
			arr[row][col] = num;
			
			flag = sudokuSolver(arr) || flag;
			
			arr[row][col] = 0;
		}
	}
	return flag;
}

void sudoku() {
	int arr[9][9] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
		};	
	if (! sudokuSolver(arr)) {
		cout << "Solution does not exist \n";
	}
}

int main() {
	bool flag = true;
	int option;
	while (flag) {
		cout << "\n\n1.Sudoku solver.";
		cout << "\n0.Exit";
		cout << "\nEnter option...";
		cin >> option;
		switch (option) {
			case 1: {
				sudoku();
				break;
			}
			
			case 0: {
				flag = false;
				break;
			}
		}
	}
}
