// C program to simulate the Two level directory File organization technique
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char dName[10], fName[10][10];
    int fCount; // no. of files
} directory;

void main()
{
    directory dir[10];
    int i, ch, dCount=0, k, found;
    char f[30], d[30];
    while (1)
    {
        printf("\n1. Create Directory. \n2. Create File. \n3. Delete File. \n4. Search file. \n5. Display. \n6. Exit. \nENTER CHOICE: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // create directory
            printf("Enter the name of the directory: ");
            scanf("%s", dir[dCount].dName);
            dir[dCount].fCount = 0;
            dCount++;
            printf("Directory created\n");
            break;
        case 2:  // create file
            printf("Enter the name of the directory: ");
            scanf("%s", d);
            for (i=0; i<dCount; i++) {
                if (strcmp(d, dir[i].dName) == 0) {
                    printf("Enter the name of the file: ");
                    scanf("%s", f);
                    for (k=0; k<dir[i].fCount; k++) {
                        if (!strcmp(f, dir[i].fName[k]))
                            break;
                    }
                    if (k==dir[i].fCount) {
                        strcpy(dir[i].fName[dir[i].fCount++], f);
                        printf("File created\n");
                    } else {
                        printf("File %s already exists!\n\n", f);
                    }
                    break;
                }
            }
            if (i==dCount) 
                printf("Directory %s not found!\n", d);
            break;
        case 3: // delete file
            printf("Enter the name of the directory: ");
            scanf("%s", d);
            for (i = 0; i < dCount; i++)
            {
                if (strcmp(d, dir[i].dName) == 0)
                {
                    if (dir[i].fCount) {
                        printf("Enter the name of the file: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fCount; k++)
                        {
                            if (strcmp(f, dir[i].fName[k]) == 0)
                            {
                                printf("Deleted file: %s\n", f);
                                dir[i].fCount--;
                                strcpy(dir[i].fName[k], dir[i].fName[dir[i].fCount]);
                                goto jmp;
                            }
                        }
                        printf("File %s not found!\n", f);
                        goto jmp;
                    } else {
                        printf("Directory empty!\n");
                    }
                }
            }
            printf("Directory %s not found!\n", d);
            jmp: break;
        case 4: // search
            found = 0;
            printf("Enter name of the file: ");
            scanf("%s", f);
            for (i=0; i<dCount; i++) {
                for (k=0; k<dir[i].fCount; k++) {
                    if (strcmp(f, dir[i].fName[k]) == 0) {
                        printf("File %s found in directory: %s\n", f, dir[i].dName);
                        found = 1;
                    }
                }
            }
            if (!found) printf("File %s not found in any directory!\n", f);
            break;
        case 5: // display
            if (dCount == 0)
                printf("No directories!\n");
            else {
                for (i=0; i<dCount; i++) {
                    printf("DIRECTORY: %s\n", dir[i].dName);
                    if (dir[i].fCount) {
                        for (k=0; k<dir[i].fCount; k++)
                            printf("%s\n", dir[i].fName[k]);
                        printf("\n");
                    } else {
                        printf("Empty!\n\n");
                    }
                }
            }
            break;
        default:
            exit(0);
        }
    }
}