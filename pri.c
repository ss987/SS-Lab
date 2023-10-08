#include<stdio.h>
typedef struct{
	int id,at,bt,ct,wt,tat,p,rt;
}process;
int main()
{
	int n,t=0,i,ttat=0,twt=0,completed=0,q;
	printf("No of process");
	scanf("%d",&n);
	process l[n];
	printf("AT n BT and priority of processes");
	for(i=0;i<n;i++)
	{
		scanf("%d",&l[i].at);
		scanf("%d",&l[i].bt);
		scanf("%d",&l[i].p);
		l[i].id=i+1;
		l[i].rt=l[i].bt;
	}
	while(completed<n)
	{
		int sj=-1;
		for(i=0;i<n;i++)
		{
			
			if(l[i].p>sj && l[i].rt>0 && l[i].at<=t)
			{
				sj=i;
				
			}
		}
		if(sj==-1)
			t++;
		else
		{
			t++;
			l[sj].rt--;
			if(l[sj].rt==0)
			{
				l[sj].ct=t;
				l[sj].tat=l[sj].ct-l[sj].at;
				l[sj].wt=l[sj].tat-l[sj].bt;
				completed++;
				twt+=l[sj].wt;
			}
		}	
	}
	printf("process	at	bt	ct	wt	tat	pri\n");
	for(i=0;i<n;i++)
	{
		printf("%d	%d	%d	%d	%d	%d	%d\n",l[i].id,
		l[i].at,l[i].bt,l[i].ct,l[i].wt,l[i].tat,l[i].p);
	}
	printf("Avg wt=%f",(float)twt/n);
	return 0;
}
