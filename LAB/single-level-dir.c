// Simulate single-level directory structure.
#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    int i, j=0;
    char ch[2];
    char dName[10], fName[10][10], name[10];
    printf("Enter the directory name: ");
    scanf("%s", dName);

    do {
        printf("Enter filename: ");
        scanf("%s", name);

        for (i=0; i<j; i++) {
            if (!strcmp(name, fName[i]))
                break;
        }
        if (i==j) {
            strcpy(fName[j++], name);
        } else {
            printf("File %s already exists!\n\n", name);
        }
        if (j == 10) break;
        printf("Do you want to create another file ? Y/N: ");
        scanf("%s", ch);
    } while (ch[0] == 'y');
    printf("\nFiles in directory %s: \n", dName);
    for (i=0; i<j; i++)
        printf("%s\n", fName[i]);
}