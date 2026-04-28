#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of disk requests : ");
    scanf("%d",&n);
    int requests[n];
    int total=0;
    int head=53;
    printf("Enter the requests sequence : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&requests[i]);

        total+= abs(requests[i]-head);
        head = requests[i];
    }
        printf("Total R/W Head Movement : %d",total);


    return 0;
}

