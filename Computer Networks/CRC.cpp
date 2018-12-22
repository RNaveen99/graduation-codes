#include <iostream>
using namespace std;

void divideXOR (string & tempData, const string & generator) {
	int bits = generator.size();
	int size = tempData.size();
	int i = 0, index;
	bool flag;
	while ((size - i) >= bits) {
		flag = true;
		index = i;
		for (int j = 0; j < bits; j++, index++) {
			tempData[index] = (tempData[index] ^ generator[j]) + '0';
			if (flag && (tempData[index] - '0')) {
				flag = false;
				i = index;	
			}
		}
		if (flag) {
			i = index;
		}
	}
}


int main() {
	
	string tempData, generator, originalData;
	
	cout << "Enter data:";
	cin >> tempData;
	originalData = tempData;
	cout << "Enter generator:";
	cin >> generator;
	
	int bits = generator.size() - 1;
	
	for (int i = 0; i < bits; i++) {
		tempData += "0";
	}
	
	int size = tempData.size();
	divideXOR(tempData, generator);	
	cout << "Remainder =" << tempData;
	originalData += tempData.substr((size - bits), bits);
	cout << "\nReceived Data = "<< originalData;
	
	divideXOR(originalData, generator);
	cout << "\nVerifying Data...";
	cout << "\nRemainder =" << originalData;
	
}
