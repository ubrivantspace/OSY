#include <stdio.h>

int main() {
    int n, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Added priority array
    int id[n], at[n], bt[n], priority[n], ct[n], tat[n], wt[n], rt[n], done[n];
    int g_id[100], g_time[101], g_idx = 0;

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        // Added input for priority
        printf("P%d Arrival, Burst & Priority (lower = higher priority): ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        done[i] = 0;
    }

    g_time[0] = 0;
    while (completed < n) {
        int idx = -1;
        int max_priority = 9999; // Using 9999 as a placeholder for "lowest" priority

        for (int i = 0; i < n; i++) {
            // Check if process has arrived and has higher priority than current selection
            if (at[i] <= time && !done[i]) {
                if (priority[i] < max_priority) {
                    max_priority = priority[i];
                    idx = i;
                }
                // Optional: Tie-breaker using Arrival Time if priorities are equal
                else if (priority[i] == max_priority) {
                    if (at[i] < at[idx]) {
                        idx = i;
                    }
                }
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

    // Updated Table Header to include Priority
    printf("\nPID\tPRI\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", id[i], priority[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);

    // Gantt Chart
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
