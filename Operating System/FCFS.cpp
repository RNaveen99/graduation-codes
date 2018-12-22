#include <iostream>
using namespace std;

struct Process {
	int processId;
	int arrivalTime;
	int burstTime;
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
	}
}

//sorting the processes in Ascending order w.r.t ArrivalTime
void sortProcess(Process * p, const int & n) {
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

void calculate(Process * p, const int & n, double & avgTAT, double & avgWT) {
	sortProcess(p, n);
	int currentTime = p[0].arrivalTime;
	for (int i = 0; i < n; i++) {
		if (currentTime < p[i].arrivalTime) {
			currentTime = p[i].arrivalTime;
		}
		p[i].startingTime = currentTime;
		currentTime += p[i].burstTime;
		p[i].completionTime = currentTime;
		p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
		p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
		
		avgTAT += p[i].turnAroundTime;
		avgWT += p[i].waitingTime;
	}
	avgTAT /= n;
	avgWT /= n;
}

void displayProcess(Process * p, const int & n, const double & avgTAT, const double & avgWT) {
	cout << "\nP_id\t Arrival Time\t Burst Time\t starting time\t  Completion Time\t TurnAround Time\t Waiting Time";
	for (int i = 0; i < n; i++) {
		if (i != 0 && p[i].startingTime != p[i - 1].completionTime) {
			cout << "\n\n\t-----------------CPU idle for " << p[i].startingTime - p[i - 1].completionTime << "--------------------";
		}
		cout << "\n\n" << "P" << p[i].processId << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].startingTime;
		cout << "\t\t" << p[i].completionTime << "\t\t\t" << p[i].turnAroundTime << "\t\t"<< p[i].waitingTime;
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
	cout << "\t\t\t**********************FCFS Scheduling**********************" << endl;
	cout << "Enter the no. processes:";
	int n;
	cin >> n;
	Process * p = new Process[n];
	enterProcess(p, n);
	double avgTAT = 0, avgWT = 0;
	calculate(p, n, avgTAT, avgWT);
	displayProcess(p, n, avgTAT, avgWT);
	return 0;
}
