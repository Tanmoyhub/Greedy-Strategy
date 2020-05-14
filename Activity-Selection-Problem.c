/*Write a C program to implement Activity Selection Problem using Greedy Strategy.*/
/*
Tanmoy Ghosh
Computer Science & Engineering Department
Hooghly Engineering & Technology College
*/

#include<stdio.h>
#include<time.h>
int n;
struct timestamp
{
    int start;
    int end;
};
void selection(struct timestamp sample[])
{
    int i,a[50],c=1,j=1,prev;
    a[0]=1;
    prev=sample[0].end;
    for(i=1;i<n;i++)
    {
        if(prev<=sample[i].start)
        {
            c++;
            a[j++]=(i+1);
            prev=sample[i].end;
        }
    }
    printf("Maximum %d activities can be performed.",c);
    printf("\nActivities are: ");
    for(i=0;i<c;i++)
    {
        printf(" %d ",a[i]);
        if(i!=c-1)
        printf("-->");
    }
    
}
void main()
{
    int i;
    double s,e,t;
    struct timestamp sample[50];
    printf("Enter the number of activities: ");
    scanf("%d",&n);
    printf("Enter the timeslots: \n");
    for(i=0;i<n;i++)
    {
        printf("Enter the start time of Activity %d: ",i+1);
        scanf("%d",&sample[i].start);    
        printf("Enter the End time of Activity %d: ",i+1);
        scanf("%d",&sample[i].end);
    }
    s=clock();
    selection(sample);
    e=clock();
    t=(e-s)/(double)CLOCKS_PER_SEC;
    printf("\nTime taken by the program: %e seconds.",t);
}
