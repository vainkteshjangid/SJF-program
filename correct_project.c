#include<stdio.h>
int n;
struct Process
{
	int procesId;
	int arrivalTime;
	int burstTime;
};
void main()
{
	printf("Enter no. of processes:");
	scanf("%d",&n);
	struct Process p[n];
	int burst[n],arrival[n];
	int pid[n];
		int i;
		printf("\nEnter data:-");
		for(i=0;i<n;i++)
		{
			printf("\nProcess%d:-",i+1);
			printf("\narrivalTime:");
			scanf("%d",&p[i].arrivalTime);
			arrival[i]=p[i].arrivalTime;
			printf("\nburstTime:");
			scanf("%d",&p[i].burstTime);
			burst[i]=p[i].burstTime;
			pid[i]=i+1;
			p[i].procesId=pid[i];
		}
	
	int wait[n];
	
	
		
		
	
		
	int j;
	for(i=0;i<n;i++)
    {
        int pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst[j]<burst[pos])
            pos=j;
        }
 
        int temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
 
        temp=pid[i];
        pid[i]=pid[pos];
        pid[pos]=temp;
        
        temp=arrival[i];
        arrival[i]=arrival[pos];
        arrival[pos]=temp;
        
    }
		printf("\nThe process will execute in the order:");
		for(i=0;i<n;i++)
		{
			printf(" P%d",pid[i]);
		}
		
		//waitingTime()
		for(i=0;i<n;i++)
		{
				if(i==0)
				{
				wait[i]=0;
				}
				else
				{
				wait[i]=wait[i-1]+burst[i-1];
				}
		}
		printf("\nwaiting Time                         :");
		for(i=0;i<n;i++)
		{
			printf("  %d",wait[i]);
		}
		
		printf("\n\nProcess\tarrivalTime\tburstTime\twaitingTime");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[j].procesId=pid[i])
				{
					printf("\n     %d           %d         %d           %d",p[i].procesId,arrival[i],burst[i],wait[i]);
				}
			}
		}
	
}
