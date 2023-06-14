#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>

int main()
{
	int x;
	char *p, ar[10];

	x=shmget(7017, 20, IPC_CREAT|0666);

	if (x!=-1)
	{
		p=(char *)shmat(x, NULL, 0);
		printf("\nThe received sentence is - %s", p);
	}
	return 0;
}
