/*
 * Developer : Naveen Rohilla
 * Objective : Simple Linked List using only head
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
class SLL {
	private:
		node<T> * head;	
	public:
		static int count;
		SLL() {
			head = 0;
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
int SLL<T> :: count=0;

//add element in the front of Linked List
template <typename T>
void SLL<T> :: addToHead(T ele) {
	node<T> * p = new node<T>(ele);
	if (head == 0) {
		head = p;
	}
	else {
		p -> next = head;
		head = p;
	}	
	count++;
}

//add element at last of Linked List
template <typename T>
void SLL<T> :: addToTail(T ele) {
	node<T> * p = new node<T>(ele);
	if (head == 0) {
		head = p;
	}
	else {
		node<T> * temp = head;
		while (temp -> next != 0) {
			temp = temp -> next;
		}
		temp -> next = p;
	}
	count++;
}

//add element at the given position in Linked List
template <typename T>
void SLL<T> :: addToPos(int pos, T ele) {
	node<T> * p = new node<T>(ele);
	node<T> * temp = head;
	node<T> * prev = NULL;
	int i = 1;
	while (i != pos) {
		prev = temp;
		temp = temp -> next;
		i++;
	}
	if (prev == NULL) {
		p -> next = head;
		head = p;
	}
	else {
		p -> next = prev -> next;
		prev -> next = p;
	}
	count++;
}

//remove element from the head
template <typename T>
void SLL<T> :: removeHead() {
	if (head == NULL) {
		cout << "Linked List is empty";
	}
	else {
		node<T> * temp = head;
		head = head -> next;
		delete temp;
		count--;
	}
}

//remove element from the tail
template <typename T>
void SLL<T> :: removeTail() {
	if (head == NULL) {
		cout << "Linked List is empty";
	}
	else {
		node<T> * temp = head;
		node<T> * prev = NULL;
		while (temp -> next != NULL) {
			prev = temp;
			temp = temp -> next;
		}
		if (prev == NULL) {
			head = NULL;
		}
		else {
			prev -> next = NULL;	
		}
		delete temp;
		count--;
	}
}

//remove element from the given position
template <typename T>
void SLL<T> :: removeByPos(int pos) {
	node<T> * temp = head;
	node<T> * prev = NULL;
	int i = 1;
	while (i != pos) {
		prev = temp;
		temp = temp -> next;
		i++;
	}
	if (prev == NULL) {
		head = head -> next;
	}
	else {
		prev -> next = temp -> next;
	}
	delete temp;
	count --;
}

//remove element By value
template <typename T>
void SLL<T> :: removeByValue(T ele) {
	node<T> * temp = head;
	node<T> * prev = NULL;
	bool flag = true;
	while (temp != NULL) {
		if (temp -> data == ele) {
			if (prev == NULL) {
				head = head -> next;
				delete temp;
				temp = head;
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
		}
	}
	if (flag) {
		cout << "Element not found";
	}
}

//display all the elements of the linked list
template <typename T>
void SLL<T> :: display() {
	node<T> * temp = head;
	if (head == 0) {
		cout << "\nNo element in Linked List\n";
	}
	else {
		cout << "Total no. of elements = " << count << endl;
		while (temp != 0) {
			cout << temp -> data << "\t";
			temp = temp -> next;
		}
		
	}
}

int main() {
	SLL <int>m;
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

