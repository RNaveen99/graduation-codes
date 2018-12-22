#include<iostream>
using namespace std;
int TQ;
struct Process {
	int TQ;
	int processId;
	int burstTime;
	int remainingTime;
	int startingTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
};

void enterTQ() {
	cout << "\nEnter Time Quantum :";
	cin >> TQ;
}
void enterProcess(Process * p, const int & n) {
	cout << "\nEnter values:";
	enterTQ();
	for (int i = 0; i < n; i++) {
		cout << "\n\nProcess Id       :P" << i + 1 << endl;
		p[i].processId = i + 1;
		cout << "Burst Time       :";
		cin >> p[i].burstTime;
		p[i].remainingTime = p[i].burstTime;
		p[i].startingTime = -1;
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

void calculate(Process *p, const int & n, double & avgTAT, double & avgWT) {
	int currentTime = 0, counter = 0;
	bool flag = true;
	int oldTime = currentTime;		
	while (counter < n) {
		for (int i = 0; i < n; i++) {
			if (p[i].startingTime == -1) {
				p[i].startingTime = currentTime;
			}
			if (p[i].remainingTime > TQ) {
				p[i].remainingTime -= TQ;
				currentTime += TQ;
			}
			else if (p[i].remainingTime > 0) {
				currentTime += p[i].remainingTime;
				p[i].completionTime = currentTime;
				p[i].turnAroundTime = p[i].completionTime;
				p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
				avgTAT += p[i].turnAroundTime;
				avgWT += p[i].waitingTime;
				p[i].remainingTime = 0;
				counter++;
			}
			tempDisplayProcess(p[i], oldTime, currentTime);
			oldTime = currentTime;
		}
		
	}
	avgTAT /= n;
	avgWT /= n;
}


void displayProcess(Process * p, const int & n, const double & avgTAT, const double & avgWT) {
	cout << "\n\nP_id\t Burst Time\t starting time\t  Completion Time\t TurnAround Time\t Waiting Time";
	for (int i = 0; i < n; i++) {
		cout << "\n\n" << "P" << p[i].processId << "\t\t" << p[i].burstTime << "\t\t" << p[i].startingTime;
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
	cout << "\n\n\nAverage Turn around Time = " << avgTAT;
	cout << "\n\nAverage waiting time = " << avgWT;
}

int main() {
	cout << "\t\t***************Round Robin Scheduling**********" << endl;
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

