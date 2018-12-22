/*
 * Developer : Naveen Rohilla
 * Objective : Simple Sorted Linked List
 */
 
 
#include <iostream>
#include "SSLL1.cpp"
using namespace std;
template <typename T>
class SSLL : private SLL<T> {
	public:
		using SLL<T> :: removeHead;
		using SLL<T> :: removeTail;
		using SLL<T> :: removeByValue;
		using SLL<T> :: removeByPos;
		using SLL<T> :: display;
		SSLL() {
			this -> head = this -> tail = 0;
		}
		void insert(T);
		int getCount();
};

template <typename T>
void SSLL<T> :: insert(T ele) {
	node<T> * p = new node<T>(ele);
	if (this -> head == NULL) {
		this -> addToHead(ele);
	}
	else if (ele < this -> head -> data) {
		this -> addToHead(ele);
	}
	else if (ele > this -> tail -> data) {
		this -> addToTail(ele);
	}
	else {
		node<T> * temp = this -> head;
		node<T> * prev = NULL;
		while (temp -> data < ele) {
			prev = temp;
			temp = temp -> next;
		}
		p -> next = prev -> next;
		prev -> next = p;
		this -> count++;
	}
} 

template <typename T>
int SSLL<T> :: getCount() {
	return this -> count;
}
int main() {
	SSLL <int>m;
	bool flag = true;
	int ele;
	while (flag) {
		cout << "\n\n1.Insert element";
		cout << "\t2.Remove from head.";
		cout << "\t3.Remove from tail";
		cout << "\t4.Remove By Position.";
		cout << "\t5.Remove By value.";
		cout << "\t6.Size of Linked list.";
		cout << "\t7.Display elements.";
		cout << "\t0.Exit.";
		cout << "\n\nEnter choice...";
		int option;
		cin >> option;
		switch (option) {
			
			case 1: {
				cout << "Enter element : ";
				cin >> ele;
				m.insert(ele);
				break;
			}
			
			case 2: {
				m.removeHead();
				break;
			}
			
			case 3: {
				m.removeTail();
				break;
			}
			
			case 4: {
				try {
					cout << "Enter position:";
					int pos;
					cin >> pos;
					if (pos <= 0 || pos > m.getCount()) {
						throw "Invalid position";
					}
					m.removeByPos(pos);
				}
				catch(const char * p) {
					cout << p;
				}
				break;
			}
			
			case 5: {
				cout << "Enter value";
				cin >> ele;
				m.removeByValue(ele);
				break;
			}
			case 6: {
				cout << "Total no. of elements = " << m.getCount();
				break;
			}
			case 7: {
				m.display();
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

