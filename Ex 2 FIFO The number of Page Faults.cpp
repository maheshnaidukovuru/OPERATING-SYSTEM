#include <stdio.h>

#define MAX_FRAMES 10

int main() {
    int pageFrames[MAX_FRAMES];
    int pageReferenceSequence[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int numFrames = 3;
    int numReferences = sizeof(pageReferenceSequence) / sizeof(pageReferenceSequence[0]);

    int pageFaults = 0;
    int frameIndex = 0;
    int i, j;

    // Initialize page frames to -1, indicating that they are empty
    for (i = 0; i < numFrames; i++) {
        pageFrames[i] = -1;
    }

    printf("Page Reference Sequence: ");
    for (i = 0; i < numReferences; i++) {
        printf("%d ", pageReferenceSequence[i]);
    }
    printf("\n");

    printf("Number of Page Frames: %d\n", numFrames);

    // Simulate page replacement using FIFO
    for (i = 0; i < numReferences; i++) {
        int currentPage = pageReferenceSequence[i];
        int pageFound = 0;

        // Check if the current page is already in a frame
        for (j = 0; j < numFrames; j++) {
            if (pageFrames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            // Page fault, replace the oldest page in the frame
            pageFaults++;
            pageFrames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % numFrames;
        }

        // Print the current state of page frames
        printf("Page Frames: ");
        for (j = 0; j < numFrames; j++) {
            printf("%d ", pageFrames[j]);
        }
        printf("\n");
    }

    printf("Number of Page Faults: %d\n", pageFaults);

    return 0;
}

