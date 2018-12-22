#include <iostream>
using namespace std;

char decimalIP(string ip) {
	int result = 0;
	char clas;
	for (int i = 0; ip[i] != '.'; i++) {
		result = (result * 10 + (ip[i] - '0'));
	}
	if (result < 128) {
		clas = 'A';
	}
	else if (result < 192) {
		clas = 'B';
	}
	else if (result < 224) {
		clas = 'C';
	}
	else if (result < 240) {
		clas = 'D';
	}
	else if (result < 256) {
		clas = 'E';
	}
	return clas;
}

char binaryIP(string ip) {
	int result = ip.find('0');
	char clas;
	switch (result) {
		case 0: {
			clas = 'A';
			break;
		}
		
		case 1: {
			clas = 'B';
			break;
		}
		
		case 2: {
			clas = 'C';
			break;
		}
		
		case 3: {
			clas = 'D';
			break;
		}
		
		default: {
			clas = 'E';
			break;
		}
	}
	return clas;
}

int main() {
	bool flag = true;
	string ip;
	do {
		cout << "\n1.Decimal IP";
		cout << "\n2.Binary IP";
		cout << "\n0.Exit";
		cout << "\noption...";
		int option;
		cin >> option;
		switch (option) {
			case 1: {
				cout << "Enter Ip :";
				cin >> ip;
				cout << decimalIP(ip);
				break;
			}
			
			case 2: {
				cout << "Enter IP :";
				cin >> ip;
				cout << binaryIP(ip);
				break;
			}
			
			case 0: {
				flag = false;
				break;
			}
				
		}
	} while (flag);
}
