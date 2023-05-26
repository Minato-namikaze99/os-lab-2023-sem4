#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *todo1()
{
	printf("\n TODO 1\n");
}

void *todo2()
{
	printf("\n TODO 2\n");
}

int main()
{
	int x;
	pthread_t t[2];
	
	x=pthread_create(&t[0], NULL, &todo1, NULL);
	x=pthread_create(&t[1], NULL, &todo2, NULL);
	sleep(1);
	//compile by adding "-lpthread" at the end
	return 0;
}
