//max size of a file 
#include <stdio.h>

#define BLOCK_SIZE 8192 
#define POINTER_SIZE 4  

#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS)
#define TRIPLE_INDIRECT_BLOCKS (SINGLE_INDIRECT_BLOCKS * DOUBLE_INDIRECT_BLOCKS)

int main() {
    long long maxFileSize;
    maxFileSize = (long long)DIRECT_BLOCKS * BLOCK_SIZE +
                  (long long)SINGLE_INDIRECT_BLOCKS * BLOCK_SIZE +
                  (long long)DOUBLE_INDIRECT_BLOCKS * BLOCK_SIZE * SINGLE_INDIRECT_BLOCKS +
    printf("Maximum file size: %lld bytes\n", maxFileSize);

    return 0;
}

