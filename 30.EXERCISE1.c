#include <stdio.h>

void main()
{
    int blockSize[20], processSize[20], allocation[20], i, j, n, m;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the size of each memory block:\n");
    for (i = 0; i < m; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the size of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    for (i = 0; i < n; i++)
    {
        int worstBlock = -1;
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstBlock == -1)
                    worstBlock = j;
                else if (blockSize[worstBlock] < blockSize[j])
                    worstBlock = j;
            }
        }
        if (worstBlock != -1)
        {
            allocation[i] = worstBlock;
            blockSize[worstBlock] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
