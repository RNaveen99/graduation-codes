#include <iostream>
using namespace std;

//	calculating no. of parity bits 
//	using formula (2 ^ r) >= r + m + 1
int calculateParityBits(int m) {
	m ++;
	int r = 0;
	while (((1 << r) - r) < m) {
		r++;
	}
	return r;
}

//	calculating no. of parity bits in the given hamming code
int calculateParityBits2(int m) {
	int r = 0;
	while ((1 << r) < m) {
		r++;
	}
	return r;
}

//	inserting parity bits in data
void insertParityBits(string & data, const int & r, int & m) {
	for (int i = 0; i < r; i++) {
		data.insert(m + 1 - (1 << i), "p");
		m++; 
	}
}


//	generating hamming code
void hamming(string & data, int parity) {
	int m = data.size();
	
	int r = calculateParityBits(m);
	cout << "Parity bits = " << r << endl;
	insertParityBits(data, r, m); 
	cout << "\nData is = " << data << endl;

	//calculating value of parity bits
	for (int i = 0, j, counter, skip, count1; i < r; i++) {
		counter = 1 << i;
		skip = counter;
		count1 = 0;
		for (j = m - skip; j >= 0; j--) {
			if (data[j] == '1') {
				count1++;
			}
			skip--;
			if (skip == 0) {
				skip = counter;
				j = j - skip;
			}
		}
		
		if (parity) {
			if (count1 & 1) {
				data.replace(m - counter, 1, "0");
			} 
			else {
				data.replace(m - counter, 1, "1");
			}
		}
		else {
			if (count1 & 1) {
				data.replace(m - counter, 1, "1");
			}
			else {
				data.replace(m - counter, 1, "0");
			}	
		}	
	}
}


//	detection and correction of received hamming code
void detection(string & data, int parity) {
	bool flag = true;
	int errorBit = 0;
	int m = data.size();
	
	int r = calculateParityBits2(m);
	
	//verifying value of parity bits
	for (int i = 0, j, counter, skip, count1; i < r; i++) {
		counter = 1 << i;
		skip = counter;
		count1 = 0;
		for (j = m - skip; j >= 0; j--) {
			if (data[j] == '1') {
				count1++;
			}
			skip--;
			if (skip == 0) {
				skip = counter;
				j = j - skip;
			}
		}
		
		if (parity) {
			if (count1 & 1); 
			else {
				flag = false;
				errorBit += counter;
			}
		}
		else {
			if (count1 & 1) {
				flag = false;
				errorBit += counter;
			}
			else;	
		}	
	}
	
	if (! flag) {
		cout << "Error occurd in the received data, in bit(from right side) " << errorBit << endl;
		if (data[m - errorBit] == '1') {
			data.replace(m - errorBit, 1, "0");
		}
		else {
			data.replace(m - errorBit, 1, "1");
		}
		cout << "Correct code should be = " << data << endl;
	}
	else {
		cout << "Code is correct";
	}
	
	for (int i = 0; i < r; i++) {
		data.erase(m - (1 << i), 1);
	}
}

int main() {
	string data;
	int parity;
	int option;
	bool flag = true;
	do {
		cout << "\n\n1.Generate Hamming code";
		cout << "\n2.Detection and Correction of Received Hamming code";
		cout << "\n3.Generate and error detection and correction of a hamming code";
		cout << "\n0.Exit";
		cout << "\nEnter option...";
		cin >> option;
		
		switch (option) {
			
			case 1: {
				cout << "\nEnter Data :";
				cin >> data;
				cout << "Enter parity  0--even , 1--odd :";
				cin >> parity;
				hamming(data, parity);
				cout << "\nHamming code generated = " << data << endl;
				break;
			}
			
			case 2: {
				cout << "\nEnter Data :";
				cin >> data;
				cout << "Enter parity  0--even , 1--odd :";
				cin >> parity;
				detection(data, parity);
				cout << "\n original data received = " << data << endl;
				break;
			}
			
			case 3: {
				cout << "\nEnter Data :";
				cin >> data;
				cout << "Enter parity  0--even , 1--odd :";
				cin >> parity;
				hamming(data, parity);
				cout << "\nHamming code generated = " << data << endl;
				detection(data, parity);
				cout << "\nOriginal data received = " << data << endl;
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

