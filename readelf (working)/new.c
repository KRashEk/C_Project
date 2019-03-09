#include <stdio.h>

int main()
{
    FILE *fp;
    char ptr[200];
    fp = fopen("a.out","r");
    fread(ptr,100,1,fp);
    //for(int i = 0; i < 8; i++)
    printf("%#x",(*(int*)&ptr[0x18]));
}
