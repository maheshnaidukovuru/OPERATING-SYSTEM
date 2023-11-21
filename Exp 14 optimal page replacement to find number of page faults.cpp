#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGE_FRAMES 3
#define MAX_PAGE_REFERENCES 20

int findLRU(int pages[], int n, int time[]) {
    int lruIndex = 0, minTime = time[0];

    for (int i = 1; i < n; i++) {
        if (time[i] < minTime) {
            minTime = time[i];
            lruIndex = i;
        }
    }

    return lruIndex;
}

int pageFaults(int pageReferences[], int n, int pageFrames) {
    int pages[pageFrames];
    int time[pageFrames];
    int pageFaultsCount = 0;

    for (int i = 0; i < pageFrames; i++) {
        pages[i] = -1; // Initialize pages with -1 indicating an empty frame
        time[i] = 0;   // Initialize time for each page frame
    }

    for (int i = 0; i < n; i++) {
        bool pageExists = false;

        // Check if page is already in memory
        for (int j = 0; j < pageFrames; j++) {
            if (pages[j] == pageReferences[i]) {
                pageExists = true;
                time[j] = i; // Update the time of last reference
                break;
            }
        }

        // If page is not in memory, replace the LRU page
        if (!pageExists) {
            int lruIndex = findLRU(pages, pageFrames, time);
            pages[lruIndex] = pageReferences[i];
            time[lruIndex] = i;
            pageFaultsCount++;
        }

        // Print current state
        printf("Page Reference: %d\tPage Frames: ", pageReferences[i]);
        for (int j = 0; j < pageFrames; j++) {
            printf("%d ", pages[j]);
        }
        printf("\n");
    }

    return pageFaultsCount;
}

int main() {
    int pageFrames = 3;
    int pageReferences[MAX_PAGE_REFERENCES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    printf("Page Reference Sequence: ");
    for (int i = 0; i < MAX_PAGE_REFERENCES; i++) {
        printf("%d ", pageReferences[i]);
    }
    printf("\n");

    int faults = pageFaults(pageReferences, MAX_PAGE_REFERENCES, pageFrames);

    printf("\nTotal Page Faults: %d\n", faults);

    return 0;
}

