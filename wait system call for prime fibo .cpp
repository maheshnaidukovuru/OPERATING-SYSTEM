//wait system call
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int isPrime(int num) 
{
    if (num <= 1) 
	{
        return 0;  
    }
    for (int i = 2; i * i <= num; ++i) 
	{
        if (num % i == 0)
		 {
            return 0;  
        }
    }
    return 1;
}
void generateFibonacci(int n) 
{
    int first = 0, second = 1, next;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; ++i)
	 {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() 
{
    int n;
    printf("Enter the value of n for Fibonacci series: ");
    scanf("%d", &n);
    pid_t childPid = fork();
    if (childPid == -1) 
	{
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }

    if (childPid == 0) 
	{
        generateFibonacci(n);
    }
	 else 
	{
        wait(NULL); 
        printf("Prime Numbers: ");
        for (int i = 2; i <= n; ++i) 
		{
            if (isPrime(i)) 
			{
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}

