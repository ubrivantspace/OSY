#include <stdio.h>

int main() {
    int n, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int id[n], at[n], bt[n], ct[n], tat[n], wt[n], rt[n], done[n];
    int g_id[100], g_time[101], g_idx = 0;

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("P%d Arrival & Burst: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = 0;
    }

    g_time[0] = 0;
    while (completed < n) {
        int idx = -1, min_bt = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx != -1) {
            rt[idx] = time - at[idx];

            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done[idx] = 1;
            completed++;

            g_id[g_idx] = id[idx];
            g_time[++g_idx] = time;
        } else {
            if (g_idx > 0 && g_id[g_idx-1] == -1) {
                time++;
                g_time[g_idx] = time;
            } else {
                g_id[g_idx] = -1;
                time++;
                g_time[++g_idx] = time;
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", id[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g_idx; i++) {
        if (g_id[i] == -1) printf(" Idle |");
        else printf("  P%d  |", g_id[i]);
    }
    printf("\n%d", g_time[0]);
    for (int i = 1; i <= g_idx; i++) printf("      %d", g_time[i]);
    printf("\n");

    return 0;
}
