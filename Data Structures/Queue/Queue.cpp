#include <iostream>
using namespace std;
template <typename T>
class Queue {
	protected:
		T * arr;
		int size;
		int front;
		int rear;
		
	public:
		Queue(int s = 0) {
			size = s;
			arr = new T[size];
			front = rear = -1;
		}
		
		bool isEmpty() {
			return (front == -1);
		}
		
		bool isFull() {
			return (((rear + 1) % size) == front);
		}
		
		void enqueue(T x) {
			if (isFull()) {
				throw "Queue overflow";
			}
			if (isEmpty()) {
				front = rear = 0;
			}
			else {
				rear = (rear + 1) % size;
			}
			arr[rear] = x;
		}
		
		T dequeue() {
			if (isEmpty()) {
				throw "Queue underflow";
			}
			T temp = arr[front];
			if (front == rear) {
				front = rear = -1;
			}
			else {
				front = (front + 1) % size;
			}
			return temp;
		}
		void display() {
			if (isEmpty()) {
				cout << "Queue is Empty";
			}
			else {
				int i = front;
				while (i != rear) {
					cout << arr[i] << "\t";
					i = (i + 1) % size;
				}
				cout << arr[rear];
			}
//			else if (front <= rear) {
//				for (int i = front; i <= rear; i++) {
//					cout << arr[i] << "\t";
//				}
//			}
//			else {
//				for (int i = front; i < size; i++) {
//					cout << arr[i] << "\t";
//				}
//				for (int i = 0; i <= rear; i++) {
//					cout << arr[i] << "\t";
//				}
//			}
		}
};
//
//int main() {
//	bool flag = true;
//	cout << "Enter size of Queue :";
//	int size;
//	cin >> size;
//	Queue <int> q(size);
//	int ele;
//	do {
//		cout << "\n1.Enter element";
//		cout << "\t2.Delete element";
//		cout << "\t3.isEmpty";
//		cout << "\t4.isFull";
//		cout << "\t5.Display";
//		cout << "\t0.Exit";
//		cout << "\nOption...";
//		int option;
//		cin >> option;
//		try {
//			switch (option) {
//				case 1: {
//					cout << "Enter element :";
//					cin >> ele;
//					q.enqueue(ele);
//					break;
//				}
//			
//				case 2: {
//					cout << "Element Removed : "<< q.dequeue();
//					break;
//				}
//			
//				case 3: {
//					cout << q.isEmpty();
//					break;
//				}
//			
//				case 4: {
//					cout << q.isFull();
//					break;
//				}
//			
//				case 5: {
//					q.display();
//					break;
//				}
//			
//				case 0: {
//					flag = false;
//					break;
//				}
//			}
//		}
//		catch (const char * p) {
//			cout << p << endl;
//		}	
//	} while (flag);
//	return 0;
//}
