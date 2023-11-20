#include <stdio.h>

#define NUM_PARTITIONS 6
#define NUM_PROCESSES 5

// Function to allocate memory using First Fit algorithm
void firstFit(int partitions[], int numPartitions, int processes[], int numProcesses) {
    int allocation[numProcesses];

    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1; // Initialize allocation array to -1 (unallocated)

        for (int j = 0; j < numPartitions; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j; // Allocate the process to this partition
                partitions[j] -= processes[i]; // Update the available memory in the partition
                break;
            }
        }
    }

    // Display the memory allocation result
    printf("\nMemory Allocation:\n");
    for (int i = 0; i < numProcesses; i++) {
        if (allocation[i] != -1) {
            printf("Process %d -> Partition %d\n", i + 1, allocation[i] + 1);
        } else {
            printf("Process %d -> Not Allocated\n", i + 1);
        }
    }
}

int main() {
    // Test case data
    int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[NUM_PROCESSES] = {115, 500, 358, 200, 375};

    // Display memory partitions
    printf("Memory Partitions:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("%d KB ", partitions[i]);
    }

    // Display processes
    printf("\n\nProcesses:\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("%d KB ", processes[i]);
    }

    // Call the firstFit function
    firstFit(partitions, NUM_PARTITIONS, processes, NUM_PROCESSES);

    return 0;
}

