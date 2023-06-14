#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
	int a,b;

	char *ptr="/tmp/70170", buf[100];
	printf("Enter a word that you want to send - ");
	scanf("%s", buf);

	a=mkfifo(ptr, 0666);

	if (a==0)
	{
		//a==0 means that the pipe was created succesfully
		b=open(ptr, O_WRONLY);

		if (b!=-1)
		{
			//b!=-1 means that there is no error in opening the pipe
			write(b, buf, strlen(buf)+1);
		}
		else 
			printf("\nError Occurred\n");
	}
	else 
		printf("\nError Occurred\n");
	return 0;
}
