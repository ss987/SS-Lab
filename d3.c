#include<stdio.h>
#include<math.h>
int main()
{
	int n,head,i,j;
	printf("Limit");
	scanf("%d",&n);
	printf("head");
	scanf("%d",&head);
	int q[n+3],q1[n],q2[n],a,i1=0,i2=0,i3=1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a<=head)
		{
			q1[i1]=a;
			i1++;
		}
		else
		{
			q2[i2]=a;
			i2++;
		}
	}
	for(i=0;i<i1;i++)
	{
		for(j=0;j<i1-i-1;j++)
		{
			if(q1[j]<q1[j+1])
			{
				int temp=q1[j];
				q1[j]=q1[j+1];
				q1[j+1]=temp;
			}
		}
	}
	for(i=0;i<i2;i++)
	{
		for(j=0;j<i2-i-1;j++)
		{
			if(q2[j]>q2[j+1])
			{
				int temp=q2[j];
				q2[j]=q2[j+1];
				q2[j+1]=temp;
			}
		}
	} 
	q[0]=head;
	for(i=0;i<i2;i++)
	{
		q[i3]=q2[i];
		i3++;
	}
	q[i3]=199;
	
	i3+=1;
	for(i=0;i<i1;i++)
	{
		q[i3]=q1[i];
		i3++;
	}
	q[i3]=0;
	int seekdis=0,k;
	for(i=0;i<n+2;i++)
	{
		k=fabs(q[i]-q[i+1]);
		seekdis+=k;
		printf("%d->",q[i]);	
	}
	printf("%d",q[i]);
	printf("	%d",seekdis);
	return 0;
}
