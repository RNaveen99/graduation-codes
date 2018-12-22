#include<iostream>
using namespace std;

struct Process {
	int processId;
	int arrivalTime;
	int burstTime;
	int remainingTime;
	int startingTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
};

void enterProcess(Process * p, const int & n) {
	cout << "\nEnter values:";
	for (int i = 0; i < n; i++) {
		cout << "\n\nProcess Id       :P" << i + 1 << endl;
		p[i].processId = i + 1;
		cout << "Arrival Time     :";
		cin >> p[i].arrivalTime;
		cout << "Burst Time       :";
		cin >> p[i].burstTime;
		p[i].remainingTime = p[i].burstTime;
		p[i].startingTime = -1;
	}
}

//sorting processes in Ascending order w.r.t Arrival Time
void sortProcess1(Process * p, const int & n) { 
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (p[j].arrivalTime > p[j + 1].arrivalTime) {
				Process temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;	
			}
		}
	}
}

//sorting processes in Ascending order w.r.t Remaining Time
void sortProcess2(Process * p, const int & start, const int & last) {
	for (int i = start; i < last - 1; i++) {
		for (int j = start; j < last - 1; j++) {
			if (p[j].remainingTime > p[j + 1].remainingTime) {
				Process temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;	
			}
		}
	}
}

void tempDisplayProcess(Process p, const int & oldTime, const int & newTime) {
	if (oldTime == newTime) {
		return;
	}
	cout << "\n|----------|";
	cout << "\n|          |";
	cout << "\n|    P" << p.processId << "    |";
	cout << "\n|----------|";
	cout << "\n" << oldTime << "         " << newTime << "  ";
	if (p.remainingTime == 0) {
		cout << "-----Completed";
	}
}

void calculate(Process * p, const int & n, double & avgTAT, double & avgWT) {
	sortProcess1(p, n);
	int currentTime = p[0].arrivalTime;
	bool flag = true;
	int lastIndex, j, k = 0, oldTime = currentTime;	
	Process temp1 = p[0], temp2;	
	while (k < n) {
		if (flag) {
			for (j = 0; j < n; j++) {
				if (p[j].arrivalTime > currentTime) {
					lastIndex = j;
					break;
				}
			}
		}
		if (j == n) {
			lastIndex = n;
			flag = false;
		}
		sortProcess2(p, k, lastIndex);
		temp2 = p[k];
		if (p[k].startingTime == -1) {
			p[k].startingTime = currentTime;
		}
		p[k].remainingTime--;
		if (temp1.processId != temp2.processId) {
			tempDisplayProcess(temp1, oldTime, currentTime);
			oldTime = currentTime;
			temp1 = temp2;
		}
		currentTime++;
		if (p[k].remainingTime == 0) {
			p[k].completionTime = currentTime;
			p[k].turnAroundTime = p[k].completionTime - p[k].arrivalTime;
			p[k].waitingTime = p[k].turnAroundTime - p[k].burstTime;
			avgTAT += p[k].turnAroundTime;
			avgWT += p[k].waitingTime;
			temp2 = p[k];
			tempDisplayProcess(p[k], oldTime, currentTime);
			oldTime = currentTime;
			k++;
		}		
		
	}
	tempDisplayProcess(temp1, oldTime, currentTime);
	avgTAT /= n;
	avgWT /= n;
}


void displayProcess(Process * p, const int & n, const double & avgTAT, const double & avgWT) {
	cout << "\n\nP_id\t Arrival Time\t Burst Time\t starting time\t  Completion Time\t TurnAround Time\t Waiting Time";
	for (int i = 0; i < n; i++) {
		cout << "\n\n" << "P" << p[i].processId << "\t\t" << p[i].arrivalTime << "\t\t"<< p[i].burstTime << "\t\t" << p[i].startingTime;
		cout << "\t\t" << p[i].completionTime << "\t\t\t" << p[i].turnAroundTime << "\t\t" << p[i].waitingTime;
	}
	
	cout << endl << endl;
	for (int i = 0; i < n; i++)
		cout << "|----------| ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << "|          | ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << "|    P" << p[i].processId << "    | ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << "|----------| ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << p[i].startingTime << "         " << p[i].completionTime << "  ";
	cout << "\n\n\nAverage Turn around Time=" << avgTAT;
	cout << "\n\nAverage waiting time=" << avgWT;
}

int main() {
	cout << "\t\t***************SRTF Scheduling**********" << endl;
	cout << "Enter the no. processes:";
	int n;
	cin >> n;
	Process * p = new Process[n];
	enterProcess(p, n);
	double avgTAT = 0,avgWT = 0;
	calculate(p, n, avgTAT, avgWT);
	displayProcess(p, n, avgTAT, avgWT);
	return 0;
}

