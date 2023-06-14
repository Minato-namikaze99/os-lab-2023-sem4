#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int a,b;
	char *ptr="/tmp/70170", buf[100];

	b=open(ptr, O_RDONLY);
	if (b!=-1)
	{
		read(b, buf, 10);
	}

	printf("The received word is - %s", buf);
	return 0;
}
