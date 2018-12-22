#include <iostream>
#include <cmath>
using namespace std;
template<typename T>
class Stack {
	T * arr;
	int size;
	int top;
	
	public:
	Stack(int s = 0) {
		size = s;
		arr = new T[size];
		top = -1;
	}
	
	bool isEmpty() {
		return (top == -1);
	}
	
	bool isFull() {
		return (top == size - 1);
	}
	
	T stackTop() {
		return arr[top];
	}
	
	void push(T num) {
		if (isFull()) {
			throw "Satck overflow";
		}
		arr[++top] = num;
	}
	
	T pop() {
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


int evaluatePostfix(string s) {
	int size = s.size();
	int a, b;
	Stack <int> p((size + 1) / 2);
	int i = 0;
	while (s[i] != '\0') {
		switch (s[i]) {
			case '+': {
				b = p.pop();
				a = p.pop();
				p.push(a + b);
				break;
			}
			
			case '-': {
				b = p.pop();
				a = p.pop();
				p.push(a - b);
				break;
			}
			
			case '*': {
				b = p.pop();
				a = p.pop();
				p.push(a * b);
				break;
			}
			
			case '/': {
				b = p.pop();
				a = p.pop();
				p.push(a / b);
				break;
			}
			
			case '^': {
				b = p.pop();
				a = p.pop();
				p.push(pow(a, b));
				break;
			}
			default: {
				p.push(s[i] - '0');
				break;
			}
		}
		i++;
	}
	a = p.pop();
	if (!p.isEmpty()) {
		throw "Invalid expression";
	}
	return a;
}

string infixToPostfix(string s) {
	int size = s.size();
	Stack <char> p(size);
	int i = 0;
	string postfix;
	while(s[i] != '\0') {
		switch (s[i]) {
			case '+':
			case '-': {
				while (! p.isEmpty() && p.stackTop() != '(') {
					postfix += p.pop();
				}
				p.push(s[i]);
				break;
			}
			case '*':
			case '/': {
				while (! p.isEmpty() && p.stackTop() != '(' && p.stackTop() != '+' && p.stackTop() != '-') {
					postfix += p.pop();
				}
			
				p.push(s[i]);
				break;
			}
				
			case '^': 
			case '(': {
				p.push(s[i]);
				break;
			}
			case ')': {
				while (p.stackTop() != '(') {
					postfix += p.pop();
				}
				p.pop();
				break;
			}
			default: {
				postfix += s[i];
				break;
			}
		}
		i++;
	}
	while (! p.isEmpty()) {
		postfix += p.pop();
	}
	return postfix;
}

string postfixToInfix(string s) {
	int size = s.size();
	Stack <string>p(size);
	int i = 0;
	while (s[i] != '\0') {
		switch (s[i]) {
			case '+':
			case '-':
			case '*':
			case '/':
			case '^': {
				string b = p.pop();
				string a = p.pop();
				string c = a + s[i] + b;
				p.push(c);
				break;
			}
			default: {
				p.push(string(1, s[i]));
				break;
			}
		}
		i++;
	}
	return p.stackTop();
}

string infixToPrefix(string s) {
	int size = s.size();
	Stack <char> p((size + 1) / 2);
	Stack <string> q(size);
	int i = 0;
	while(s[i] != '\0') {
		switch (s[i]) {
			case '+':
			case '-': {
				while (! p.isEmpty() && p.stackTop() != '(') {
					string b = q.pop();
					string a = q.pop();
					q.push(p.pop() + a + b);
				}
				p.push(s[i]);
				break;
			}
			case '*':
			case '/': {
				while (! p.isEmpty() && p.stackTop() != '(' && p.stackTop() != '+' && p.stackTop() != '-') {
					string b = q.pop();
					string a = q.pop();
					q.push(p.pop() + a + b);
				}
				p.push(s[i]);
				break;
			}
				
			case '^': 
			case '(': {
				p.push(s[i]);
				break;
			}
			case ')': {
				while (p.stackTop() != '(') {
					string b = q.pop();
					string a = q.pop();
					q.push(p.pop() + a + b);
				}
				p.pop();
				break;
			}
			default: {
				q.push(string(1, s[i]));
				break;
			}
		}
		i++;
	}
	while (! p.isEmpty()) {
		string b = q.pop();
		string a = q.pop();
		q.push(p.pop() + a + b);
	}
	return q.pop();
}

string prefixToInfix(string s) {
	int size = s.size();
	Stack <char>p((size + 1) / 2);
	int i = 0;
	string infix;
	while (s[i + 1] != '\0') {
		switch (s[i]) {
			case '+':
			case '-':
			case '*':
			case '/':
			case '^': {
				p.push(s[i]);
				break;
			}
			default: {
				infix = infix + s[i] + p.pop();
				break;
			}
		}
		i++;
	}
	infix += s[i];
	return infix;
}

int evaluatePrefix(string s) {
	int size = s.size();
	int a, b;
	Stack <int> p((size + 1) / 2);
	int i = size - 1;
	while (i != -1) {
		switch (s[i]) {
			case '+': {
				b = p.pop();
				a = p.pop();
				p.push(a + b);
				break;
			}
			
			case '-': {
				b = p.pop();
				a = p.pop();
				p.push(b - a);
				break;
			}
			
			case '*': {
				b = p.pop();
				a = p.pop();
				p.push(a * b);
				break;
			}
			
			case '/': {
				b = p.pop();
				a = p.pop();
				p.push(b / a);
				break;
			}
			
			case '^': {
				b = p.pop();
				a = p.pop();
				p.push(pow(b, a));
				break;
			}
			default: {
				p.push(s[i] - '0');
				break;
			}
		}
		i--;
	}
	a = p.pop();
	if (!p.isEmpty()) {
		throw "Invalid expression";
	}
	return a;
}
int main() {
	bool flag = true;
	string infix, postfix, prefix;
	do {
		cout << "\n\n1.Infix to Postfix and Evaluate it";
		cout << "\t2.Infix to Postfix";
		cout << "\t3.Evaluate Postfix";
		cout << "\t4.Postfix to Infix";
		cout << "\n5.Infix to Prefix and Evaluate it";
		cout << "\t6.Infix to Prefix";
		cout << "\t7.Evaluate Prefix";
		cout << "\t8.Prefix to Infix";
		cout << "\n0.Exit";
		cout << "\nOption...";
		int option;
		cin >> option;
		switch (option) {
			case 1: {
				cout << "Enter Infix expression : ";
				cin >> infix;
				postfix = infixToPostfix(infix);
				cout << "Postfix expression = "<< postfix;
				cout << "\nResult = "<< evaluatePostfix(postfix);
				break;
			}
			
			case 2: {
				cout << "Enter Infix expression : ";
				cin >> infix;
				postfix = infixToPostfix(infix);
				cout << "Postfix expression = "<< postfix;
				break;
			}
			
			case 3: {
				cout << "Enter Postfix expression : ";
				cin >> postfix;
				cout << "Result = "<< evaluatePostfix(postfix);
				break;
			}
			
			case 4: {
				cout << "Enter Postfix expression :";
				cin >> postfix;
				infix = postfixToInfix(postfix);
				cout << "Infix expression = " << infix;
				break;
			}
			
			case 5: {
				cout << "Enter Infix expression : ";
				cin >> infix;
				prefix = infixToPrefix(infix);
				cout << "Prefix expression = "<< prefix;
				cout << "\nResult = "<< evaluatePrefix(prefix);
				break;
			}
			
			case 6: {
				cout << "Enter Infix expression : ";
				cin >> infix;
				prefix = infixToPrefix(infix);
				cout << "Prefix expression = "<< prefix;
				break;
			}
			
			case 7: {
				cout << "Enter Prefix expression";
				cin >> prefix;
				cout << "Result = "<< evaluatePrefix(prefix);
				break;
			}
			
			case 8: {
				cout << "Enter Prefix expression :";
				cin >> prefix;
				infix = prefixToInfix(prefix);
				cout << "Infix expression = " << infix;
				break;
			}
			case 0: {
				flag = false;
				break;
			}
		}
	} while (flag);
	return 0;
}
