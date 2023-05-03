#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int ar[2], arr[2], x, id;
	x=pipe(ar);

	if (x==0)
	{
		id=fork();
		if (id==0)
		{
			printf("Enter a string - ");
			char buf1[100];
			scanf("%[^\n]", buf1);

			int l=strlen(buf1);
			printf("\n Child Process");
			write(ar[1], 1, 4);

			write(ar[1], buf1, l);
			//ar[1] is used to write values while ar[0] is used to read from it
		}

		else
		{
			printf("\n Parent Process");
			int l1;
			char buf[10];
			read(ar[0], l1, 4);
			read(ar[0], buf, l1);

			printf("\n The received data is - %s\n", buf);
		}
	}
	return 0;
}
