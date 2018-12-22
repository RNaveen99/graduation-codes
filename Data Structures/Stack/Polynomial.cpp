/*
 * Developer : Naveen Rohilla
 * Objeetive : Polynomail
 */
 
 
#include <iostream>
using namespace std;

class node {
	public:
		float data;
		int expo;
		node * next;
		node(float ele, int e = 0) {
			data = ele;
			expo = e;
			next = NULL;
		}
};
class Polynomial {
	private:
		node * head;
		node * tail;
	public:
	Polynomial() {
		head = 0;
		tail = 0;
	}
	void addToHead(float, int);
	void addToTail(float, int);
	void enter();
	void insert(float, int);
	void display();
	Polynomial(Polynomial& p) {
		head = tail = 0;
		node * temp = p.head;
		node * prev = 0;
		while (temp != 0) {
			addToTail(temp -> data, temp -> expo);
			prev = temp;
			temp = temp -> next;
		}
		tail = prev;
	}
	
	Polynomial& operator=(const Polynomial& p) {
		head = tail = 0;
		node * temp = p.head;
		node * prev = 0;
		while (temp != 0) {
			addToTail(temp -> data, temp -> expo);
			prev = temp;
			temp = temp -> next;
		}
		tail = prev;
		return *this;
	}
	
	Polynomial& operator+(const Polynomial& p) {
		Polynomial t;
		node * temp1 = head;
		node * temp2 = p.head;
		
		while (temp1 != 0 && temp2 != 0) {
			if ((temp1 -> expo == temp2 -> expo) && (temp1 -> data + temp2 -> data != 0)) {
				t.addToTail((temp1 -> data + temp2 -> data), temp1 -> expo);
				temp1 = temp1 -> next;
				temp2 = temp2 -> next;
			}
			else if (temp1 -> expo > temp2 -> expo) {
				t.addToTail(temp1 -> data, temp1 -> expo);
				temp1 = temp1 -> next;
			}
			else if (temp1 -> expo < temp2 -> expo) {
				t.addToTail(temp2 -> data, temp2 -> expo);
				temp2 = temp2 -> next;
			}
			else {
				temp1 = temp1 -> next;
				temp2 = temp2 -> next;
			}
		}
		while (temp1 != 0) {
			t.addToTail(temp1 -> data, temp1 -> expo);
			temp1 = temp1 -> next;
		}
		while (temp2 != 0) {
			t.addToTail(temp2 -> data, temp2 -> expo);
			temp2 = temp2 -> next;
		}
		return t;
	}
		
	Polynomial& operator-(const Polynomial& p) {
		Polynomial t;
		node * temp1 = head;
		node * temp2 = p.head;
		
		while (temp1 != 0 && temp2 != 0) {
			if ((temp1 -> expo == temp2 -> expo) && (temp1 -> data - temp2 -> data != 0)) {
				t.addToTail((temp1 -> data - temp2 -> data), temp1 -> expo);
				temp1 = temp1 -> next;
				temp2 = temp2 -> next;
			}
			else if (temp1 -> expo > temp2 -> expo) {
				t.addToTail(temp1 -> data, temp1 -> expo);
				temp1 = temp1 -> next;
			}
			else if (temp1 -> expo < temp2 -> expo) {
				t.addToTail((0 - temp2 -> data), temp2 -> expo);
				temp2 = temp2 -> next;
			}
			else {
				temp1 = temp1 -> next;
				temp2 = temp2 -> next;
			}
		}
		while (temp1 != 0) {
			t.addToTail(temp1 -> data, temp1 -> expo);
			temp1 = temp1 -> next;
		}
		while (temp2 != 0) {
			t.addToTail(temp2 -> data, temp2 -> expo);
			temp2 = temp2 -> next;
		}
		return t;
	}
	
	Polynomial& operator*(const Polynomial& p) {
		Polynomial t;
		node * temp1 = head;
		node * temp2 = NULL;
		while (temp1 != 0) {
			temp2 = p.head;
			while (temp2 != 0) {
				t.insert(temp1 ->data * temp2 -> data, temp1 -> expo + temp2 -> expo);
				temp2 = temp2 -> next;
			}
			temp1 = temp1 -> next;
		}
		
		return t;
	}	
};

//add at front
void Polynomial :: addToHead(float ele, int e) {
	node * p = new node(ele, e);
	if (head == 0) {
		head = p;
		tail = p;
	}
	else {
		p -> next = head;
		head = p;
	}	
}

//add element at last of Linked List
void Polynomial :: addToTail(float ele, int e) {
	node * p = new node(ele, e);
	if (tail == 0) {
		head = p;
		tail = p;
	}
	else {
		tail -> next = p;
		tail = p;
	}
}

//enter polynomial
void Polynomial :: enter() {
	int e;
	do {
		cout << "\nEnter coefficient ";
		float ele;
		cin >> ele;
		cout << "Enter exponential ";
		cin >> e;
		if (ele != 0) {
			insert(ele, e);
		}
	} while(e != 0);	
}

//insert polynomail
void Polynomial :: insert(float ele, int e) {
	if (head == NULL) {
		addToHead(ele, e);
	}
	else if (e > head -> expo) {
		addToHead(ele, e);
	}
	else if (e < tail -> expo) {
		addToTail(ele, e);
	}
	else {
		node * p = new node(ele, e);
		node * temp = head;
		node * prev = NULL;
		while (temp -> expo > e) {
			prev = temp;
			temp = temp -> next;
		}
		if (temp -> expo == e) {
			temp -> data += ele;
		}
		else {
			p -> next = prev -> next;
			prev -> next = p;
		}
	}
}

//display polynomial
void Polynomial :: display() {
	if (head == NULL) {
		cout << "\nNo element in Linked List\n";
	}
	else {
		node * temp = head;
		while (temp != 0) {
			if (temp -> data > 0) {
				cout << "+ " << temp -> data << "X^" << temp -> expo << "  ";
			}
			else {
				cout << "- " << (0 - temp -> data) << "X^" << temp -> expo << "  ";
			}
			temp = temp -> next;
		}
		
	}
}

int main() {
	cout << "\t\t\tPolynomial\n\n";
	Polynomial p1;
	p1.enter();
	p1.display();
	
	Polynomial p2;
	p2.enter();
	p2.display();
	
	cout << "\n\nP3=";
	Polynomial p3 = p1 + p2;
	p3.display();
	
	cout << "\n\nP4=";
	Polynomial p4 = p1 - p2;
	p4.display();
	
	cout << "\n\nP5=";
	Polynomial p5 = p1 * p2;
	p5.display();
	return 0;
}

