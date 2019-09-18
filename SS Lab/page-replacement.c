/* Simulate the foll page replacement algorithms: 
1. FIFO
2. LRU
3. LFU
*/

#include<stdio.h>

int n_frames, n_pages, pNo, avlbl, pages[50], frames[10];

int find(int x, int f[]) {
	// if x in f, return 1, else 0
	int i;
	for (i=0; i<n_frames; i++)
		if (f[i] == x) return 1;
	return 0;
}

void print_frames(int ref, char fault) {
	int i;
	printf("%d\t", ref);
	for (i=0; i<n_frames; i++)
		printf("%d ", frames[i]);
	printf("%c\n", fault);
}

void FIFO() {
	int i, j, k, count=0; // count gives the number of page faults
	for (i=0; i<n_frames; i++)
		frames[i] = -1;
	i=0;
	printf("FIFO PAGE REPLACEMENT: \n");
	printf("ref str\t page frames\n");
	for (j=0; j<n_pages; j++) {
		char fault=' ';
		if (!find(pages[j], frames)) { // page is not in a frame yet
			count++; // page fault occurred;
			// bring page into frame:
			frames[i] = pages[j];
			i = (i+1) % n_frames;
			// fault='F';
		}
		print_frames(pages[j], fault);
	}
	printf("No. of page faults=%d\n", count);
}

void LRU() {

}

void LFU() {

}

void main()
{
	char ch[2];
	int i;
	do {
		printf("Enter the number of frames: ");
		scanf("%d", &n_frames);
		printf("Enter the no. of pages accessed: ");
		scanf("%d", &n_pages);
		printf("Enter the page reference string (as space-separated integers): \n");
		for (i=0; i<n_pages; i++)
			scanf("%d", &pages[i]);

		FIFO();

		LRU();

		LFU();

		printf("Do you want to continue? Y/N: ");
		scanf("%s", ch);
	} while (ch[0] == 'y' || ch[0] == 'Y');
}