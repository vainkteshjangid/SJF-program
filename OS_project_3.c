#include<stdio.h>
#include<conio.h>
int n;
struct Process
{
	int procesId;
	int arrivalTime;
	int burstTime;
};

void main()
{
	struct Process p[n];
	int burst[n],arrival[n],allocation[n];
	int pid[n],wait[n];


	/*void getdata()
	{*/
	printf("Enter no. of processes:");
	scanf("%d",&n);
	
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
			if(i==0)
			{
				allocation[i]=0;
			}
			else
			allocation[i]=allocation[i-1]+burst[i-1];
 		}
 		
		
	
	
	int j;
	for(i=0;i<n;i++)
    {
        int pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst[j]<burst[pos] && arrival[j]<allocation[pos])
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
        
        int k;
        
        
        		
	}
	int k;
	for(k=i;k<n;k++)
        {
        	
       		if(k==0)
        	{
        		allocation[i]=0;
			}
			else
         	allocation[i]=allocation[i-1]+burst[i-1];	
			
		}
		printf("\nThe process will execute in the order:");
		for(i=0;i<n;i++)
		{
			printf(" P%d",pid[i]);
		}
	
	
	
		void waitingTime()
		{
			int i;
		for(i=0;i<n;i++)
		{
				if(i==0)
				{
				wait[i]=0;
				}
				else
				{
				wait[i]=allocation[i]-arrival[i];
				}
		}
		printf("\nwaiting Time                         :");
		for(i=0;i<n;i++)
		{
			printf("  %d",wait[i]);
		}
		};
		
		
		void display()
		{
		int i,j;
		printf("\n\nProcess\tarrivalTime\tburstTime\tallocationTime\twaitingTime");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[j].procesId=pid[i])
				{
					printf("\n     %d           %d         %d                %d	          %d",p[j].procesId,arrival[i],burst[i],allocation[i],wait[i]);
					break;
				}
			}
		}
		
		};
		
		

	waitingTime();
	display();
		
	getch();
}
