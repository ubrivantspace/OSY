#include <stdio.h>

void displayFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

int findLRU(int time[], int n) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10];
    int faults = 0, flag1, flag2, pos;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter reference string: ");
    for (int i = 0; i < no_of_pages; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < no_of_frames; i++) {
        frames[i] = -1;
    }

    printf("\nRef String | Memory State\n");
    printf("-----------|-------------\n");

    for (int i = 0; i < no_of_pages; i++) {
        flag1 = flag2 = 0;

        for (int j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (int j = 0; j < no_of_frames; j++) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        printf("    %d      | ", pages[i]);
        displayFrames(frames, no_of_frames);
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
