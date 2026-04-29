#include<stdio.h>
#include<stdlib.h>

int main()
{
    int no_frames,no_pages,i,j,page,flag=0,hit=0,fault=0;

    printf("Enter the number of frames: ");
    scanf("%d",&no_frames);

    int frames[no_frames], time[no_frames];
    int counter = 0, min, pos;

    for(i=0;i<no_frames;i++)
    {
        frames[i] = -1;   
        time[i] = 0;      
    }

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
                hit++;              
                counter++;          
                time[j] = counter;  
                break;
            }
        }


        if(flag==0)
        {
            printf("Page Fault\n");
            fault++; 

            int placed = 0;

            for(j=0;j<no_frames;j++)
            {
                if(frames[j] == -1)
                {
                    frames[j] = page; 
                    counter++;
                    time[j] = counter; 
                    placed = 1;
                    break;
                }
            }

            if(placed == 0)
            {
                min = time[0];
                pos = 0;

                for(j=1;j<no_frames;j++)
                {
                    if(time[j] < min)
                    {
                        min = time[j];
                        pos = j;
                    }
                }

                frames[pos] = page;
                counter++;
                time[pos] = counter;
            }
        }
        else
        {
            printf("Page Hit\n");
        }

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
    printf("Fault: %d\n",fault);
    printf("Fault ratio: %d%%\n",(fault*100/no_pages));

    return 0;
}
