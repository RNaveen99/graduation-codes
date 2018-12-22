#include <iostream>
using namespace std;
class Stack {
	char * arr;
	int size;
	int top;
	
	public:
	Stack(int s = 0) {
		size = s;
		arr = new char[size];
		top = -1;
	}
	
	bool isEmpty() {
		return (top == -1);
	}
	
	bool isFull() {
		return (top == size - 1);
	}
	
	int getSize() {
		return size;
	}
	
	void push(char num) {
		if (isFull()) {
			throw "Satck overflow";
		}
		arr[++top] = num;
	}
	
	int pop() {
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

bool match(char c1, char c2) {
	bool flag = false;
	if ((c1 == '(') && (c2 == ')')) {
		flag = true;
	}
	else if ((c1 == '{') && (c2 == '}')){
		flag = true;
	}
	else if ((c1 == '[') && (c2 == ']')) {
		flag = true;
	}
	return flag;
}

bool parenthesis(string s) {
	bool valid = true;
	int i = 0;
	int size = s.size();
	Stack p(size);
	while (s[i] != '\0' && valid) {
		if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
			p.push(s[i]);
		}
		else if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
			if (p.isEmpty()) {
				valid = false;
			}
			else {
				char ch = p.pop();
				if (!match(ch, s[i])) {
					valid = false;
				}
			}
		}
		i++;
	}
	if(!p.isEmpty()) {
		valid = false;
	}
	return valid;
}
int main() {
	string s;
	cout << "Enter expression : ";
	cin >> s;
	bool flag = parenthesis(s);
	if (flag) {
		cout << "It is valid";
	}
	else {
		cout << "It is invalid";
	}
	return 0;
}
