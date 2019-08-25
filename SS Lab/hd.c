#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_element {
	char name[20];
	int ftype, nc, level;
	struct tree_element *link[5];
} node;

void create(node **root, int level, char *dName) {
	int i;
	if (*root == NULL) {
        (*root) = (node *)malloc(sizeof(node));
        printf("\nEnter name of dir/file (under %s): ", dName);
        scanf("%s", (*root)->name);
        printf("Enter 1 for directory / 2 for file: ");
        scanf("%d", &(*root)->ftype);
        (*root)->level = level;
        for (i = 0; i < 5; i++)
            (*root)->link[i] = NULL;
        if ((*root)->ftype == 1) { // directory
            printf("No. of sub directories/files (for %s): ", (*root)->name);
            scanf("%d", &(*root)->nc);
            for (i = 0; i < (*root)->nc; i++)
                create(&((*root)->link[i]), level+1, (*root)->name);
        }
        else
            (*root)->nc = 0;
    }
}

void display(node *root) {
    int i;
    if (root != NULL) {
        if (root->ftype == 1) {
            printf("DIRECTORY: %s\n", root->name);
        } else {
            printf("File: %s\n", root->name);
        }
        for (i=0; i<root->nc; i++) {
            display(root->link[i]);
        }
    }
}

void main()
{
	char d[15], f[15];
	node *root = NULL;
    create(&root, 0, "root");
    printf("\n\n");
    display(root);
}