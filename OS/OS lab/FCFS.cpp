#include<iostream>
using namespace std;


void findWaitingTime(int processes[],int n,int bt[],int wt[])
{
    wt[0]=0;

    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }

}

void turnAroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)   
    {
        tat[i]=wt[i]+bt[i];
    }
}

void findAverageTime(int processes[],int n,int bt[])
{
    int wt[n], tat[n];
    int total_wt=0;
    int total_tat=0;

    findWaitingTime(processes,n,bt,wt);

    turnAroundTime(processes,n,bt,wt,tat);

    cout<<"Process ID"<<"  "<<"Burst Time"<<"  "<<"Waiting Time"<<"  "<<"Turaround Time"<<endl;

    for(int i=0;i<n;i++)
    {
        total_wt=total_wt+wt[i];

        total_tat=total_tat+tat[i];

        cout<<" "<<i+1<<"     \t "<<bt[i]<<"           "<<wt[i]<<"              "<<tat[i]<<endl;
    }

    cout<<"Average Waiting Time ";
    float awt;
    awt= (float)total_wt/(float)n;
    cout<<awt;

    cout<<"Average Turnaround time ";
    float atat;
    atat=(float)total_tat/(float)n;
    cout<<atat;
}


int main()
{
    int processes[100];
    cout<<"Enter Total number of Process ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>processes[i];
    }


    int burst_time[100];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter Burst time for process "<<i+1<<" ";
        cin>>burst_time[i];
    }

    findAverageTime(processes,n,burst_time);
    
    return 0;
}