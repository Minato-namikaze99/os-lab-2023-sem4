#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/types.h>

int main()
{
	int x;
	char * p, ar[10];
	x=shmget(7017, 20, IPC_CREAT|0666);

	if (x!=-1)
	{
		p=(char *)shmat(x, NULL, 0);
		printf("\nEnter a sentence - ");
		scanf("%[^\n]s", ar);
		strcpy(p, ar);
	}
	return 0;
}
