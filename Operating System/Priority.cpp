#include<iostream>
using namespace std;

struct Process {
	int processId;
	int arrivalTime;
	int burstTime;
	int priority;
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
		cout << "Priority         :";
		cin >> p[i].priority;
		cout << "Arrival Time     :";
		cin >> p[i].arrivalTime;
		cout << "Burst Time       :";
		cin >> p[i].burstTime;
	}
}

//sorting processes in Ascending order w.r.t ArrivalTime
void sortProcess1(Process * p, const int & n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (p[j].arrivalTime > p[j + 1].arrivalTime) {
				Process temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;	
			}
		}
	}
}

//sorting processes in Descending order w.r.t Priority Time
void sortProcess2(Process * p, const int & start, const int & last) {
	for (int i = start; i < last; i++) {
		for (int j = start; j < last - 1; j++) {
			if (p[j].priority < p[j + 1].priority) {
				Process temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;	
			}
		}
	}
}

void calculate(Process * p, const int & n, double & avgTAT, double & avgWT) {
	sortProcess1(p, n);
	int currentTime = p[0].arrivalTime;
	int lastIndex, j;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (flag) {
			for (j = i; j < n; j++) {
				if (p[j].arrivalTime > currentTime) {
					lastIndex = j;
					break;
				}
			}
		}
		if(j == n) {
			lastIndex = n;
			flag = false;
		}
		sortProcess2(p, i, lastIndex);
		if(currentTime < p[i].arrivalTime) {
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
	cout << "P_id\t   Priority \t Arrival Time \t Burst Time\t starting time\t  Completion Time\t TurnAround Time\t Waiting Time";
	for (int i = 0; i < n; i++) {
		if (i != 0 && p[i].startingTime != p[i - 1].completionTime) {
			cout << "\n\n\t-----------------CPU idle for " << p[i].startingTime-p[i - 1].completionTime << "--------------------";
		}
		cout << "\n\n" << "P" << p[i].processId << "\t\t" << p[i].priority << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].startingTime;
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
	cout << "\t\t\t**************Priority Scheduling non preemptive***************" << endl;
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

