#include <stdio.h>
int main()
{
     int m, p, i, j;
     int mem[20], process[20];
     int allocation[20];
     for (i = 0; i < 20; i++)
        allocation[i] = -1;
     printf("Enter number of memory partitions: ");
     scanf("%d", &m);
     printf("Enter size of each partition:\n");
     for (i = 0; i < m; i++)
         scanf("%d", &mem[i]);
         printf("Enter number of processes: ");
         scanf("%d", &p);
         printf("Enter size of each process:\n");
     for (i = 0; i < p; i++)
         scanf("%d", &process[i]);
     for (i = 0; i < p; i++)
    {
         for (j = 0; j < m; j++)
            {
                if (mem[j] >= process[i])
                {
                    allocation[i] = j;
                    mem[j] -= process[i];
                    break;
                }
            }
         printf("\nProcess No\tProcess Size\tPartition No\tInternal Fragmentation\n");
         for (i = 0; i < p; i++)
         {
             if (allocation[i] != -1)
                printf("%d\t\t%d\t\t%d\t\t%d\n",i + 1, process[i], allocation[i] + 1, mem[allocation[i]]);
             else
                printf("%d\t\t%d\t\tNot Allocated\t-\n", i + 1, process[i]);
         }
         return 0;
    }
}
