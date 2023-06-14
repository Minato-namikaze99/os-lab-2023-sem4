#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int p,q,a;

	p=fork();
	if (p==0)
	{
		//p==0 means it is a child process
		q=getpid();
		a=getppid();

		printf("The process ID of this child process is - %d\n", q);
		printf("The parents' process ID is - %d\n", a);
	}
	else 
	{
		//this is the parent process
		wait(NULL);
		//this wait puts the parent process on hold, till the child process is executed
		q=getpid();
		printf("\nThe process ID of this parent process is - %d\n", q);
	}
	return 0;
}
