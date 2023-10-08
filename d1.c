#include<stdio.h>
#include<math.h>
int main()
{
	int n,head,i;
	printf("Limit");
	scanf("%d",&n);
	printf("head");
	scanf("%d",&head);
	int l[n];
	printf("Vals");
	l[0]=head;
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&l[i]);
	}
	int seekdis=0,k;
	for(i=0;i<n;i++)
	{
		k=fabs(l[i]-l[i+1]);
		seekdis+=k;
		printf("%d->",l[i]);	
	}
	printf("%d",l[i]);
	printf("	%d",seekdis);
	return 0;
}
