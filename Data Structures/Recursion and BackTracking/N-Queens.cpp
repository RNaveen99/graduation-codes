/*
 * Developer : Naveen Rohilla
 * Objective : N - Queens problem
 */
 
 
#include <iostream>
using namespace std;

//	allocate memory to chessboard
void allocate(int ** & arr, const int & size) {
	arr = new int * [size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int [size] {0};
	}
}

//	deallocate memory of chessboard
void deallocate(int ** & arr, const int & size) {
	for (int i = 0; i < size; i++) {
		delete []arr[i];
	}
	delete []arr;
}

//	prints the chessboard
void display(int ** & arr, const int & size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

//	checks if Queen can be placed on that block
bool isSafe(int ** & arr, const int & size, const int & row, const int & col) {
	int i;
	int j;
	bool flag = true;
	if (flag) {
		//	checks the upper column
		for (i = 0; flag && i < row; i++) {
			if (arr[i][col]) {
				flag = false;
			}
		}
	}
	if (flag) {
		//	checks the upper left diagonal
		for (i = row - 1, j = col - 1; flag && i >= 0 && j >= 0; i--, j--) {
			if (arr[i][j]) {
				flag = false;
			}
		}
	}
	if (flag) {
		//	checks the upper right diagonal
		for (i = row - 1, j = col + 1; flag && i >= 0 && j < size ; i--, j++) {
			if (arr[i][j]) {
				flag = false;
			}
		}
	}
	return flag;
} 

//	solve NQ
bool solveNQ(int ** & arr, const int & size, int row = 0) {
	//	base condition
	//	if all queens are placed then return true
	if (row >= size) {
		return true;
	}
	
	//	consider this row and try placing this queen in all columns one at a time
	for (int i = 0; i < size; i++) {
		//	checks if Queen can be placed on board [row][i]
		if (isSafe(arr, size, row, i)) {
			//	place the Queen on board [row][i]
			arr[row][i] = 1;
			//	repeat this process with [row + 1] for rest of the Queens
			if (solveNQ(arr, size, row + 1)) {
				return true;
			}
			//	If placing queen in board[row][i] doesn't lead to a solution, then remove queen from board [row][i]
			arr[row][i] = 0;
		}
	}
	//	If the queen cannot be placed in any column in  this row then return false
	return false;
}

//	solve N - Queen
void solveNQueens() {
	int ** arr;
	int size;
	cout << "Enter size of chessboard : ";
	cin >> size;
	allocate(arr, size);
	if (solveNQ(arr, size)) {
		display(arr, size);
	}
	else {
		cout << "\nNo solution Possible";
	}
}


int main() {
	cout << "-----------------N - QUEENS----------------- ";
	bool flag = true;
	int opt;
	while (flag) {
		cout << "\n\n1.N - Queens problem";
		cout << "\n0.Exit";
		cout << "\nEnter choice...";
		cin >> opt;
		switch (opt) {
			case 1: {
				solveNQueens();
				break;
			}
			case 0: {
				flag = false;
				break;
			}
		}
	}
	return 0;
}

