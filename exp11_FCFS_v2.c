#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int head, total_seek = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the disk requests:\n");
    for(i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\n----- FCFS Disk Scheduling -----\n");

    printf("\nStep-by-step movement:\n");
    printf("Current Head\tNext Request\tSeek Time\n");

    for(i = 0; i < n; i++) {
        int distance = abs(req[i] - head);
        printf("%d\t\t%d\t\t%d\n", head, req[i], distance);

        total_seek += distance;
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", total_seek);

    printf("\nSeek Sequence: ");
    for(i = 0; i < n; i++) {
        printf("%d ", req[i]);
    }
    printf("\n");

    return 0;
}
