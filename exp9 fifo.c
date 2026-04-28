#include<stdio.h>
#include<stdlib.h>

int main()
{
    int no_frames,no_pages,i,j,counter=0,page,flag=0,hit=0,fault=0;

    printf("Enter the number of frames: ");
    scanf("%d",&no_frames);

    int frames[no_frames];

    for(i=0;i<no_frames;i++)
        frames[i] = -1;

    printf("Enter the number of pages: ");
    scanf("%d",&no_pages);

    for(i=0;i<no_pages;i++)
    {
        printf("Enter the page: ");
        scanf("%d",&page);

        flag = 0;

        for(j=0;j<no_frames;j++)
        {
            if(page == frames[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag==0)
        {
            printf("Page Fault\n");
            frames[counter] = page;
            fault++;
            counter++;

            if(counter == no_frames)
                counter = 0;
        }
        else
        {
            printf("Page Hit\n");
            hit++;
        }

        // Graph of frames
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

    printf("\nHit: %d\n",hit);
    printf("Hit ratio: %d%%\n",(hit*100/no_pages));
    printf("\nFault: %d\n",fault);
    printf("Fault ratio: %d%%\n",(fault*100/no_pages));

    return 0;
}
