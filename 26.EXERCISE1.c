#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

void sort_by_priority(struct process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                struct process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process *processes = malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and priority of process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        sort_by_priority(processes, n);
        int i = 0;
        while (i < n && processes[i].burst_time == 0) {
            i++;
        }
        if (i == n) {
            break;
        }
        int pid = processes[i].pid;
        processes[i].remaining_time--;
        processes[i].burst_time--;
        if (processes[i].burst_time == 0) {
            completed_processes++;
            processes[i].turnaround_time = current_time + 1;
            processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        }
        current_time++;
    }

    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }

    free(processes);
    return 0;
}
