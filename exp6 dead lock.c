#include<stdio.h>

int main() {
  int p, c, count = 0, i, j, alc[5][3], max[5][3], need[5][3], safe[5], available[3], done[5], terminate = 0;

  printf("Enter number of processes: ");
  scanf("%d", &p);
  printf("Enter number of resources: ");
  scanf("%d", &c);

  printf("Enter allocation matrix (%dx%d):\n", p, c);
  for (i = 0; i < p; i++) {
    printf("Process P%d: ", i);
    for (j = 0; j < c; j++) {
      scanf("%d", &alc[i][j]);
    }
  }

  printf("Enter max matrix (%dx%d):\n", p, c);
  for (i = 0; i < p; i++) {
    printf("Process P%d: ", i);
    for (j = 0; j < c; j++) {
      scanf("%d", &max[i][j]);
    }
  }

  printf("Enter available resources: ");
  for (i = 0; i < c; i++) {
    scanf("%d", &available[i]);
  }

  printf("\nNeed matrix:\n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      need[i][j] = max[i][j] - alc[i][j];
      printf("%d\t", need[i][j]);
    }
    printf(" <- P%d\n", i);
  }

  for (i = 0; i < p; i++) {
    done[i] = 0;
  }

  while (count < p && terminate < p) {
    int found = 0;
    for (i = 0; i < p; i++) {
      if (done[i] == 0) {
        int can_execute = 1;
        for (j = 0; j < c; j++) {
          if (need[i][j] > available[j]) {
            can_execute = 0;
            break;
          }
        }
        if (can_execute) {
          safe[count] = i;
          done[i] = 1;
          for (j = 0; j < c; j++) {
            available[j] += alc[i][j];
          }
          count++;
          found = 1;
          printf("\nExecuting P%d, new available: ", i);
          for (j = 0; j < c; j++) printf("%d ", available[j]);
          break;
        }
      }
    }
    if (!found) {
      terminate++;
    }
  }

  if (count == p) {
    printf("\n✅ Safe sequence exists!\n");
    printf("Safe sequence: ");
    for (i = 0; i < p; i++) {
      printf("P%d ", safe[i]);
    }
    printf("\nFinal available resources: ");
    for (i = 0; i < c; i++) {
      printf("%d ", available[i]);
    }
    printf("\n");
  } else {
    printf("\n❌ Safe sequence does not exist (deadlock risk).\n");
  }

  return 0;
}
