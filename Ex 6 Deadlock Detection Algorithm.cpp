#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources;
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int request[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];

void input() {
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < processes; i++)
        for (j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter the request matrix:\n");
    for (i = 0; i < processes; i++)
        for (j = 0; j < resources; j++)
            scanf("%d", &request[i][j]);

    printf("Enter the available resources vector:\n");
    for (j = 0; j < resources; j++)
        scanf("%d", &available[j]);
}

int isSafe(int process, int finish[], int work[]) {
    int i;
    for (i = 0; i < resources; i++)
        if (request[process][i] > work[i])
            return 0;

    return 1;
}

void detectDeadlock() {
    int finish[MAX_PROCESSES] = {0};
    int work[MAX_RESOURCES];
    int i, j, k, flag, deadlock = 0;

    for (i = 0; i < resources; i++)
        work[i] = available[i];

    for (i = 0; i < processes; i++) {
        if (finish[i] == 0 && isSafe(i, finish, work)) {
            for (j = 0; j < resources; j++)
                work[j] += allocation[i][j];

            finish[i] = 1;
            i = -1; // Reset to check all processes again
        }
    }

    for (i = 0; i < processes; i++)
        if (finish[i] == 0) {
            deadlock = 1;
            break;
        }

    if (deadlock) {
        printf("\nSystem is in a deadlock state.\n");
        printf("Deadlocked processes: ");
        for (i = 0; i < processes; i++)
            if (finish[i] == 0)
                printf("%d ", i);
        printf("\n");
    } else {
        printf("\nSystem is not in a deadlock state.\n");
    }
}

int main() {
    input();
    detectDeadlock();

    return 0;
}

