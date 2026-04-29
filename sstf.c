#include <stdio.h>
int sstf(int requests[],int n,int head,int visited[])
{
    int min_distance=1e9;
    int sstf_index=-1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;
        int diff = abs(requests[i]-head);
        if(diff<min_distance)
        {
            min_distance=diff;
            sstf_index=i;        }

    }
    visited[sstf_index]=1;
    return requests[sstf_index];
}
int main()
{
    int n;
    printf("Enter the number of disk requests : ");
    scanf("%d",&n);
    int requests[n];
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i]=0;
    printf("Enter the requests sequence : ");
    for(int i=0;i<n;i++)
        scanf("%d",&requests[i]);

    int head;
    printf("Enter initial head position : ");
    scanf("%d",&head);


    int total=0;
    for(int i=0;i<n;i++)
    {
        int origHead=head;
        head = sstf(requests,n,head,visited);
        printf("\nMoved to : %d",head);
        total+=abs(origHead-head);
    }
    printf("\nTotal R/W Head Movement : %d",total);
    return 0;
}
