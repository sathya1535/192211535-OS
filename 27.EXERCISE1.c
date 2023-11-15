#include <stdio.h>

void main()
{
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j, p[20];
    float temp;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d", &n);
    printf("\nEnter Process Burst Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        avwt += wt[i];
    }
    avwt /= n;
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avtat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }
    avtat /= n;
    printf("\n\nAverage Waiting Time:%d", avwt);
    printf("\nAverage Turnaround Time:%d", avtat);
}
