#include<stdio.h>
#include<stdlib.h>

// Process structure to store process information
struct Process {
    int processID;  // Process ID
    int burstTime;  // Burst time
};

// Function to perform SJF scheduling
void sjfScheduling(struct Process processes[], int n) {
    int waitingTime[n], turnaroundTime[n];
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Sort processes based on burst time (shortest job first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    waitingTime[0] = 0;
    turnaroundTime[0] = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input burst time for each process
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    // Perform SJF Scheduling
    sjfScheduling(processes, n);

    return 0;
}
