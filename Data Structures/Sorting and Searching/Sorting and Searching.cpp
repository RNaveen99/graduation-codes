/*
 * Developer : Naveen Rohilla
 * Objective : Sorting and Searching
 */
 
 
#include <iostream>
using namespace std;

void allocate(int * & arr, const int & size, bool flag) {
	if (arr == NULL) {
		arr = new int [size];
	}
	else if (flag) {
		delete [] arr;
		arr = new int [size];
	}
}

void enter(int * & arr, const int & size) {
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void display(int * & arr, const int & size) {
	cout << endl;
	for (int i =0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}

void bubbleSort(int * & arr, const int & size) {
	bool flag;
	for (int i = 0; i < size - 1 ; i++) {
		flag = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if (! flag) {
			break;
		}
	}
}

void selectionSort(int * & arr, const int & size) {
	for (int i = 0; i < size - 1; i++) {
		int index = i;
		int min = arr[i];
		for (int j = i + 1 ; j < size; j++) {
			if (arr[j] > min) {
				index = j;
				min = arr[j];
			} 
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

void insertionSort(int * & arr, const int & size) {
	for (int i = 1; i < size; i++) {
		int min = arr[i];
		int j = i - 1;
		while (arr[j] > min && j >= 0) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] =min;
	}
}

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2; 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 
		merge(arr, l, m, r); 
	} 
} 


void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

int linearSearch(int * & arr, const int & size, const int & ele) {
	bool flag = true;
	int i = 0;
	while (i < size && flag) {
		if (arr[i] == ele) {
			flag = false;
		}
		i++;
	}
	if (flag) {
		i = -1;
	}
	else {
		i --;
	}
	return i;
}

int binarySearch(int * & arr, const int & size, const int & ele) {
	int first, last;
	first = 0;
	last = size - 1;
	int mid;
	bool flag = true;
	while (first <= last && flag) {
		mid = (first + last) / 2;
		if (arr[mid] == ele) {
			flag = false;
		}
		else if (arr[mid] > ele) {
			last = mid - 1;
		}
		else if (arr[mid] < ele) {
			first = mid + 1;
		}
	}
	if (flag) {
		mid = -1;
	}
	return mid;
}


int main() {
	bool flag1, flag2, flag3, flag4;
	int opt;
	int size, prevSize;
	int * arr = NULL;
	flag1 = flag2 = flag3 = flag4 = true;
	while (flag1) {
		flag1 = flag2 = flag3 = true;
		cout << "\n1.Enter elements.";
		cout << "\n0.Exit.";
		cout << "\nEnter option...";
		cin >> opt;
		switch (opt) {
			case 1: {
				flag3 = true;
				cout << "\nEnter size :";
				cin >> size;
				if (flag4) {
					flag4 = false;
				}
				else if (size == prevSize) {
					flag3 = false;
				}
				allocate(arr, size, flag3);
				prevSize = size;
				cout << "Enter elements :";
				enter(arr, size);
				
				flag2 = true;
				while (flag2) {
					cout << "\n\n1.Bubble sort";
					cout << "\n2.Selection sort";
					cout << "\n3.Insertion sort";
					cout << "\n4.Merge Sort";
					cout << "\n5.Quick Sort";
					cout << "\n6.Linear Search.";
					cout << "\n7.Binary Search";
					cout << "\n8.Display";
					cout << "\n9.Previous menu";
					cout << "\n0.Exit";
					cout << "\nEnter option...";
					cin >> opt;
					switch (opt) {
						case 1: {
							bubbleSort(arr, size);
							break;
						}
						
						case 2: {
							selectionSort(arr, size);
							break;
						}
						
						case 3: {
							insertionSort(arr, size);
							break;
						}
						
						case 4: {
							mergeSort(arr, 0, size - 1);
							break;
						}
						
						case 5: {
							quickSort(arr, 0, size - 1);
							break;
						}
						
						case 6: {
							cout << "Enter element to be searched...";
							int ele;
							cin >> ele;
							cout << linearSearch(arr, size, ele);
							break;
						}
						
						case 7: {
							cout << "Enter element to be searched...";
							int ele;
							cin >> ele;
							cout << binarySearch(arr, size, ele);
							break;
						}
						
						case 8: {
							display(arr, size);
							break;
						}
						case 9: {
							flag2 = false;
							break;
						}
						
						case 0: {
							flag2 = flag1 = false;
							break;
						}
					}
				}
				break;
			}
			
			case 0: {
				flag1 = false;
				break;
			}
		}
	}
	
	return 0;
}

