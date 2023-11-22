//sequential file allocation
#include <stdio.h>
#include <stdlib.h>
#define TOTAL_BLOCKS 16
#define BLOCK_SIZE 1024
#define INODE_BLOCKS 8
#define MIN_FILE_SIZE 1024
int areBlocksFree(int startBlock, int numBlocks, int *allocationMap) 
{
    for (int i = startBlock; i < startBlock + numBlocks; ++i) 
	{
        if (allocationMap[i] == 1) 
		{
            return 0; 
        }
    }
    return 1;
}
void allocateBlocks(int startBlock, int numBlocks, int *allocationMap) 
{
    for (int i = startBlock; i < startBlock + numBlocks; ++i)
	 {
        allocationMap[i] = 1; 
    }
}
int main()
 {
    int allocationMap[TOTAL_BLOCKS] = {0};
    int fileSize;
    printf("Enter the file size (minimum 1 KB): ");
    scanf("%d", &fileSize);
    if (fileSize < MIN_FILE_SIZE) 
	{
        printf("Error: File size should be at least 1 KB.\n");
        exit(EXIT_FAILURE);
    }
    int numBlocksRequired = (fileSize + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int startBlock = -1;
    for (int i = INODE_BLOCKS; i < TOTAL_BLOCKS - numBlocksRequired + 1; ++i) 
	{
        if (areBlocksFree(i, numBlocksRequired, allocationMap)) 
		{
            startBlock = i;
            allocateBlocks(startBlock, numBlocksRequired, allocationMap);
            break;
        }
    }
    if (startBlock == -1)
	 {
        printf("Error: Not enough contiguous free blocks available.\n");
        exit(EXIT_FAILURE);
    }
    printf("File allocated to blocks: ");
    for (int i = startBlock; i < startBlock + numBlocksRequired; ++i) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

