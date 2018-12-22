#include <iostream>
#include <string>
using namespace std;

//	reverse display of a string without storing it
void reverseDisp() {
	char ch;
	cin.get(ch);
	if (ch != '\n') {
		reverseDisp();
	}
	cout << ch;
}

//	reverse display of a string char by char
void reverseDisplay(string &s, int i){
	if(s[i] == '\0') {
		return;
	}
	reverseDisplay(s, i + 1);
	cout << s[i];
}

//	calculating x ^ y
int rePower(int b, int e) {
	if ((b == 0) || (e == 1)) {
		return b;
	}
	if (e == 0) {
		return 1;
	}
	int x = rePower(b, e/2);
	if (e & 1) {
		return b * x * x;
	}
	else {
		return x * x;
	}
}

//	reversing a string by swapping first and last elements
void reverseString(string &s, int start, int last) {
	if (start < last) {
		char temp = s[start];
		s[start] = s[last];
		s[last] = temp;
		reverseString(s, start + 1, last - 1);
	} 
}

//	sum of N numbers
int sumN(int x) {
	if (x == 0) {
		return x;
	}
	return x + sumN(x-1);	
}

//	sum of numbers in a array
int sumN2(int arr[], int size, int i) {
	if (i < size) {
		return arr[i] + sumN2(arr, size, i + 1);
	}
	return 0;
}

//	average of numbers in a array
float avg(int arr[], int size, int i) {
	if (size - i == 1) {
		return arr[i];
	}
	return (arr[i] + avg(arr, size, i + 1) * (size - 1 - i)) / (size - i);
}

//	fibonacci series element
int fibonacci(int ele) {
	if ((ele == 1) || (ele == 2)) {
		return ele - 1;
	}
	
	return fibonacci(ele - 1) + fibonacci(ele - 2);
}

//	factorial of a number
int factorial(int num) {
	if (num == 0) {
		return 1;
	}
	return num * factorial(num - 1);
}

//	remove char from string
string removeChar(string s, int i, char ele) {
	if (i == s.size()) {
		return "";
	}
	if (s[i] != ele) {
		return s[i] + removeChar(s, i + 1, ele);
	}
	return removeChar(s, i + 1, ele);
}

//	cube
void cube(int n) {
	if (n == 0) {
		return; 
	}
	cout << "N = " << n << ", cube =  " << n * n * n << endl;
	cube (n - 1);
}

//	GCD
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return  gcd (b, a % b);
}

//	palindrome
bool palindrome(string s, int i, int l) {
	if (i >= l) {
		return true;
	}
	if (s[i] != s[l]) {
		return false;
	}
	return palindrome(s, i + 1, l - 1);
}

// palindrome of a sentence
bool palindromeSentence(string s, int i, int l) {
	if (i >= l) {
		return true;
	}
	if (((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && ((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))) {
		if (s[i] != s[l]) {
			return false;
		}
		return palindromeSentence(s, i + 1, l - 1);
	}
	else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
		return palindromeSentence(s, i, l - 1);
	}
	else if ((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z')) {
		return palindromeSentence(s, i + 1, l);
	}
	else {
		return palindromeSentence(s, i + 1, l - 1);
	}
}


//	Tower of Hanoi
void TOH(char source, char auxiliary, char destination, int n) {
	static int steps = 0;
	if (n == 1) {
		cout << "\nStep " << ++steps << "  : Ring " << n << " moved from " << source << " to " << destination;
		return;
 	}
 	TOH(source, destination, auxiliary, n - 1);
 	cout << "\nStep " << ++steps << "  : Ring " << n << " moved from " << source << " to " << destination;
 	TOH(auxiliary, source, destination, n - 1);
}


int main() {
	bool flag = true;
	int opt, x, y, * arr;
	string str;
	char ele;
	while (flag) {
		cout << "\n\n1.GCD";
		cout << "\n2.Factorial";
		cout << "\n3.Fibonacci";
		cout << "\n4.Cube (from 2 to N)";
		cout << "\n5.Sum of N numbers (1 to N)";
		cout << "\n6.Sum of numbers in a array ";
		cout << "\n7.Average of numbers in a array";
		cout << "\n8.Power (x ^ y)";
		cout << "\n9.Palindrome";
		cout << "\n10.Remove char from a string";
		cout << "\n11.Reverse a string.";
		cout << "\n12.Reverse display a string.";
		cout << "\n13.Reverse display a string without storing it.";
		cout << "\n14.Tower Of Hamoi";
		cout << "\n0.Exit.";
		cout << "\nEnter option...";
		cin >> opt;
		switch (opt) {
			case 1: {
				cout << "\nEnter x : ";
				cin >> x;
				cout << "Enter y : ";
				cin >> y;
				cout << "GCD = " << gcd(x, y);
				break;
			}
			
			case 2: {
				cout << "\nEnter x : ";
				cin >> x;
				cout << "Factorial = " << factorial(x);
				break;
			}
			
			case 3: {
				cout << "\nEnter x : ";
				cin >> x;
				cout << "Fibonmacci series = ";
				for (int i = 1; i <= x; i++) {
					cout << fibonacci(i) << "\t";
				}
				break;
			}
			
			case 4: {
				cout << "\nEnter x : ";
				cin >> x;
				cout << "Cubes :\n"; 
				cube(x);
				break;
			}
			
			case 5: {
				cout << "\nEnter N : ";
				cin >> x;
				cout << "Sum = " << sumN(x);
				break;
			}
			
			case 6: {
				cout << "\nEnter size of array : ";
				cin >> x;
				arr = new int [x];
				cout << "Enter elements of array : ";
				for (int i = 0; i < x; i++) {
					cin >> arr[i];
				}
				cout << "Sum = " << sumN2(arr, x, 0);
				delete arr;
				break;
			}
			
			case 7: {
				cout << "\nEnter size of array : ";
				cin >> x;
				arr = new int [x];
				cout << "Enter elements of array : ";
				for (int i = 0; i < x; i++) {
					cin >> arr[i];
				}
				cout << "Average = " << avg(arr, x, 0);
				delete arr;
				break;
			}
			
			case 8:  {
				cout << "\nEnter x : ";
				cin >> x;
				cout << "Enter y : ";
				cin >> y;
				cout << "x ^ y = " << rePower(x, y);
				break;
			}
			
			case 9: {
				cout << "Enter string : ";
				cin.ignore(256, '\n');
				getline (cin, str);
				if (palindromeSentence(str, 0, str.size() - 1)) {
					cout << "Given string is Palindrome";
				}
				else {
					cout << "Given string is not palindrome";
				}
				break;
			}
			
			case 10: {
				cout << "Enter string : ";
				cin.ignore(256, '\n');
				getline (cin, str);
				cout << "Enter character to be removed : ";
				cin >> ele;
				str = removeChar(str, 0, ele);
				cout << "String = " << str;
				break;
			}
			
			case 11: {
				cout << "Enter string : ";
				cin.ignore(256, '\n');
				getline (cin, str);
				reverseString(str, 0, str.size() - 1);
				cout << "String reversed = " << str;
				break;
			}
			
			case 12: {
				cout << "Enter string : ";
				cin.ignore(256, '\n');
				getline (cin, str);
				cout << "Reverse display = ";
				reverseDisplay(str, 0);
				break;
			}
			
			case 13: {
				cout << "Enter string : ";
				cin.ignore(256, '\n');
				reverseDisp();
				break;
			}
			
			case 14: {
				cout << "\nEnter no. of rings : ";
				cin >> x;
				TOH('A', 'B', 'C', x);
				break;
			}
			case 0:{
				flag = false;
				break;
			}
		}
	}
	return 0;
}
