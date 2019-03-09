#include "mygcc.h"
//this is hypens function
//first check filestat then fire command
//then store log in build.log by calling function buildlog
void hypens(char *str1,char*str3)
{
	char str[200];
	if(str3==NULL)
	{
		
		d=filestat(str1,"hello_world.s");		
		sprintf(str,"gcc -S -o hello_world.s %s ",str1);
		printf("wait for sometime.........\n");
		myprocess(str);
		struct stat st;
		if(stat("hello_world.s",&st)!=0)
			perror("hello");
		sprintf(bstring,"\n%.24s:hello_world.s is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);
		buildlog(bstring,a);	
		exit(0);	
	}
	//hypens function with custom output file.
	else
	{
		d=filestat(str1,str3);
		sprintf(str,"gcc -S -o %s %s",str3,str1);
		printf("wait for sometime.........\n");
		myprocess(str);
		struct stat st;
		if(stat(str3,&st)!=0)
			perror("hello");
		sprintf(bstring,"\n%.24s:%s is created.\n",ctime(&(st.st_ctime)),str3);
		a=strlen(bstring);
		buildlog(bstring,a);
		exit(0);
	}
}
//this is hypenc function
//first check filestat then fire command
//then store log in build.log by calling function buildlog
void hypenc(char *str1,char *str3)
{	if(str3==NULL)
	{
		d=filestat(str1,"hello_world.o");
		sprintf(str,"gcc -S -o hello_world.s %s",str1);
		printf("wait for sometime.........\n");
		myprocess(str);
		struct stat st;
		if(stat("hello_world.s",&st)!=0)
			perror("hello");
		sprintf(bstring,"\n%.24s:hello_world.s is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);
		buildlog(bstring,a);
		sprintf(str,"as -o hello_world.o hello_world.s");
		myprocess(str);
		if(stat("hello_world.o",&st)!=0)
			perror("hello");
		sprintf(bstring,"%.24s:hello_world.o is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);
		buildlog(bstring,a);
		s=unlink("hello_world.s");
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		strftime(bstring,sizeof(bstring),"%c",tm);		
		strcat(bstring,":hello_world.s is deleted.\n");
		a=strlen(bstring);
		buildlog(bstring,a);
		exit(0);
	}
	//hypenc function with custom output file
	else
	{
		d=filestat(str1,str3);
		char tempstr[100];
		sprintf(str,"gcc -S -o hello_world.s %s",str1);
		printf("wait for sometime.........\n");
		
		myprocess(str);
		struct stat st;
		if(stat("hello_world.s",&st)!=0)
			perror("hello");
		sprintf(bstring,"\n%.24s:hello_world.s is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);
		buildlog(bstring,a);
		sprintf(str,"as -o %s hello_world.s",str3);
		myprocess(str);
		if(stat(str3,&st)!=0)
			perror("hello");
		sprintf(bstring,"%.24s:%s is created.\n",ctime(&(st.st_ctime)),str3);
		a=strlen(bstring);
		buildlog(bstring,a);
		s=unlink("hello_world.s");
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		strftime(bstring,sizeof(bstring),"%c",tm);		
		strcat(bstring,":hello_world.s is deleted.\n");
		a=strlen(bstring);
		buildlog(bstring,a);
		exit(0);		
	}
		
	
}
//this is nooption function
//first check filestat then fire command
//then store log in build.log by calling function buildlog
void nooption(char *str3,char *str4)
{
	if(str4==NULL)
	{
		d=filestat(str3,"a.out");
		sprintf(str,"gcc -S -o hello_world.s %s",str3);
		printf("wait for sometime.........\n");
		myprocess(str);
		struct stat st;
		if(stat("hello_world.s",&st)!=0)	
			perror("hello_world.s is not found");
		sprintf(bstring,"\n%.24s:hello_world.s is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);
		buildlog(bstring,a);
		sprintf(str,"as -o hello_world.o hello_world.s");
		myprocess(str);
		if(stat("hello_world.o",&st)!=0)
			perror("hello");
		sprintf(bstring,"%.24s:hello_world.o is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);
		buildlog(bstring,a);
		sprintf(str,"ld -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 hello_world.o -e main");
		myprocess(str);
		if(stat("a.out",&st)!=0)
			perror("hello");
		sprintf(bstring,"%.24s:a.out is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);
		buildlog(bstring,a);
		s=unlink("hello_world.s");
		s=unlink("hello_world.o");
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		strftime(bstring,sizeof(bstring),"%c",tm);		
		strcat(bstring,":hello_world.s is deleted.\n");
		a=strlen(bstring);
		buildlog(bstring,a);
		strftime(bstring,sizeof(bstring),"%c",tm);		
		strcat(bstring,":hello_world.o is deleted.\n");
		a=strlen(bstring);
		buildlog(bstring,a);
		exit(0);
	}
	//nooption with custom output file.
	else
	{
		d=filestat(str3,str4);
		sprintf(str,"gcc -S -o hello_world.s %s",str3);
		printf("wait for sometime.........\n");
		myprocess(str);
		struct stat st;
		if(stat("hello_world.s",&st)!=0)
			perror("hello");
		sprintf(bstring,"\n%.24s:hello_world.s is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);
		buildlog(bstring,a);
		sprintf(str,"as -o hello_world.o hello_world.s");
		myprocess(str);
		if(stat("hello_world.o",&st)!=0)
			perror("hello");
		sprintf(bstring,"%.24s:hello_world.o is created.\n",ctime(&(st.st_ctime)));
		a=strlen(bstring);		
		buildlog(bstring,a);
		sprintf(str,"ld -o %s  -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 hello_world.o -e main",str4);
		myprocess(str);
		if(stat(str4,&st)!=0)
			perror("hello");
		sprintf(bstring,"%.24s:%s is created.\n",ctime(&(st.st_ctime)),str4);
		a=strlen(bstring);
		buildlog(bstring,a);
		s=unlink("hello_world.s");
		s=unlink("hello_world.o");
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		strftime(bstring,sizeof(bstring),"%c",tm);		
		strcat(bstring,":hello_world.s is deleted.\n");
		a=strlen(bstring);
		buildlog(bstring,a);
		strftime(bstring,sizeof(bstring),"%c",tm);		
		strcat(bstring,":hello_world.o is deleted.\n");
		a=strlen(bstring);		
		buildlog(bstring,a);
		exit(0);
	}
		
}
//process creation for command fire.
void myprocess(char*string)
{	
	pid_t childpid;
	switch (childpid=fork()){
	
	case -1:
		error("process is not created\n");
		exit(0);
	case 0:
		execl("/bin/sh","sh","-c",string,(char*)NULL);
	default:
		sleep(3);
		break;	
	}
}
//for creation build.log
// file permission is 777 becas if you want to file open for checking log is genrated or not there fore 777 permission is needed
void buildlog(char*bbs,int c)
{
	
	if((fd=open("build.log",O_WRONLY))==-1)
//	{
//		int f;
		fd=creat("build.log",0777);
//		f=chmod("build.log",S_IRWXU|S_IRWXG|S_IRWXO);
//	}		
	lseek(fd,0L,2);
	i=write(fd,bbs,c);
	close(fd);
}
//for checkion file allready compile or not 
//if file is already compile then exit from the programm or return to function
//if file is modified then target file is delete and create new
//and genrate the log
int filestat(char* str,char*str2)
{
	char tempstr[20];
	if((fd=open(str2,O_RDONLY))==-1)
		return 0;
	struct stat st,st2;
	stat(str,&st);
	stat(str2,&st2);
	time_t t1=st.st_mtime;
	time_t t2=st2.st_ctime;
	if(t2>t1)
	{
		printf("%s file is already updated\n",str2);
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		strftime(bstring,sizeof(bstring),"%c",tm);		
		sprintf(tempstr,":%s is upto date.\n",str2);
		strcat(bstring,tempstr);		
		a=strlen(bstring);
		buildlog(bstring,a);
		close(fd);
		exit(0);
	}
	else 
	{
		printf("%s file is deleted\n",str2);
		unlink(str2);
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		strftime(bstring,sizeof(bstring),"%c",tm);		
		sprintf(tempstr,":%s is deleted.\n",str2);
		strcat(bstring,tempstr);
		a=strlen(bstring);
		buildlog(bstring,a);
		close(fd);
		return 0;
	}	
}	
