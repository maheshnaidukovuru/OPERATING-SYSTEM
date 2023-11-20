#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;            // Process ID
    int arrival_time;  // Arrival time
    int burst_time;    // CPU burst time
    int remaining_time; // Remaining CPU burst time
    int waiting_time;  // Waiting time
    int turnaround_time; // Turnaround time
};

// Function to perform SRPT scheduling
void srpt_scheduling(struct Process processes[], int n) {
    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int shortest = -1;
        int shortest_time = INT_MAX;

        // Find the process with the shortest remaining time
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_time && processes[i].remaining_time > 0) {
                shortest = i;
                shortest_time = processes[i].remaining_time;
            }
        }

        if (shortest == -1) {
            // If no process is ready to execute, move to the next arrival time
            current_time++;
        } else {
            // Execute the selected process for one unit of time
            processes[shortest].remaining_time--;
            current_time++;

            // If the process is completed
            if (processes[shortest].remaining_time == 0) {
                completed++;
                processes[shortest].turnaround_time = current_time - processes[shortest].arrival_time;
                processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
            }
        }
    }
}

// Function to calculate and print average waiting time and turnaround time
void calculate_average_times(struct Process processes[], int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    float average_waiting_time = total_waiting_time / n;
    float average_turnaround_time = total_turnaround_time / n;

    printf("Average Waiting Time: %.2f milliseconds\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f milliseconds\n", average_turnaround_time);
}

// Main function
int main() {
    int n;

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory for an array of processes
    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    // Get input for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Perform SRPT scheduling
    srpt_scheduling(processes, n);

    // Calculate and print average waiting time and turnaround time
    calculate_average_times(processes, n);

    // Free allocated memory
    free(processes);

    return 0;
}

