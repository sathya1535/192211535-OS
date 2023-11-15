#include <stdio.h>

void main()
{
    int blockSize[10], processSize[10], blockCount, processCount, flags[10] = {0}, allocation[10] = {-1}, i, j;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &blockCount);
    printf("Enter the size of each memory block:\n");
    for (i = 0; i < blockCount; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &processCount);
    printf("Enter the size of each process:\n");
    for (i = 0; i < processCount; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    for (i = 0; i < processCount; i++)
    {
        for (j = 0; j < blockCount; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                flags[j] = 1;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < processCount; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
