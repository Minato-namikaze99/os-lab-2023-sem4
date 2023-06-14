#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t first;
pthread_mutex_t second;

void *todo1()
{
	pthread_mutex_lock(&first);
	printf("\nFirst Mutex Locked in Thread 1\n");
	sleep(1);
	pthread_mutex_lock(&second);
	printf("\nSecond Mutex Locked in Thread 1\n");
}

void *todo2()
{
	pthread_mutex_lock(&second);
	printf("\nSecond Mutex Locked in Thread 2\n");
	sleep(1);
	pthread_mutex_lock(&first);
	printf("\nFirst Mutex Locked in Thread 2\n");
}

int main()
{
	pthread_mutex_init(&first, NULL);
	pthread_mutex_init(&second, NULL);
	pthread_t one, two;

	pthread_create(&one, NULL, todo1, NULL);
	pthread_create(&two, NULL, todo2, NULL);
	pthread_join(one, NULL);
	pthread_join(two, NULL);
	return 0;
}
