// Simulate single-level directory structure.
#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    int i, fCount=0, ch;
    char dName[10], fName[10][10], name[10];
    printf("Enter the directory name: ");
    scanf("%s", dName);

    while (1) {
        printf("\n1. Create file. \n2. Delete file. \n3. Search file. \n4. Display files. \n5. Exit. \nENTER CHOICE: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // Create file
            if (fCount < 10) {
                printf("Enter filename: ");
                scanf("%s", name);

                for (i=0; i<fCount; i++) {
                    if (!strcmp(name, fName[i]))
                        break;
                }
                if (i==fCount) {
                    strcpy(fName[fCount++], name);
                    printf("File created\n");
                } else {
                    printf("File %s already exists!\n", name);
                }
            } else {
                printf("Directory full!\n");
            }
            break;
        case 2: // Delete file
            if (fCount) {
                printf("Enter the name of the file: ");
                scanf("%s", name);
                for (i = 0; i < fCount; i++) {
                    if (!strcmp(name, fName[i])) {
                        printf("Deleting file %s\n", name);
                        strcpy(fName[i], fName[--fCount]);
                        break;
                    }
                }
                if (i == fCount)
                    printf("File %s not found!\n", name);
            } else {
                printf("Directory empty!\n");
            }
            break;
        case 3: // Search file
            printf("Enter the name of the file: ");
            scanf("%s", name);
            for (i = 0; i < fCount; i++) {
                if (!strcmp(name, fName[i])) {
                    printf("File %s found!\n", name);
                    break;
                }
            }
            if (i == fCount)
                printf("File %s not found!\n", name);
            break;
        case 4: // Display files
            printf("\nFiles in directory %s: \n", dName);
            for (i = 0; i < fCount; i++)
                printf("%s\n", fName[i]);
            break;
        default:
            exit(0);
        }
    }
}