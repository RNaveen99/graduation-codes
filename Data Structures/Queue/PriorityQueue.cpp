/*
 * Developer : Naveen Rohilla
 * Objective : Priority Queue
 */
 
 
#include <iostream>
using namespace std;

template <typename T>
class node {
	public:
		T data;
		int priority;
		node *next;		
		node(T ele = NULL, int p = 0) {
			data = ele;
			priority = p;
			next = NULL;
		}	
};

template <typename T>
class PriorityQueue {
	private:
		node<T> * head;
		node<T> * tail;	
		
		void addToHead(T, int);
		void addToTail(T, int);
	
	public:
		static int count;
		PriorityQueue() {
			head = 0;
			tail = 0;
		}	
		void insert(T, int);
		void removeHead();
		void removeTail();
		void display();	
		int getCount();	
};
template <typename T>
int PriorityQueue<T> :: getCount() {
	return this -> count;
}
template <typename T>
int PriorityQueue<T> :: count=0;

//add element in the front of Linked List
template <typename T>
void PriorityQueue<T> :: addToHead(T ele, int prior) {
	node<T> * p = new node<T>(ele, prior);
	if (head == 0) {
		head = p;
		tail = p;
	}
	else {
		p -> next = head;
		head = p;
	}	
	count++;
}

//add element at last of Linked List
template <typename T>
void PriorityQueue<T> :: addToTail(T ele, int prior) {
	node<T> * p = new node<T>(ele, prior);
	if (tail == 0) {
		head = p;
		tail = p;
	}
	else {
		tail -> next = p;
		tail = p;
	}
	count++;
}

//remove element from front
template <typename T>
void PriorityQueue<T> :: removeHead() {
	if (head == 0) {
		cout << "Linked list is empty";
	}
	else {
		node<T> * temp = head;
		head = head -> next;
		delete temp;
		if (head == 0) {
			tail = 0;
		}
		count--;
	}
}

//remove element from tail
template <typename T>
void PriorityQueue<T> :: removeTail() {
	if(tail == 0) {
		cout << "Linked List is empty";
	}
	else {
		node<T> * temp = head;
		node<T> * prev = 0;
		while(temp != tail) {
			prev = temp;
			temp = temp -> next;
		}
		if (prev == NULL) {
			head = tail = NULL;
		}
		else {
			tail = prev;
			tail -> next = NULL;
		}
		delete temp;
		count--;
	}
}

//display all the elements of the linked list
template <typename T>
void PriorityQueue<T> :: display() {
	if (head == NULL) {
		cout << "\nNo element in Linked List\n";
	}
	else {
		node<T> * temp = head;
		cout << "Total no. of elements = " << count << endl;
		while (temp != 0) {
			cout << "\ndata =" << temp -> data << "  " << "priority =" << temp -> priority << "\t";
			temp = temp -> next;
		}
		
	}
}


template <typename T>
void PriorityQueue<T> :: insert(T ele, int prior) {
	
	if (this -> head == NULL) {
		this -> addToHead(ele, prior);
	}
	else if (prior < this -> head -> priority) {
		this -> addToHead(ele, prior);
	}
	else if (prior > this -> tail -> priority) {
		this -> addToTail(ele, prior);
	}
	else {
		node<T> * p = new node<T>(ele, prior);
		node<T> * temp = this -> head;
		node<T> * prev = NULL;
		while (temp -> priority < prior) {
			prev = temp;
			temp = temp -> next;
		}
		p -> next = prev -> next;
		prev -> next = p;
		this -> count++;
	}
} 

int main() {
	PriorityQueue <int>m;
	bool flag = true;
	int ele;
	int prior;
	while (flag) {
		cout << "\n\n1.Insert element";
		cout << "\t2.Remove from head.";
		cout << "\t3.Remove from tail";
//		cout << "\t4.Remove By Position.";
//		cout << "\t5.Remove By value.";
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
				cout << "Enter priority :";
				cin >> prior;
				m.insert(ele, prior);
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

