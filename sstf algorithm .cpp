//shortest seek time  disc scheduling
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int request[100],i,n,totalheadmoment=0,initial,count=0,min,distance,index;
	printf("enter the number of request:");
	scanf("%d",&n);
	printf("enter the request sequence:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&request[i]);
	}
	printf("enter the initial head position:");
	scanf("%d",&initial);
	while(count!=n)
	{
		min=1000;
		for(i=0;i<n;i++)
		{
			distance=abs(request[i]-initial);
			if(min>distance)
			{
				min=distance;
				index=i;
				
			}
		}
		totalheadmoment=totalheadmoment+min;
		initial=request[index];
		request[index]=1000;
		count++;
	}
	printf("total head moment=%d",totalheadmoment);
	return 0;
}
