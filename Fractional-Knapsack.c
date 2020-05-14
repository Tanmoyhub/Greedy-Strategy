/*Write a C program to implement fractional knapsack using Greedy approach.*/
/*
Tanmoy Ghosh
Computer Science & Engineering Department
Hooghly Engineering & Technology College
*/
#include<stdio.h>
int n;
float w[100],c[100],p[100],cap;
void knapsack()
{
	int i;
	float sv[100],mp=0.000000;
	for(i=0;i<n;i++)
	    sv[i]=0.000000;
	for(i=0;i<n;i++)
	{
		if(w[i]<=cap)
		{
			cap-=w[i];
			sv[i]=1.000000;
			mp+=(sv[i]*w[i]*p[i]);
		}
		else
		{
			sv[i]=cap/w[i];
			mp+=(sv[i]*w[i]*p[i]);
			break;
		}
	}
	printf("\nSolution vector is: ");
	for(i=0;i<n;i++)
	printf(" %.2f ",sv[i]);
	printf("\nMaximum profit that can be earned: %.2f",mp);
}
int partition(int l,int u)
{
	int i,j,x,t;
	x=p[u];
	i=l-1;
	for(j=l;j<u;j++)
	{
		if(p[j]>=x)
		{
			i++;
			t=p[i];
			p[i]=p[j];
			p[j]=t;
			t=w[i];
			w[i]=w[j];
			w[j]=t;
		}
	}
	t=p[i+1];
	p[i+1]=p[u];
	p[u]=t;
	t=w[i+1];
	w[i+1]=w[u];
	w[u]=t;
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
	printf("Enter the number of items: ");
	scanf("%d",&n);
	printf("Enter the item details: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter the Weight of item %d: ",(i+1));
		scanf("%f",&w[i]);
		printf("Enter the Cost of item %d: ",(i+1));
		scanf("%f",&c[i]);
		p[i]=c[i]/w[i];
	}
	printf("Enter the capacity of the knapsack: ");
	scanf("%f",&cap);
	sort(0,n-1);
	printf("After rearranging weights of the items: ");
	for(i=0;i<n;i++)
	printf(" %.2f ",w[i]);
	printf("\nPriority of the items: ");
	for(i=0;i<n;i++)
	printf(" %.2f ",p[i]);
	knapsack();
}
