#include <iostream>
using namespace std;
#include "Queue.cpp"
int main() {
	bool flag = true;
	cout << "Enter size of Queue :";
	int size;
	cin >> size;
	Queue <int> q(size);
	int ele;
	do {
		cout << "\n1.Enter element";
		cout << "\t2.Delete element";
		cout << "\t3.isEmpty";
		cout << "\t4.isFull";
		cout << "\t5.Display";
		cout << "\t0.Exit";
		cout << "\nOption...";
		int option;
		cin >> option;
		try {
			switch (option) {
				case 1: {
					cout << "Enter element :";
					cin >> ele;
					q.enqueue(ele);
					break;
				}
			
				case 2: {
					cout << "Element Removed : "<< q.dequeue();
					break;
				}
			
				case 3: {
					cout << q.isEmpty();
					break;
				}
			
				case 4: {
					cout << q.isFull();
					break;
				}
			
				case 5: {
					q.display();
					break;
				}
			
				case 0: {
					flag = false;
					break;
				}
			}
		}
		catch (const char * p) {
			cout << p << endl;
		}	
	} while (flag);
	return 0;
}
