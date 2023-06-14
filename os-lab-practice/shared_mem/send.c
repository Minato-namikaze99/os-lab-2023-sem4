#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>

int main()
{
	int x;
	char *p, ar[10];
	x=shmget(7017, 20, IPC_CREAT|0666);
	
	if (x!=-1)
	{
		p=(char *)shmat(x,NULL,0);
		printf("\nEnter a sentence - ");
		scanf("%[^\n]", ar);
		strcpy(p, ar);
	}

	return 0;
}
