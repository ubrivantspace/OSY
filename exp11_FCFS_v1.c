// C program for FCFS Disk Scheduling with user input
#include <stdio.h>
#include <stdlib.h>  // for abs()

void FCFS(int arr[], int size, int head)
{
    int seek_count = 0;
    int cur_track, distance;

    for(int i = 0; i < size; i++)
    {
        cur_track = arr[i];

        // calculate absolute distance
        distance = abs(head - cur_track);

        // increase total seek count
        seek_count += distance;

        // move head to current track
        head = cur_track;
    }

    printf("\nTotal number of seek operations: %d\n", seek_count);

    printf("Seek Sequence is:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int size, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &size);

    int arr[size];  // Variable Length Array (C99)

    printf("Enter the request sequence:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    FCFS(arr, size, head);

    return 0;
}
