#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main( )
{
	FILE *fname;
	char *argv[3141];
	 char **en;
	//int pfds[2];
	//pipe(pfds);
	int pid ;
	if((pid =fork()) == 0)
	{
		if(execve("./sq <input.txt >out.txt",argv,en)<0)
		{
			printf("system error\n");
		}
	

	}
/*	else
	{
		//	close(1);
		int a;
		fname = fopen("input.txt", "r");
		int i,bytes=0;
		char buf[255];
		char *c=buf;
		
		i=0;
		while(!feof(fname))
		{
		fscanf(fname,"%c",c);
		printf("%c",*c);
		c = c + 1;

		}
		fclose(fname);


	//}*/
}
