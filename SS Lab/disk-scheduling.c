#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int head, n, max, req[25], p;

void fcfs() {
	int movts=0, i, cur=head;
	printf("Head Movements: \n");
	for (i=0; i<n; i++) {
		if (i != n-1) printf("%d --> ", req[i]);
		else printf("%d\n", req[i]);
		movts += abs(req[i]-cur);
		cur = req[i];
	}
	printf("No. of cylinder movements: %d\n", movts);
}

void sortRequests() {
	bool found = false;
	int s;
	for (i=0; i<n-1; i++) {
		s=i;
		for (j=i+1; j<n; j++) {
			if (req[j] < req[s]) {
				s=j;
			}
		}
		temp = req[i];
		req[i] = req[s];
		req[s] = temp;
		if (!found && req[i] >= head) {
			found = true;
			p = i;
		}
	}
}

void scan() {
	int movts=0, i, j, temp, cur=head;
	printf("Head Movements: \n");
	for (i=p; i<n; i++) {
		printf("%d --> ", req[i]);
		movts += abs(req[i]-cur);
		cur = req[i];
	}
	for (i=p-1; i>=0; i--) {
		if (i) printf("%d --> ", req[i]);
		else printf("%d\n", req[i]);
		movts += abs(req[i]-cur);
		cur = req[i];
	}
	printf("No. of cylinder movements: %d\n", movts);
}

void cScan() {
	int movts=0, i, cur=head;
	printf("Head Movements: \n");
	for (i=p; i<n; i++) {
		printf("%d --> ", req[i]);
		movts += abs(req[i]-cur);
		cur = req[i];
	}
	for (i=0; i<p; i--) {
		if (i != p-1 ) printf("%d --> ", req[i]);
		else printf("%d\n", req[i]);
		movts += abs(req[i]-cur);
		cur = req[i];
	}
	printf("No. of cylinder movements: %d\n", movts);
}

void main()
{
	int i;
	char ch[2];
	do {
		printf("Enter the upper limit of cylinders: ");
		scanf("%d", &max);
		printf("Enter the disk head position: ");
		scanf("%d", &head);
		printf("Enter the no. of requests: ");
		scanf("%d", &n);

		printf("Enter the requests: \n");
		for (i=0; i<n; i++) 
			scanf("%d", &req[i]);

		printf("\nFCFS: \n");
		fcfs();

		sortRequests();

		printf("\nSCAN: \n");
		scan();

		printf("\nC-SCAN: \n");
		cScan();

		printf("\nDo you want to continue? Y/N: ");
		scanf("%s", ch);
	} while (ch[0]=='y' || ch[0]=='Y');
}