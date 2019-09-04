#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int mutex=1, n, full=0, empty, buffer[25], temp=0, f=-1, r=-1;

void wait(int *s)
{
	(*s)--;
}

void signal(int *s)
{
	(*s)++;
}

void producer() {
	int x;
	wait (&mutex);
	signal(&full);
	wait(&empty);
	// produce an item
	printf("Enter the item to be produced: ");
	scanf("%d", &x);

	// place the item in buffer
	if (f==-1) f++;
	r = (r+1)%n;
	buffer[r] = x;
	printf("Produced item: %d\n\n", x);

	signal(&mutex);
}

void consumer() {
	wait(&mutex);
	wait(&full);
	signal(&empty);

	//remove an item from buffer
	int x = buffer[f];
	if (f==r) f=r=-1;
	else f = (f+1)%n;

	signal(&mutex);

	// consume the item
	printf("Consumed item: %d\n\n", x);
}

void main()
{
	int ch;
	printf("Enter the size of the buffer: ");
	scanf("%d", &n);
	empty=n;
	while (true) 
	{
		printf("1. Producer. \n2. Consumer. \n3.Exit. \nENTER CHOICE: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: 
				if (empty)
					producer();
				else 
					printf("Buffer full!\n\n");
				break;
			case 2: 
				if (full)
					consumer();
				else 
					printf("Buffer empty!\n\n");
				break;
			default: exit(0);
		}
	}
}