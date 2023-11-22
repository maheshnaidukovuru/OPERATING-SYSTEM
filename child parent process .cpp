//child parent process
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
void printNumbers(int start, int end, int step, const char* processName) 
{
    for (int i = start; i <= end; i += step) 
	{
        printf("%s (%d): %d\n", processName, getpid(), i);
    }
}

int main() {
    pid_t pid1, pid2, pid3, pid4;
    if ((pid1 = fork()) == 0) 
	{
        printNumbers(1, 20, 2, "Odd");
        _exit(0);
    }
    if ((pid2 = fork()) == 0) 
	{
        printNumbers(2, 20, 2, "Even");
        _exit(0);
    }
    if ((pid3 = fork()) == 0)
	 {
        printNumbers(3, 30, 3, "Multiples of 3");
        _exit(0);
    }
    if ((pid4 = fork()) == 0) 
	{
        printNumbers(5, 50, 5, "Multiples of 5");
        _exit(0);
    }
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
    waitpid(pid4, NULL, 0);
    return 0;
}

