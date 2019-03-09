#include "mygcc.h"
char * p=NULL;
//This is main function which is accept the options.
int main(int argc,char *argv[])
{
	char str[100],str2[100],mmtime[50],cctime[50];
	int a,i,n,b;
	a=argc;
	struct stat sb;
	char chs,chc,cho;
	if(a==2)
	{
		nooption(argv[1],NULL);
	}
	else
	{
		for(i=1;i<a;i++)
		{
				n=strlen(argv[i]);
				if(n==2)
				{
					p = argv[i];
					if(*p == '-' && *(p+1)=='S')
					{
						chs=*(p+1);
					}
					else if(*p == '-' && *(p+1)=='c')
					{
						chc=*(p+1);
					}
					else if(*p == '-' && *(p+1)=='o')	
					{
						cho=*(p+1);
						strcpy(str2,argv[i+1]);
						b=i+1;
					}
				}
				else if(i!=b)
				{
					strcpy(str,argv[i]);
				}
		}
	}
	//if option is -S then hypens function or -c hypenc function or without option for nooption function.
	 if(chs=='S')
	{
		if(cho!='o')
		hypens(str,NULL);
		else
		hypens(str,str2);
		return 0;
	}		
	else if(chc=='c')
	{
		if(cho!='o')
		hypenc(str,NULL);
		else
		hypenc(str,str2);
		return 0;
	}
	else 
	{
		nooption(str,str2);
	}

}
