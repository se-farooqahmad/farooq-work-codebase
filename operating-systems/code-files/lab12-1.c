#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}dir[10];
void main()
{
    int i,ch,n,d;
    char f[30];
    dir[10].fcnt = 0;
    printf("You are at the root level right now\n");
    printf("Enter the Number of directories you want to create :\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the Name of the Directory %d :",i);
        scanf("%s",dir[i].dname);
        dir[i].fcnt++;
    }
    while(1)
    {
        printf("\nEnter the Number of directory you want to entertain : ");
        scanf("%d",&d);
        printf("You have Entered Directory %d ",d);
        printf("\n\n1. Create File\t2. Delete File\t3. Search File  4. Display Files\t5. Exit\nEnter your choice -- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the name of the file -- ");
            scanf("%s",dir[d].fname[dir[d].fcnt]);
            dir[d].fcnt++;
            break;
            case 2:
            printf("\nEnter the name of the file -- ");
            scanf("%s",f);
            for(i=0;i<dir[d].fcnt;i++)
            {
                if(strcmp(f, dir[d].fname[i])==0)
                {
                    printf("File %s is deleted ",f);
                    strcpy(dir[d].fname[i],dir[d].fname[dir[d].fcnt-1]);
                    break;
                }
            }
            if(i==dir[d].fcnt)
                printf("File %s not found",f);
            else
                dir[d].fcnt--;
            break;
            case 3: 
            printf("\nEnter the name of the file -- ");
            scanf("%s",f);
            for(i=0;i<dir[d].fcnt;i++)
            {
                if(strcmp(f, dir[d].fname[i])==0)
                {
                    printf("File %s is found ", f);
                    break;
                }
            }
            if(i==dir[d].fcnt)
                printf("File %s not found",f);
            break;
            case 4: 
            if(dir[d].fcnt==0)
                printf("\nDirectory Empty");
            else
            {
                printf("\nThe Files are -- ");
                for(i=0;i<dir[d].fcnt;i++)
                    printf("\t%s",dir[d].fname[i]);
            }
            break;
            default: exit(0); 
        }

    }
}