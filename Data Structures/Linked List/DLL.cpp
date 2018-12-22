/*
 * Developer : Naveen Rohilla
 * Objective : Double Linked List using head and tail
 */
 
 
#include <iostream>
using namespace std;

template <typename T>
class node {
	public:
		T data;
		node *prev;
		node *next;		
		node(T ele = NULL, node * p = NULL, node * n = NULL) {
			data = ele;
			prev = p;
			next = n;
		}	
};

template <typename T>
class DLL {
	private:
		node<T> * head;
		node<T> * tail;	
	public:
		static int count;
		DLL() {
			head = 0;
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
//		friend DLL<T>& operator+(DLL<T> m, T n) {
//			m.addToTail(n);
//			return m;
//		}		
};
template <typename T>
int DLL<T> :: count=0;

//add element in the front of Linked List
template <typename T>
void DLL<T> :: addToHead(T ele) {
	node<T> * p = new node<T>(ele);
	if (head == 0) {
		head = p;
		tail = p;
	}
	else {
		p -> next = head;
		head -> prev = p;
		head = p;
	}	
	count++;
}

//add element at last of Linked List
template <typename T>
void DLL<T> :: addToTail(T ele) {
	node<T> * p = new node<T>(ele);
	if (tail == 0) {
		head = p;
		tail = p;
	}
	else {
		tail -> next = p;
		p -> prev = tail;
		tail = p;
	}
	count++;
}

//add element at the given position in Linked List
template <typename T>
void DLL<T> :: addToPos(int pos, T ele) {
	node<T> * p = new node<T>(ele);
	node<T> * temp = head;
	int i = 1;
	while (i != pos) {
		temp = temp -> next;
		i++;
	}
	if (pos == 1) {
		p -> next = head;
		head -> prev = p;
		head = p;
	}
	else {
		p -> next = (temp -> prev) -> next;
		p -> prev = temp -> prev;
		(temp -> prev) -> next = p;
		temp -> prev = p;		
	}
//		int i = 1;
//		while (i != pos - 1) {
//			temp = temp -> next;
//			i++;
//		}
//		p -> next = temp -> next;
//		temp -> next = p;
	count++;
}

//remove element from front
template <typename T>
void DLL<T> :: removeHead() {
	if (head == 0) {
		cout << "Linked list is empty";
	}
	else {
		node<T> * temp = head;
		head = head -> next;
		if (head == 0) {
			tail = 0;
		}
		else {
			head -> prev = NULL;
		}
		delete temp;
		
		count--;
	}
}

//remove element from tail
template <typename T>
void DLL<T> :: removeTail() {
	if(tail == 0) {
		cout << "Linked List is empty";
	}
	else {
		node<T> * temp = tail;
		if (tail -> prev == NULL) {
			head = tail = 0;
		}
		else {
			tail = tail -> prev;
			tail -> next = NULL;
		}
//		node<T> * temp = head;
//		node<T> * prev = 0;
//		while(temp != tail) {
//			prev = temp;
//			temp = temp -> next;
//		}
//		if (prev == NULL) {
//			head = tail = NULL;
//		}
//		else {
//			tail = prev;
//			tail -> next = NULL;
//		}
		delete temp;
		count--;
	}
}

//remove element from the given position
template <typename T>
void DLL<T> :: removeByPos(int pos) {
	node<T> * temp = head;
	int i = 1;
	while (i != pos) {
		temp = temp -> next;
		i++;
	}
	if (temp == head) {
		head = head -> next;
		if (head == 0) {
			tail = 0;
		}
		else {
			head -> prev = NULL;
		}
	}
	else if(temp == tail) {
		tail = tail -> prev;
		tail -> next = NULL;
	}
	else {
		(temp -> prev) -> next = temp -> next;
		(temp -> next) -> prev = temp -> prev;
		//prev -> next = temp -> next;
	}
	delete temp;
	count--;
	
}

//remove element By value
template <typename T>
void DLL<T> :: removeByValue(T ele) {
	node<T> * temp = head;
	//node<T> * prev = NULL;
	bool flag = true;
	while (temp != NULL) {
		if (temp -> data == ele) {
			if (temp == head) {
				removeHead();
				temp = head;
//				head = head -> next;
//				delete temp;
//				temp = head;
//				if (head == NULL) {
//					tail = NULL;
//				}
			}
			else if (temp == tail) {
				removeTail();
				temp = NULL;
//				prev -> next = NULL;
//				tail = prev;
//				delete temp;
//				temp = NULL;
			}
			else {
				(temp -> prev) -> next = temp -> next;
				(temp -> next) -> prev = temp -> prev;
				delete temp;
				count--;
//				prev -> next = temp -> next;
//				delete temp;
//				temp = prev -> next;
			}
			flag = false;	
		}
		else {
			//prev = temp;
			temp = temp -> next;
		}
	}
	if (flag) {
		cout << "Element not found";
	}
}

//display all the elements of the linked list
template <typename T>
void DLL<T> :: display() {
	if (head == NULL) {
		cout << "\nNo element in Linked List\n";
	}
	else {
		node<T> * temp = head;
		cout << "Total no. of elements = " << count << endl;
		while (temp != 0) {
			cout << temp -> data << "\t";
			temp = temp -> next;
		}
		
		cout << endl;
		temp = tail;
		while (temp != 0) {
			cout << temp -> data << "\t";
			temp = temp -> prev;
		}
		
	}
}



int main() {
	//DLL <int>* m  = new DLL<int>();
	DLL <int>m;
	bool flag = true;
	int ele;
	while (flag) {
		cout << "\n\n1.Add to Head.";
		cout << "\t2.Add to Tail.";
		cout << "\t3.Add to Position.";
		cout << "\t4.Remove from head.";
		cout << "\t5.Remove from tail";
		cout << "\t6.Remove By Position.";
		cout << "\t7.Remove By value.";
		cout << "\t8.Size of Linked list.";
		cout << "\t9.Display elements.";
		cout << "\t0.Exit.";
		cout << "\n\nEnter choice...";
		int option0;
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
				cout << "Enter value";
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

