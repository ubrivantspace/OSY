#include <stdio.h>

int main() {
    int n, time = 0, completed = 0, prev = -1;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rem[n], ct[n], tat[n], wt[n], rt[n], started[n];
    int g_id[200], g_time[200], g_idx = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d Arrival & Burst: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem[i] = bt[i];
        started[i] = 0;
    }

    while (completed < n) {
        int idx = -1, min_val = 9999;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rem[i] > 0 && rem[i] < min_val) {
                min_val = rem[i];
                idx = i;
            }
        }

        if (idx != -1) {
            if (!started[idx]) {
                rt[idx] = time - at[idx];
                started[idx] = 1;
            }
            if (idx != prev) {
                g_id[g_idx] = idx + 1;
                g_time[g_idx++] = time;
            }

            rem[idx]--;
            time++;
            prev = idx;

            if (rem[idx] == 0) { 
                completed++;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        } else {
            // Idle logic
            if (prev != -2) {
                g_id[g_idx] = -1;
                g_time[g_idx++] = time;
            }
            time++;
            prev = -2;
        }
    }
    g_time[g_idx] = time;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);

    printf("\nGantt:\n|");
    for (int i = 0; i < g_idx; i++)
        (g_id[i] == -1) ? printf(" Idle |") : printf("  P%d  |", g_id[i]);

    printf("\n");
    for (int i = 0; i <= g_idx; i++) printf("%-7d", g_time[i]);
    printf("\n");

    return 0;
}
