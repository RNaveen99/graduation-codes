#include <iostream>
using namespace std;
#include "Deque.cpp"
int main() {
	bool flag = true;
	cout << "Enter size of Deque :";
	int size;
	cin >> size;
	Deque <int> q(size);
	int ele;
	do {
		cout << "\n\n1.Enter ele from front";
		cout << "\t\t2.Enter ele from rear";
		cout << "\n3.Delete ele from front";
		cout << "\t\t4.Delete ele from rear";
		cout << "\n5.Display";
		cout << "\t0.Exit";
		cout << "\nOption...";
		int option;
		cin >> option;
		try {
			switch (option) {
				case 1: {
					cout << "Enter element :";
					cin >> ele;
					q.addToFront(ele);
					break;
				}
				
				case 2: {
					cout << "Enter element :";
					cin >> ele;
					q.enqueue(ele);
					break;
					break;
				}
			
				case 3: {
					cout << "Element Removed : "<< q.dequeue();
					break;
				}
				
				case 4: {
					cout << "Element Removed : " << q.removeFromRear();
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
