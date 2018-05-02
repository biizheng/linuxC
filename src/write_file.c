#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FILENAME "./write_test"
#define SIZE 80
#define	FLAGS O_RDWR|O_CREAT
#define MODE S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH
int main(void){
	int count;
	int file_description;
	char wirte_buffer[SIZE];
	char read_buffer[SIZE];
	const char* file_name;
	
	//------------get file name
	char pn[30];
	printf("get file name!\n");
	gets(pn);

	//------------open file
	file_name = pn;
	file_description=open(file_name,FLAGS,MODE);
	if(file_name==-1){
		printf("OPEN FILE ERROR!");
		exit(1);
	}
	printf("OPEN FILE SUCCESS!\tFILE DESCRIPTION IS %d\n",file_description);
	
	//------------command 
	char command;
	printf("PLEASE INPUT COMMAND!\n");
	while(1){
		command = getchar();
		if(command=='r'){
			printf("YOU ARE IN READ MODE!\n");
			char* read_buffer[30];
			signed long buffer_size;
			buffer_size = read(file_description,read_buffer,30);
			printf("READ FILE:%s\t %ld bytes\n",file_name,buffer_size);
			printf("%s",read_buffer);
			//printf("\n");
		}else if(command=='w'){
			printf("YOU ARE IN WRITE MODE! PLEASE WRITE THE WORDS YOU WANGT:\n");
		}else if(command=='q'){
			printf("PROGRAM EXIT!");
			exit(0);		
		}	

		printf("PLEASE INPUT COMMAND!\n");

		//------------clean keyboard buffer		
		while ((command = getchar()) != '\n');
	}
			


}
