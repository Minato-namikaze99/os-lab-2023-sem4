#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
	int ar[2],x, id;
	x=pipe(ar);

	if (x==0)
	{
		id =fork();
		if (id==0)
		{
			printf("\nCHILD PROCESS\n");
			printf("Enter a string - ");
			char buf[100];
			scanf("%[^\n]", buf);
			write(ar[1], buf, 20);
		}

		else 
		{
			wait(NULL);
			printf("\nPARENT PROCESS\n");
			char buf[100];
			read(ar[0], buf, 20);
			printf("The received string is - %s\n", buf);
		}
	}

	return 0;
}
