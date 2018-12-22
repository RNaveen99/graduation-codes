#include "Stack.cpp";
#include <iostream>
using namespace std;

string add(string s1, string s2) {
	
	int size1 = s1.size();
	Stack n1(size1);
	for (int i = 0; i < size1; i++) {
		n1.push(s1[i] - '0');
	}
	
	int size2 = s2.size();
	Stack n2(size2);
	for (int i = 0; i < size2; i++) {
		n2.push(s2[i] - '0');
	}
	
	int size3 = (size1 > size2 ? size1 : size2);
	Stack n3(size3 + 1);
	
	int i, j, carry, result;
	i = j = carry = result = 0;
	while (i < size1 && j < size2) {
		result = n1.pop() + n2.pop() + carry;
		n3.push(result % 10);
		carry = result / 10;
		i++;
		j++;
	}
	while (i < size1) {
		result = n1.pop() + carry;
		n3.push(result % 10);
		carry = result / 10;
		i++;
	}
	while (j < size2) {
		result = n2.pop() + carry;
		n3.push(result % 10);
		carry = result / 10;
		j++;
	}
	if (carry) {
		n3.push(carry);
		size3++;
	}
	
	string s3;
	for( int i = 0; i < size3; i++) {
		s3 += (n3.pop() + '0');
	}
	return s3;
}
int main() {
	string s1, s2;
	cout << "Enter 1st number:";
	cin >> s1;
	cout << "Enter 2nd number:";
	cin >> s2;
	string s3 = add(s1, s2);
	cout << s3;
	return 0;
}
