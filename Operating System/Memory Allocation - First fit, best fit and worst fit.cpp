#include <iostream>
using namespace std;
struct Process {
	int id;
	int size;
	int sizeLeft;
	int blockNum;
	bool flag;
};

void enterMemory(int * & memory, int & size, int * & arr) {
	cout << "Enter the no. of memory blocks : ";
	cin >> size;
	memory = new int[size];
	arr = new int[size];
	cout << "Enter the size of each block :";
	for (int i = 0; i < size; i++) {
		cin >> memory[i];
	}
}

void copyM(Process * & p, const int & num, int * & memory, int * &arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = memory [i];
	}
	for (int i = 0; i < num; i++) {
		p[i].flag = false;
	}
}

void enterProcess(Process * & p, int & num) {
	cout << "Enter the no. of processes : ";
	cin >> num;
	p = new Process[num];
	cout << "Enter the size of each Process :";
	for (int i = 0; i < num; i++) {
		cin >> p[i].size;
		p[i].flag = false;
		p[i].id = i + 1;
	}
}

void firstFit(int *arr, const int & size, Process * p, const int & num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[j] >= p[i].size) {
				p[i].blockNum = j + 1;
				p[i].flag = true;
				p[i].sizeLeft = arr[j] = arr[j] - p[i].size;
				break;
			}
		}
	}
}

void bestFit(int *arr, const int & size, Process * p, const int & num) {
	cout << "\n\nBest fit\n";
	int min;
	for (int i = 0; i < num; i++) {
		min = -1;
		for (int j = 0; j < size; j++) {
			if (arr[j] >= p[i].size)  {
				if (min == -1) {
					min = j;
				}
				else if ((min != -1) && (arr[j] < arr[min])) {
					min = j;
				}
			}
		}
		if (min != -1) {
			p[i].blockNum = min + 1;
			p[i].flag = true;
			p[i].sizeLeft = arr[min] = arr[min] - p[i].size;
		}
	}
}

void worstFit(int *arr, const int & size, Process * p, const int & num) {
	cout << "\n\nWorst fit\n";
	int max;
	for (int i = 0; i < num; i++) {
		max = -1;
		for (int j = 0; j < size; j++) {
			if (arr[j] >= p[i].size)  {
				if (max == -1) {
					max = j;
				}
				else if ((max != -1) && (arr[j] > arr[max])) {
					max = j;
				}
			}
		}
		if (max != -1) {
			p[i].blockNum = max + 1;
			p[i].flag = true;
			p[i].sizeLeft = arr[max] = arr[max] - p[i].size;
		}
	}
}


void display(Process * p, const int & num) {
	for (int i = 0; i < num; i++) {
		if (p[i].flag == true) {
			cout << "Process " << p[i].id << " of size " << p[i].size << " Assigned in Memory block  " << p[i].blockNum << "-------- size left = " << p[i].sizeLeft << endl;
		}
	}
	for (int i = 0; i < num; i++) {
		if (p[i].flag == false) {
			cout << "Process " << p[i].id << " is Waiting " << endl;
		}
	}
}
int main() {
	int *memory;
	int *arr;
	int size;
	Process *p;
	int num;
	
	enterMemory(memory, size, arr);
	enterProcess(p, num);
	
	copyM(p, num, memory, arr, size);
	firstFit(arr, size, p, num);
	display(p, num);
	
	copyM(p, num, memory, arr, size);
	bestFit(arr, size, p, num);
	display(p, num);
	
	copyM(p, num, memory, arr, size);
	worstFit(arr, size, p, num);
	display(p, num);
	return 0;
}
