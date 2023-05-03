#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int a,b;
	char * ptr="/tmp/7017", buf[100];
	printf("Enter a word that you want to send - ");
	scanf("%s", buf);

	a=mkfifo(ptr, 0666);

	if (a==0)
	{
		b=open(ptr, O_WRONLY);

		if (b!=-1)
		{
			write(b, buf, strlen(buf)+1);
		}

		else
			printf("\nError Occurred!\n");

		int g=unlink(ptr);

		if (g==0)
			printf("LMAO");
		else
			printf("LOL");
	}
	else
		printf("\nError Occurred!\n");

	return 0;

}
