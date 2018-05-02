#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
	int temp = 0;
	temp = open("./examtest",O_RDWR|O_CREAT,S_IRWXU);
	printf("The file description code is: %d\n",temp);
	printf("The number of args is %d\n",temp);
	printf("Current user is %s",getenv("USER"));
}
