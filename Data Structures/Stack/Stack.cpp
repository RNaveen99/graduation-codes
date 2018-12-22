#include <iostream>
using namespace std;
class Stack {
	int * arr;
	int size;
	int top;
	
	public:
	Stack(int s = 0) {
		size = s;
		arr = new int[size];
		top = -1;
	}
	
	bool isEmpty() {
		return (top == -1);
	}
	
	bool isFull() {
		return (top == size - 1);
	}
	
	int getSize() {
		return size;
	}
	
	void push(int num) {
		if (isFull()) {
			throw "Satck overflow";
		}
		arr[++top] = num;
	}
	
	int pop() {
		if (isEmpty()) {
			throw "Stack underflow";
		}
		return arr[top--];
	}
	
	void display() {
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << "\t";
		}
	}
};
/*
int main() {
	int size;
	cout << "Enter size of Stack : ";
	cin >> size;
	Stack s(size);
	bool flag = true;
	int ele;
	while (flag) {
		cout << "\n\n1.Push.";
		cout << "\t2.Pop";
		cout << "\t3.isEmpty.";
		cout << "\t4.isFull.";
		cout << "\t5.Display elements.";
		cout << "\t0.Exit.";
		cout << "\n\nEnter choice...";
		int option;
		cin >> option;
		switch (option) {
			
			case 1: {
				try {
					cout << "Enter element : ";
					cin >> ele;
					s.push(ele);
				} 
				catch(const char * p) {
					cout << p;
				}
				break;
			}
			
			case 2: {
				try {
					cout << s.pop();
				} 
				catch(const char * p) {
					cout << p;
				}
				break;
			}
			
			case 3: {
				cout << s.isEmpty();	
				break;
			}
			
			case 4: {
				cout << s.isFull();
				break;
			}
			
			case 5: {
				s.display();
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
*/
