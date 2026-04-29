#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

int find_farthest_page(int pages[], int current_index, int frames[], int num_frames, int num_pages) {
    int farthest_index = -1;
    int farthest_time = current_index;

    for (int i = 0; i < num_frames; i++) {
        int j;
        for (j = current_index; j < num_pages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest_time) {
                    farthest_time = j;
                    farthest_index = i;
                }
                break;
            }
        }
   
        if (j == num_pages) {
            return i;
        }
    }


    return (farthest_index == -1) ? 0 : farthest_index;
}

int main() {
    int pages[MAX_PAGES];
    int frames[MAX_FRAMES];
    int num_pages, num_frames;
    int page_faults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &num_pages);

    printf("Enter the page reference string:\n");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }


    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    printf("\nPage Reference String | Frames | Page Faults\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < num_pages; i++) {
        int current_page = pages[i];
        bool is_hit = false;

        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == current_page) {
                is_hit = true;
                break;
            }
        }

        if (!is_hit) {
            int replace_index = -1;
            for (int j = 0; j < num_frames; j++) {
                if (frames[j] == -1) {
                    replace_index = j;
                    break;
                }
            }

            if (replace_index == -1) {
                replace_index = find_farthest_page(pages, i + 1, frames, num_frames, num_pages);
            }

            frames[replace_index] = current_page;
            page_faults++;
        }

        printf("%d\t\t    | ", current_page);
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("   | %s\n", is_hit ? "Hit" : "Fault");
    }

    printf("---------------------------------------------\n");
    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
