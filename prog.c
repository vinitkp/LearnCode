#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main( )
{
	FILE *fname;
	//int pfds[2];
	//pipe(pfds);
/*if(fork == 0)
	{
		//close(0);
	//	dup(pfds[1]);

	}
	else
	{*/
		//	close(1);
		int a;
		fname = fopen("input.txt", "r");
		int i,bytes=0;
		char *buf;
		
		i=0;
		while(!feof(fname))
		{
		fscanf(fname,"%c",buf+i);
		printf("%c",*(buf+i));
		i++;

		}
		fclose(fname);


	//}
}
