#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    char name[128];
    bool isDir;
    struct node *p; // parent
    struct node *c[100]; // children
    int i; // no of children
} * head, *curr;

void ls()
{
    if (curr->i == 0)
    {
        printf("Directory Empty!\n");
        return;
    }
    for (int i = 0; i < curr->i; i++)
    {
        if (curr->c[i]->isDir)
            printf("*%s*  ", curr->c[i]->name);
        else
            printf("%s  ", curr->c[i]->name);
    }
}

void touch(bool d)
{
    printf("Enter filename: ");
    char fname[128];
    scanf("%s", fname);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name, fname);
    temp->isDir = d;
    temp->p = curr;
    curr->c[curr->i] = temp;
    curr->i = (curr->i) + 1; // increment the no. of children
}

void cd() // relative path - from current directory
{
    printf("Enter directory name: ");
    char dname[128];
    scanf("%s", dname);
    for (int i = 0; i < curr->i; i++)
    {
        if (!strcmp(curr->c[i]->name, dname) && curr->c[i]->isDir == true)
        {
            curr = curr->c[i];
            return;
        }
    }
    printf("Directory not present.\n");
}

void cdup()
{
    if (curr->p == NULL)
    {
        printf("You are at the root directory\n");
        return;
    }
    curr = curr->p;
    printf("Changed directory to: %s. \n", curr->name);
}

void rm(bool d)
{
	char type[] = d === true ? "directory" : "file";
    // printf("Enter name of file or directory to delete: ");
    printf("Enter name of %s to delete: ", type);
    char name[128];
    scanf("%s", name);
    for (int i = 0; i < curr->i; i++)
    {
        if (!strcmp(curr->c[i]->name, name) && ((d && curr->c[i]->isDir == true) || (!d && curr->c[i]->isDir == false)))
        {
            int t = i;
            while (t < (curr->i) - 1)
            {
                curr->c[t] = curr->c[t + 1];
                t++;
            }
            curr->i = (curr->i) - 1;
            printf("Successfully deleted.\n");
            return;
        }
    }
    printf("Not found\n");
}

void main()
{
    int in;
    head = (struct node *)malloc(sizeof(struct node));
    strcpy(head->name, "root");
    head->isDir = true;
    head->p = NULL;
    head->i = 0;
    curr = head;
    while (true)
    {
        printf("\n\nYou are in %s directory. \n1. List directory. \n2. Change directory. \n3. Go to parent directory. \n4. Add new file. \n5. Delete file. \n6. Create new directory. \n7. Delete directory. \n8. Exit. \nENTER CHOICE: ", curr->name);
        scanf("%d", &in);
        switch (in)
        {
        case 1:
            ls();
            break;
        case 2:
            cd();
            break;
        case 3:
            cdup();
            break;
        case 4:
            touch(false);
            break;
        case 5:
            rm(false);
            break;
        case 6:
            touch(true);
            break;
        case 7:
            rm(true);
            break;
        default:
            exit(0);
        }
    }
}