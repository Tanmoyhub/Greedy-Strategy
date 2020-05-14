/*Write a C program to implement Job Sequencing Problem using Greedy Strategy.*/
/* 
Tanmoy Ghosh
Computer Science & Engineering Department
Hooghly Engineering & Technology College
*/
#include<stdio.h>
#include<limits.h>
#include<time.h>
int n,max=0;
struct job 
{
    char ch;
    int profit;
    int deadline;
};
typedef struct job job;
job work[20];
void sequence()
{
    int a[max],mp=0,i,j,k;
    for(i=0;i<max;i++)
        a[i]=INT_MAX;
    for(i=0;i<n;i++)
    {
        j=work[i].deadline;
        if(a[j-1]==INT_MAX)
        {
            a[j-1]=i;
            mp+=work[i].profit;
        }
        else if(j>1)
        {
            for(k=j-1;k>=0;k--)
            {
                if(a[k]==INT_MAX)
                {
                    a[k]=i;
                    mp+=work[i].profit;
                }
            }
        }
    }
    printf("Sequence of Jobs is:");
    for(i=0;i<max;i++)
    {
        j=a[i];
        if(j!=INT_MAX)
        printf(" %c ",work[j].ch);
        if((i!=max-1)&&(j!=INT_MAX))
        printf("-->");
    }
    printf("\nMaximum Profit is: %d",mp);
    
}
int partition(int l,int u)
{
    int i,j,x;
    job t;
    x=work[u].profit;
    i=l-1;
    for(j=l;j<u;j++)
    {
        if(work[j].profit>=x)
        {
            i++;
            t=work[i];
            work[i]=work[j];
            work[j]=t;
        }
    }
    t=work[i+1];
    work[i+1]=work[u];
    work[u]=t;
    return (i+1);
}
void sort(int l,int u)
{
    int q;
    if(l<u)
    {
        q=partition(l,u);
        sort(l,q-1);
        sort(q+1,u);
    }
}
void main()
{
    int i;
    double s,e,t;
    printf("Enter the total no. of jobs: ");
    scanf("%d",&n);
    printf("Enter the details: \n");
    for(i=0;i<n;i++)
    {
        printf("Enter the name of the job: ");
        while ((getchar())!='\n');
        scanf("%c",&work[i].ch);
        printf("Enter the deadline of the job: ");
        scanf("%d",&work[i].deadline);
        printf("Enter the profit of the job: ");
        scanf("%d",&work[i].profit);
        if(max<=work[i].deadline)
            max=work[i].deadline;
    }
    s=clock();
    sort(0,n-1);
    sequence();
    e=clock();
    t=(e-s)/(double)CLOCKS_PER_SEC;
    printf("\nTime taken by the program: %e seconds.",t);
}
