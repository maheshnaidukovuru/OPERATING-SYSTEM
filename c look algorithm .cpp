#include <stdlib.h>
#include<stdio.h>
int main(){
    int request[100],i,j,n,TotalHeadMoment=0,initial,size,move,temp,index;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for (i=0;i<n;i++)
        scanf("%d",&request[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);
    for (i=0;i<n;i++)
	{
        for (j=0;j<n-i-1;j++)
		{
            if (request[j]>request[j+1])
			{
                temp=request[j];
                request[j]=request[j+1];
                request[j+1]=temp;
            }
        }
    }
    for (i=0;i<n;i++)
	{
        if (initial<request[i])
		{
            index = i;
            break;
        }
    }
    if (move==1)
	{
        for (i=index;i<n;i++){
            TotalHeadMoment=TotalHeadMoment+abs(request[i]-initial);
            initial=request[i];
        }
        for (i=0;i<index;i++){
            TotalHeadMoment=TotalHeadMoment+abs(request[i]-initial);
            initial=request[i];
        }
    }
    else
	{
        for (i=index-1;i>=0;i--){
            TotalHeadMoment=TotalHeadMoment+abs(request[i]-initial);
            initial=request[i];
        }
        for (i=n-1;i>=index;i--){
            TotalHeadMoment=TotalHeadMoment+abs(request[i]-initial);
            initial=request[i];
        }
    }
    printf("Total head movement is %d\n", TotalHeadMoment);
    return 0;
}
