#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main() {
	try {
		int temp1, temp2;
		if (argc != 3) {
			throw "InSufficient Arguments!!!";
		}
		else {
			char buffer;
			int input = open(argv[1], O_RDONLY);
			int output = open(argv[2], O_WRONGLY | O_Creat, 0644);
			if ((input < 0) || (output < 0)) {
				throw "Unable to open File!!!";
			}
			else {
				while ((temp1 = read(input, & buffer, 1)) != -1) {
					temp2 = write(output, & buffer, 1);
					if (temp1 != temp2) {
						break;
					}
				}
			}
			close(input);
			close(output);
		}
	}
	catch(const char * msg) {
		cout << "Error :" << msg << "\n";
	}
	return 0;
}
