#include <iostream>
using namespace std;
class MatrixLT {
	private:	
		int *arr;
		int size;
	
	public:
		MatrixLT(int s = 0) {
			if (s < 0) {
				throw "Invalid size ";
			}
			size = s;
			arr = new int[(size * (size + 1)) / 2] {0};
		}
		
		void set(int i, int j, int value) {
			if (i < 0 || i > size || j < 0 || j > size) {
				throw "Invalid Index";
			}
			else if ((i < j) && (value != 0)) {
				throw "Invalid value for the given index";
			}
			else {
				arr[((i * (i + 1)) / 2) + j] = value;
			}
		}
		
		int get(int i, int j) {
			if (i < 0 || i > size || j < 0 || j > size) {
				throw "Invalid Index";
			}
			else if (j > i) {
				return 0;
			}
			else {
				return arr[((i * (i + 1)) / 2) + j];
			}
		}
		
		void print() {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size ; j++) {
					if (i < j) {
						cout << "0";
					}
					else {
						cout << arr[((i * (i + 1)) / 2) + j];
					}
					cout << "\t";
				}
				cout << endl;
			}
		}
		MatrixLT() {
			delete []arr;
		}
};
int main() {
	bool flag = true;
	while (flag) {
		try {
			cout << "Enter size of the matrix : ";
			int size;
			cin >> size;
			MatrixLT m(size);
			while (flag) {
				cout << "\n1.Enter element.";
				cout << "\n2.Get element.";
				cout << "\n3.view matrix.";
				cout << "\n4.Exit.";
				int option;
				cout << "\nEnter option :";
				cin >> option;
				switch(option) {
					case 1:	{
							cout << "\nEnter i:";
							int i;
							cin >> i;
							cout << "Enter j:";
							int j;
							cin >> j;
							cout << "Enter value:";
							int value;
							cin >> value;
							m.set(i, j, value);
							break;
					}
					case 2: {
							cout << "\nEnter i:";
							int i;
							cin >> i;
							cout << "Enter j:";
							int j;
							cin >> j;
							cout << m.get(i, j);
							break;
					}
					case 3: {
							m.print();
							break;
					}
					case 4: {
						flag = false;
						break;
					}	
				}	
			}	
		}
		catch(const char * p) {
		cout << p;
		}
	}
}
