#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t lock;
int a=10;

void *todo1()
{
	pthread_mutex_lock(&lock);
	printf("\n TODO 1\n");
	a=a+5;
	printf("The value of A in thread 1 is = %d\n", a);
}

void *todo2()
{
	printf("\n TODO 2\n");
	a=a*10;
	pthread_mutex_unlock(&lock);
	printf("The value of A in thread 2 is = %d\n", a);
}

int main()
{
	int x;
	pthread_mutex_init(&lock, NULL);//it acts as a semaphor
	pthread_mutex_lock(&lock);
	pthread_t t[2];

	x=pthread_create(&t[0], NULL, &todo1, 0);
	x=pthread_create(&t[1], NULL, &todo2, 0);
	sleep(1);

	return 0;
}
