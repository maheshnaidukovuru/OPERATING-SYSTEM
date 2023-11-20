#include <stdio.h>

int main() {
    int n = 19; 
    int frames[3] = { -1, -1, -1 }; 
    int pageReferences[] = { 1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3 };
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pageReferences[i];
        int hit = 0;

     
        for (int j = 0; j < 3; j++) {
            if (frames[j] == page) {
                hit = 1;
                break;
            }
        }

        
        if (!hit) {
            int lruIndex = 0;
            for (int j = 1; j < 3; j++) {
                if (frames[j] < frames[lruIndex]) {
                    lruIndex = j;
                }
            }
            frames[lruIndex] = page;
            pageFaults++;
        }

       
        printf("%d %d %d\n", frames[0], frames[1], frames[2]);
    }

    printf("Total page faults: %d\n", pageFaults);

    return 0;
}
