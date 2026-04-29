#include <stdio.h>

int main() {
    int n, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int id[n], at[n], bt[n], priority[n], rt[n], wt[n], tat[n], ct[n], remaining_bt[n], done[n], first_start[n];
    int g_id[200], g_time[201], g_idx = 0;

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("P%d Arrival, Burst & Priority: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        remaining_bt[i] = bt[i];
        done[i] = 0;
        first_start[i] = -1;
    }

    g_time[0] = 0;
    int last_idx = -2;

    while (completed < n) {
        int idx = -1;
        int max_priority = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i] && priority[i] < max_priority) {
                max_priority = priority[i];
                idx = i;
            }
        }

        if (idx != -1) {
            if (first_start[idx] == -1) {
                first_start[idx] = time;
                rt[idx] = first_start[idx] - at[idx];
            }

            if (idx != last_idx) {
                g_id[g_idx] = id[idx];
                g_time[g_idx] = time;
                g_idx++;
            }

            remaining_bt[idx]--;
            time++;
            last_idx = idx;

            if (remaining_bt[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                done[idx] = 1;
                completed++;
            }
        } else {
            if (last_idx != -1) {
                g_id[g_idx] = -1;
                g_time[g_idx] = time;
                g_idx++;
            }
            time++;
            last_idx = -1;
        }
    }
    g_time[g_idx] = time;

    printf("\nPID\tPRI\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", id[i], priority[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g_idx; i++)
        (g_id[i] == -1) ? printf(" Idle |") : printf("  P%d  |", g_id[i]);

    printf("\n");
    for (int i = 0; i <= g_idx; i++) printf("%-7d", g_time[i]);
    printf("\n");

    return 0;
}
