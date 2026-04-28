#include<stdio.h>
#include<stdlib.h>

int main()
{
    int no_frames,no_pages,i,j,page,flag=0,hit=0,fault=0;

    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d",&no_frames);

    int frames[no_frames], time[no_frames];
    int counter = 0, min, pos;

    // Initialize frames and time arrays
    for(i=0;i<no_frames;i++)
    {
        frames[i] = -1;   // -1 indicates empty frame
        time[i] = 0;      // stores last used time
    }

    // Input number of pages
    printf("Enter the number of pages: ");
    scanf("%d",&no_pages);

    // Loop through all pages
    for(i=0;i<no_pages;i++)
    {
        printf("Enter the page: ");
        scanf("%d",&page);

        flag = 0; // reset flag for each pagem

        // Check if page is already present (HIT)
        for(j=0;j<no_frames;j++)
        {
            if(page == frames[j])
            {
                flag = 1;
                hit++;              // increment hit count
                counter++;          // increment time counter
                time[j] = counter;  // update recent usage time
                break;
            }
        }

        // If page not found (FAULT)
        if(flag==0)
        {
            printf("Page Fault\n");
            fault++; // increment fault count

            int placed = 0;

            // First try to place page in empty frame
            for(j=0;j<no_frames;j++)
            {
                if(frames[j] == -1)
                {
                    frames[j] = page;   // place page
                    counter++;
                    time[j] = counter;  // set time
                    placed = 1;
                    break;
                }
            }

            // If no empty frame, replace Least Recently Used page
            if(placed == 0)
            {
                min = time[0];
                pos = 0;

                // Find frame with minimum time (LRU)
                for(j=1;j<no_frames;j++)
                {
                    if(time[j] < min)
                    {
                        min = time[j];
                        pos = j;
                    }
                }

                // Replace LRU page
                frames[pos] = page;
                counter++;
                time[pos] = counter;
            }
        }
        else
        {
            printf("Page Hit\n");
        }

        // Display frame status after each step
        printf("\nFrame Graph:\n");
        for(j=0;j<no_frames;j++)
        {
            if(frames[j] == -1)
                printf("F%d | -\n",j+1);
            else
                printf("F%d | %d\n",j+1,frames[j]);
        }
        printf("----------------\n");
    }

    // Final results
    printf("\nHit: %d\n",hit);
    printf("Hit ratio: %d%%\n",(hit*100/no_pages));
    printf("Fault: %d\n",fault);
    printf("Fault ratio: %d%%\n",(fault*100/no_pages));

    return 0;
}
