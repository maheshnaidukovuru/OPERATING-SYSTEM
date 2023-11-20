#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, head, i, j, seek_time = 0, distance;
    int tracks[MAX];

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the track positions:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    printf("Enter the head position: ");
    scanf("%d", &head);

    printf("The sequence of tracks is:\n");
    printf("%d -> ", head);

    for (i = 0; i < n; i++) {
        distance = abs(tracks[i] - head);
        seek_time += distance;
        head = tracks[i];
        printf("%d -> ", head);
    }

    printf("\nTotal head movement: %d\n", seek_time);
    printf("Average head movement: %0.2f\n", (float) seek_time / n);

    return 0;
}
