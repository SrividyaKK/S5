/* Simulate the foll non-preemptive CPU scheduling algos to find turnaround and burst time: 
1. FCFS
2. SJF
3. RR (preemptive)
4. Priority
*/
#include<stdio.h>

typedef struct {
	int burst_time, arrival_time, pid, turnaround_time, waiting_time, remaining_time, priority;
	short done;
} process;

void sortOnArrivalTimes(process p[], int n) {
	int i, j;
	process temp;
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-1-i; j++) {
			if (p[j].arrival_time > p[j+1].arrival_time) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

void fcfs(process processes[], int n) // Done
{
	int i, t=0;
	for (i=0; i<n; i++) {
		printf("Proccess: %d\n", processes[i].pid);
		t += processes[i].burst_time;
		processes[i].turnaround_time = t - processes[i].arrival_time;
		printf("Turnaround time: %d\tWaiting time: %d\n\n", processes[i].turnaround_time, processes[i].waiting_time);
	}
}

void sjf(process processes[], int n)
{
	int i, t;
	for (i=0; i<n; i++) {
		
	}
}

void rr(process p[], int n) // TODO
{
	int i, tq, t=0, count=0; // tq: time quantum
	printf("Enter the time quantum: ");
	scanf("%d", &tq);

	while (count < n) {
		for (i=0; i<n; i++) {
			if (p[i].arrival_time <= t && !p[i].done) {
				if ([i].remaining_time > tq) {
					t += tq;
					p[i].remaining_time -= tq;
				} else {
					t += p[i].remaining_time;
					p[i].remaining_time = 0;
					p[i].done = 1;
					p[i].turnaround_time = t - p[i].arrival_time;
					p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
					count++;
				}
			}
		}
	}

	printf("Process id\tTurnaround time\tWaiting time\n-----------------------------------------------------------\n");
	for (i=0; i<n; i++) {	
		printf("%d %d %d\n", p[i].id, [i].turnaround_time, p[i].waiting_time);
	}
}

void prio(process processes[], int n)
{
	int i;
	
}

void main()
{
	int n, i;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process processes[n];
	printf("Enter pid, burst and arrival times of the processes: \n");
	for (i=0; i<n; i++) {
		scanf("%d %d %d", &processes[i].pid, &processes[i].burst_time, &processes[i].arrival_time);
		processes[i].remaining_time = processes[i].burst_time; 
		processes[i].done = processes[i].turnaround_time = processes[i].waiting_time = 0;
	}

	sortOnArrivalTimes(processes);

	printf("\nFCFS SCHEDULING ALGO: \n");
	fcfs(processes, n);
	printf("\n");

	// printf("\nSJF SCHEDULING ALGO: \n");
	// sjf(arrival_times, burst_times, n);
	// printf("\n");

	printf("\nRR SCHEDULING ALGO: \n");
	rr(processes, n);
	printf("\n");

	printf("Priority SCHEDULING ALGO: \n");
	printf("Enter the priorities of the processes: ");
	for (i=0; i<n; i++) {
		printf("Process %d: ", processes[i].pid);
		scanf("%d", &processes[i].priority);
	}
	prio(processes, n);
}