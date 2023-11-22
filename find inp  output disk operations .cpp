//to find how many disk needed for operations
#include <stdio.h>
#define TOTAL_BLOCKS 100
int contiguousAllocation(int position) 
{
    return 1;
}
int linkedAllocation(int position) 
{
    return position + 1;
}
int indexedAllocation(int position) 
{
    return 2; 
}
int main() {
    int position;
    printf("Adding block at the beginning:\n");
    position = 0;
    printf("Contiguous Allocation: %d disk I/O operations\n", contiguousAllocation(position));
    printf("Linked Allocation: %d disk I/O operations\n", linkedAllocation(position));
    printf("Indexed Allocation: %d disk I/O operations\n\n", indexedAllocation(position));
    printf("Adding block in the middle:\n");
    position = TOTAL_BLOCKS / 2;
    printf("Contiguous Allocation: %d disk I/O operations\n", contiguousAllocation(position));
    printf("Linked Allocation: %d disk I/O operations\n", linkedAllocation(position));
    printf("Indexed Allocation: %d disk I/O operations\n\n", indexedAllocation(position));
    printf("Adding block at the end:\n");
    position = TOTAL_BLOCKS - 1;
    printf("Contiguous Allocation: %d disk I/O operations\n", contiguousAllocation(position));
    printf("Linked Allocation: %d disk I/O operations\n", linkedAllocation(position));
    printf("Indexed Allocation: %d disk I/O operations\n", indexedAllocation(position));
    return 0;
}

