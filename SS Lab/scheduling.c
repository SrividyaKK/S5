#include <stdio.h>
#include <stdlib.h>

void main()
{
    struct process {
        int pname, arrival, burst, remaining, done, priority;
        float wt, tat;
    } * p, temp;

    int c, n, i, j, q, count = 0;
    float tot_time = 0, tot_wt = 0, tot_tat = 0;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    p = (struct process *)calloc(n, sizeof(struct process));
    for (i = 0; i < n; i++) {
        (p + i)->pname = i + 1;
        printf("Enter the arrival time, burst time and priority of process %d\n", i + 1);
        scanf("%d %d %d", &(p + i)->arrival, &(p + i)->burst, &(p + i)->priority);
        (p + i)->wt = (p + i)->tat = 0.0;
        (p + i)->done = 0;
        (p + i)->remaining = (p + i)->burst;
    }
    printf("Choose the CPU scheduling algorithm: \n1.FCFS\t2.SJF\t3.Priority\t4.RR\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1: //sort based on arrival time
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if ((p + j)->arrival > (p + j + 1)->arrival) {
                    temp = *(p + j);
                    *(p + j) = *(p + j + 1);
                    *(p + j + 1) = temp;
                }
            }
        }
        printf("Process\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
        for (i = 0; i < n; i++) {
            (p + i)->wt = tot_time - (p + i)->arrival;
            tot_time += (p + i)->burst; //process executes
            (p + i)->tat = (p + i)->wt + (p + i)->burst;
            tot_wt += (p + i)->wt;
            tot_tat += (p + i)->tat;
            printf("P[%d]\t%d\t\t%d\t\t%f\t%f\n", (p + i)->pname, (p + i)->arrival, (p + i)->burst, (p + i)->wt, (p + i)->tat);
        }
        printf("Average waiting time = %f\nAverage turnaround time = %f\n", tot_wt / n, tot_tat / n);
        break;
    case 2: //sort based on burst time
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if ((p + j)->burst > (p + j + 1)->burst) {
                    temp = *(p + j);
                    *(p + j) = *(p + j + 1);
                    *(p + j + 1) = temp;
                }
            }
        }
        printf("Process\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
        i = 0;
        while (count < n)
        {
            if ((p + i)->arrival <= tot_time) {
                (p + i)->wt = tot_time - (p + i)->arrival;
                tot_time += (p + i)->burst; //process executes
                (p + i)->tat = (p + i)->wt + (p + i)->burst;
                tot_wt += (p + i)->wt;
                tot_tat += (p + i)->tat;
                printf("P[%d]\t%d\t\t%d\t\t%f\t%f\n", (p + i)->pname, (p + i)->arrival, (p + i)->burst, (p + i)->wt, (p + i)->tat);
                (p + i)->done = 1;
                count++;
                i = 0;
                while (i < n) {
                    if ((p + i)->done == 0)
                        break;
                    i++;
                }
            }
            else
                i++;
        }

        printf("Average waiting time = %f\nAverage turnaround time = %f\n", tot_wt / n, tot_tat / n);
        break;

    case 3: //sort based on priority
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if ((p + j)->priority > (p + j + 1)->priority || ((p + j)->priority == (p + j + 1)->priority && (p + j)->arrival > (p + j + 1)->arrival))
                {
                    temp = *(p + j);
                    *(p + j) = *(p + j + 1);
                    *(p + j + 1) = temp;
                }
            }
        }
        printf("Process\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
        i = 0;
        while (count < n)
        {
            if ((p + i)->arrival <= tot_time) {
                (p + i)->wt = tot_time - (p + i)->arrival;
                tot_time += (p + i)->burst; //process executes
                (p + i)->tat = (p + i)->wt + (p + i)->burst;
                tot_wt += (p + i)->wt;
                tot_tat += (p + i)->tat;
                printf("P[%d]\t%d\t\t%d\t\t%f\t%f\n", (p + i)->pname, (p + i)->arrival, (p + i)->burst, (p + i)->wt, (p + i)->tat);
                (p + i)->done = 1;
                count++;
                i = 0;
                while (i < n)
                {
                    if ((p + i)->done == 0)
                        break;
                    i++;
                }
            }
            else
                i++;
        }

        printf("Average waiting time = %f\nAverage turnaround time = %f\n", tot_wt / n, tot_tat / n);
        break;

    case 4:
        printf("Enter the time quantum: ");
        scanf("%d", &q);
        //sort based on arrival time
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if ((p + j)->arrival > (p + j + 1)->arrival) {
                    temp = *(p + j);
                    *(p + j) = *(p + j + 1);
                    *(p + j + 1) = temp;
                }
            }
        }
        printf("Process\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
        i = 0;
        while (count < n)
        {
            if ((p + i)->remaining != 0) {
                if (q <= (p + i)->remaining) {
                    tot_time += q;
                    (p + i)->remaining -= q; //process executes 1 q
                }
                else {
                    tot_time += (p + i)->remaining;
                    (p + i)->remaining = 0;
                }
            }
            if ((p + i)->remaining == 0 && (p + i)->done == 0) //process completes execution
            {
                (p + i)->tat = tot_time - (p + i)->arrival;
                (p + i)->wt = (p + i)->tat - (p + i)->burst;
                tot_wt += (p + i)->wt;
                tot_tat += (p + i)->tat;
                count++;
                (p + i)->done = 1;
                printf("P[%d]\t%d\t\t%d\t\t%f\t%f\n", (p + i)->pname, (p + i)->arrival, (p + i)->burst, (p + i)->wt, (p + i)->tat);
            }
            i = (i + 1) % n;
        }
        printf("Average waiting time = %f\nAverage turnaround time = %f\n", tot_wt / n, tot_tat / n);
        break;

    default:
        printf("Invalid choice!\n");
    }
}