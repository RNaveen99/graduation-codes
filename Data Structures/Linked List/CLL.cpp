/*
 * Developer : Naveen Rohilla
 * Objective : Circular Linked List using only tail
 */
 
 
#include <iostream>
using namespace std;

template <typename T>
class node {
	public:
		T data;
		node<T> *next;		
		node(T ele = NULL) {
			data = ele;
			next = 0;
		}	
};

template <typename T>
class CLL {
	private:
		node<T> * tail;	
	public:
		static int count;
		CLL() {
			tail = 0;
		}
		void addToHead(T);
		void addToTail(T);
		void addToPos(int, T);
		void removeHead();
		void removeTail();
		void removeByPos(int);
		void removeByValue(T);
		void display();		
};

template <typename T>
int CLL<T> :: count=0;

//add element in the front of Linked List
template <typename T>
void CLL<T> :: addToHead(T ele) {
	node<T> * p = new node<T>(ele);
	if (tail == 0) {
		tail = p;
		tail -> next = p;
	}
	else {
		p -> next = tail -> next;
		tail -> next = p;
	}	
	count++;
}

//add element at last of Linked List
template <typename T>
void CLL<T> :: addToTail(T ele) {
	node<T> * p = new node<T>(ele);
	if (tail == 0) {
		tail = p;
		tail -> next = p;
	}
	else {
		p -> next = tail -> next;
		tail -> next = p;
		tail = p;
	}
	count++;
}

//add element at the given position in Linked List
template <typename T>
void CLL<T> :: addToPos(int pos, T ele) {
	node<T> * p = new node<T>(ele);
	node<T> * temp = tail -> next;
	node<T> * prev = NULL;
	int i = 1;
	while (i != pos) {
		prev = temp;
		temp = temp -> next;
		i++;
	}
	if (prev == NULL) {
		p -> next = tail -> next;
		tail -> next = p;
	}
	else {
		p -> next = prev -> next;
		prev -> next = p;
	}
	count++;
}

//remove element from the head
template <typename T>
void CLL<T> :: removeHead() {
	if (tail == NULL) {
		cout << "Linked List is empty";
	}
	else {
		node<T> * temp = tail -> next;
		if (tail -> next == tail) {
			tail = 0;
		}
		else {
			tail -> next = (tail -> next) -> next;
		}
		delete temp;
		count--;
	}
}

//remove element from the tail
template <typename T>
void CLL<T> :: removeTail() {
	if (tail == NULL) {
		cout << "Linked List is empty";
	}
	else {
		node<T> * temp = tail -> next;
		node<T> * prev = NULL;
		while (temp != tail) {
			prev = temp;
			temp = temp -> next;
		}
		if (prev == NULL) {
			tail = NULL;
		}
		else {
			prev -> next = tail -> next;
			tail = prev;	
		}
		delete temp;
		count--;
	}
}

//remove element from the given position
template <typename T>
void CLL<T> :: removeByPos(int pos) {
	node<T> * temp = tail -> next;
	node<T> * prev = NULL;
	int i = 1;
	while (i != pos) {
		prev = temp;
		temp = temp -> next;
		i++;
	}
	if (prev == NULL) {
		//head = head -> next;
		tail -> next = (tail -> next) -> next;
	}
	else if (temp == tail) {
		prev -> next = tail -> next;
		tail = prev;
	}
	else {
		prev -> next = temp -> next;
	}
	delete temp;
	count --;
}

//remove element By value
template <typename T>
void CLL<T> :: removeByValue(T ele) {
	node<T> * temp = tail -> next;
	node<T> * prev = NULL;
	bool flag = true;
	while (temp != NULL) {
		if (temp -> data == ele) {
			if (prev == NULL) {
				//head = head -> next;
				if (tail -> next == tail) {
					tail = 0;
					delete temp;
					temp = NULL;;
				}
				else {
					tail -> next = (tail -> next) -> next;
					delete temp;
					temp = tail -> next;
				}
			}
			else if (temp == tail) {
				prev -> next = tail -> next;
				delete temp;
				tail = prev;
				temp = NULL;
			}
			else {
				prev -> next = temp -> next;
				delete temp;
				temp = prev -> next;
			}
			count--;
			flag = false;	
		}
		else {
			prev = temp;
			temp = temp -> next;
			if (temp == tail -> next) {
				temp = NULL;
			}
		}
	}
	if (flag) {
		cout << "Element not found";
	}
}

//display all the elements of the linked list
template <typename T>
void CLL<T> :: display() {
	if (tail == 0) {
		cout << "\nNo element in Linked List\n";
	}
	else {
		node<T> * temp = tail -> next;
		cout << "Total no. of elements = " << count << endl;
		do {
			cout << temp -> data << "\t";
			temp = temp -> next;
		} while (temp != tail -> next);
		
	}
}

int main() {
	CLL <int>m;
	bool flag = true;
	int ele;
	while (flag) {
		cout << "\n\n1.Add to Head.";
		cout << "\t2.Add to Tail.";
		cout << "\t3.Add to Position";
		cout << "\t4.Remove from head";
		cout << "\t5.Remove from tail";
		cout << "\t6.Remove By Position.";
		cout << "\t7.Remove By value";
		cout << "\t8.Size of Linked list";
		cout << "\t9.Display elements.";
		cout << "\t0.Exit.";
		cout << "\n\nEnter choice...";
		int option;
		cin >> option;
		switch (option) {
			
			case 1: {
				cout << "Enter element : ";
				cin >> ele;
				m.addToHead(ele);
				break;
			}
			
			case 2: {
				cout << "Enter element : ";
				cin >> ele;
				m.addToTail(ele);
				break;
			}
			
			case 3: {
				try {
					cout << "Enter position : ";
					int pos;
					cin >> pos;
					if (pos <= 0 || pos > m.count) {
						throw "invalid position";
					}
					cout << "Enter element : ";
					cin >> ele;
					m.addToPos(pos, ele);
				} 
				catch(const char * p) {
					cout << p;
				}	
				break;
			}
			
			case 4: {
				m.removeHead();
				break;
			}
			
			case 5: {
				m.removeTail();
				break;
			}
			case 6: {
				try {
					cout << "Enter position:";
					int pos;
					cin >> pos;
					if (pos <= 0 || pos > m.count) {
						throw "Invalid position";
					}
					m.removeByPos(pos);
				}
				catch(const char * p) {
					cout << p;
				}
				break;
			}
			
			case 7: {
				cout << "Enter value : ";
				cin >> ele;
				m.removeByValue(ele);
				break;
			}
			case 8: {
				cout << "Total no. of elements = " << m.count;
				break;
			}
			case 9: {
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

