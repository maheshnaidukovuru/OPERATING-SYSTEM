#include<stdio.h>

// Function to calculate average waiting time and average turnaround time
void findWaitingTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Waiting time for the first process is 0
    wt[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];

    // Function to find waiting time and turnaround time
    findWaitingTime(processes, n, bt, wt, tat);

    // Calculate total waiting time and total turnaround time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_wt = (float) total_wt / (float) n;
    float avg_tat = (float) total_tat / (float) n;

    // Display results
    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    // Number of processes
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];

    // Input burst times for each process
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1; // Process IDs start from 1
    }

    // Call function to calculate average waiting time and average turnaround time
    findAverageTime(processes, n, burst_time);

    return 0;
}
