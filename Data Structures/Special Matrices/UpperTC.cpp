#include <iostream>
using namespace std;
class UpperTC {
	private:
		int *data;
		int size;
		
	public:
		UpperTC (int s) {
			if (s < 0) {
				throw "Size can't be negative";
			}
			size = s;
			data = new int[(s * (s + 1)) / 2] {0};
		}
				
		void set(int i, int j, int value) {
			if (i <= 0 || j <= 0 || i > size || j > size) {
				throw "index not in range";
			}
			else if ((i > j) && (value != 0)) {
				throw "invalid input for lower triangular matrix";
			}
			else if (i <= j) {
				int k = ((j * (j - 1)) / 2)	+ (i -1) ;
				data[k] = value;
				cout << "k=" << k << "data=" << data[k] << endl;
			}
		}			
		
		int get(int i, int j) {
			if (i <= 0 || j <= 0 || i > size || j > size) {
				throw "index not in range";
			}
			int value;
			if (i > j) {
				value = 0;
			}
			else if (i <= j) {
				value = data[((j * (j - 1)) / 2) + (i -1)];
			}
			return value;
		}
		
		UpperTC(UpperTC & ob) {
			size = ob.size;
			data = new int[(size * (size + 1)) / 2];
			for (int i = 0; i < size; i++) {
				data[i] = ob.data[i];
			}
		}	
		
		UpperTC & operator=(UpperTC & ob) {
			if (this == & ob) {
				return *this;
			}
			else if (size != ob.size) {
				delete []data;
				size = ob.size;
				data = new int[(size * (size + 1)) / 2];
			}			
			for (int i = 0; i < size; i++) {
				data[i] = ob.data[i];
			}
			return *this;
		}		
		~UpperTC() {
			delete []data;
		}		
};
int main() {
	int size;
	do {
		try {
			cout << "\nEnter size of matrix:";
			cin >> size;
			if (size < 0) {
				throw "Size can't be negative.Try again..";
			}	
		}
		catch(const char * p) {
			cout << p;
		}		
	}while (size < 0);
	
	UpperTC m(size);
	bool flag = true;
	do {
		try {
			cout << "\n1.Enter elements.";
			cout << "\n2.Get elements.";
			cout << "\n3.Exit.";
			cout << "\nEnter option...";
			int option;
			cin >> option;
			switch(option) {
				case 1: {
					cout << "Enter Values:" << endl;
					for (int i = 1; i <= size; i++) {
						int value;
						for (int j = 1; j <= size ; j++) {
							cin >> value;
							m.set(j, i, value);
						}
					}
					break;
				}
				case 2: {
					for (int i = 1; i <= size; i++) {
						for (int j = 1; j <= size ; j++) {
							cout << m.get(i, j) << "\t";
						}
						cout << endl;
					}
					break;
				}
				case 3: {
					flag = false;
					break;
				}
			}
		}
		catch(const char * p) {
			cout << p;
		}	
	}while (flag);					
	
	return 0;
}			

