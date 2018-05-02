#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define FLAGS O_WRONLY|O_CREAT|O_TRUNC
#define MODE S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH




int main(void){
	const char* pathname;
	int fd;
	char pn[30];
	printf("Input the pathname:[<30 strings]");
	gets(pn);
	printf("OPENING FILE %s\n",pn);
	pathname=pn;
	if((fd=open(pathname,FLAGS,MODE))==-1)
	{
		printf("ERROR,OPEN FILE FAILED!\n");
		exit(1);
	}
	printf("FILE OPEN!\n");
	printf("FD=%d\n",fd);
	return 0;
}
