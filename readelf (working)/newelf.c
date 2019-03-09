#include "myheader.h"
int main(int argc, char** argv, char ** envp)
{
	int fd, i, n;
	char *ptr;
	struct stat st;
	if(argc != 2)
	{
		printf("%s usage please enter at least one file name only\n",argv[0]);
		exit(0);
	}
	else
	{
		stat(argv[1],&st);
		i = st.st_size;
		char buffer[i];
//		printf("%d %ld",i, sizeof(buffer));
		fd = open(argv[1],O_RDONLY);
		n = read(fd,buffer,sizeof(buffer));
		ptr=buffer;
		if(0x1 == buffer[0x04])
			elf32(buffer);
		else if (0x2 == buffer[0x04])
			elf64(buffer);	
		
	}
	
		
}
