#include<stdio.h>
typedef struct{
	int id,at,bt,ct,wt,tat;
}process;
void sort(process l[],int n)
{
	process temp;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(l[j].at>l[j+1].at)
			{
				temp=l[j];
				l[j]=l[j+1];
				l[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n,t=0,i,ttat=0,twt=0;
	printf("No of process");
	scanf("%d",&n);
	process l[n];
	printf("AT n BT of processes");
	for(i=0;i<n;i++)
	{
		scanf("%d",&l[i].at);
		scanf("%d",&l[i].bt);
		l[i].id=i+1;
	}
	sort(l,n);
	for(i=0;i<n;i++)
	{
		
		t+=l[i].bt;
		l[i].ct=t;
		l[i].tat=l[i].ct-l[i].at;
		l[i].wt=l[i].tat-l[i].bt;
		ttat+=l[i].tat;
		twt+=l[i].wt;	
	}
	printf("process	at	bt	ct	wt	tat	\n");
	for(i=0;i<n;i++)
	{
		printf("%d	%d	%d	%d	%d	%d\n",l[i].id,
		l[i].at,l[i].bt,l[i].ct,l[i].wt,l[i].tat);
	}
	return 0;
}
