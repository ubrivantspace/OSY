#include <stdio.h>

int main() {
    int n, i, j;
    int pid[10], at[10], bt[10], ct[10], tat[10], wt[10], rt[10];
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                int temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    printf("\n--- VISUAL GANTT CHART ---\n");

    printf(" ");
    int temp_time = 0;
    for(i = 0; i < n; i++) {
        if(temp_time < at[i]) {
            for(j=0; j < (at[i]-temp_time)+6; j++) printf("-");
            temp_time = at[i];
        }
        for(j=0; j < bt[i]+6; j++) printf("-");
        temp_time += bt[i];
    }
    printf("\n");

    printf("|");
    time = 0;
    for(i = 0; i < n; i++) {
        if(time < at[i]) {
            printf(" Idle |");
            time = at[i];
        }
        printf("  P%d  |", pid[i]);
        time += bt[i];
        ct[i] = time;
    }

    printf("\n ");
    temp_time = 0;
    for(i = 0; i < n; i++) {
        if(temp_time < at[i]) {
            for(j=0; j < (at[i]-temp_time)+6; j++) printf("-");
            temp_time = at[i];
        }
        for(j=0; j < bt[i]+6; j++) printf("-");
        temp_time += bt[i];
    }

    printf("\n0");
    time = 0;
    for(i = 0; i < n; i++) {
        if(time < at[i]) {
            printf("%*d", (at[i]-time)+7, at[i]);
            time = at[i];
        }
        printf("%*d", bt[i]+7, time + bt[i]);
        time += bt[i];
    }
    printf("\n");

    printf("\nProc\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}
