#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_element {
	char name[20];
	int ftype, nc, level;
	struct tree_element *link[5];
} node;

void create(node **root, int level, char *dName, int ftype) {
	int i;
	if (*root == NULL) {
		(*root) = (node *)malloc(sizeof(node));
		// printf("Enter 1 for Dir / 2 for file: ");
		// scanf("%d", &(*root)->ftype);
		(*root)->ftype = ftype;
		(*root)->level = level;
		(*root)->nc = 0; // no. of children
		for (i=0; i<5; i++)
			(*root)->link[i] = NULL;
	} else {

	}
}

void main()
{
	int ch, ftype;
	char d[15], f[15], path[50], delim[] = "/";
	node *root = NULL;
	while (1) {
		printf("\n1. Create directory. \n2. Create file. \n3. Delete File. \n4. Search for directory. \n5. Search for file. \n6. Delete directory. \n7. Display. \n8. Exit. \nENTER CHOICE: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1: // create directory
			ftype=1;
			printf("Enter the directory name: ");
			scanf("%s", d);
			if (root==NULL) create(&root, 0, d, ftype);
			else {
				printf("Enter path (excluding directory name): ");
				scanf("%s", path);
				char *token = strtok(path, delim);
				while (token != NULL) {
					printf("%s\n", token);
					token = strtok(NULL, delim);
				}
				// create(&root, 1, d, ftype);
			}
			break;
		case 2: // create file
			break;
		case 3: // delete file
			break;
		case 4: // search for directory
			break;
		case 5: // search for file
			break;
		case 6: // delete directory
			break;
		case 7: // display
			break;
		default:
			exit(0);
		}
	}
}