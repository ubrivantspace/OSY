#include <stdio.h>
#include <stdlib.h>

void FCFS(int arr[], int size, int head)
{
    int seek_count = 0;
    int cur_track, distance;

    for(int i = 0; i < size; i++)
    {
        cur_track = arr[i];
        distance = abs(head - cur_track);
        seek_count += distance;
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

    int arr[size];

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
