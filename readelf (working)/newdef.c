#include "myheader.h"
void elf32(char * buffer)
{
	//code
	Elf32_Ehdr *pelf32, elf;
	pelf32 = &elf;
	int i,j;
	printf("\nELF Header:\n");
	printf(" Magic:  ");
	for(i = 0; i < EI_NIDENT; i++)
	{
		(*pelf32).e_ident[i] = buffer[i];
		printf(" %02x",(*pelf32).e_ident[i]);
	}
	printf("\n"); 
	if((*pelf32).e_ident[EI_CLASS]==0x1)
		printf(" Class:\t\t\t\t    ELF32\n");
	else if((*pelf32).e_ident[EI_CLASS]==0x2)
		printf(" Class:\t\t\t\t    ELF64\n");
	if((*pelf32).e_ident[EI_DATA]==0x1)
		printf(" Data:\t\t\t\t    2's complement, little endian\n");
	else if((*pelf32).e_ident[EI_DATA]==0x2)
		printf(" Data:\t\t\t\t    2's complement, big endian\n");
	printf(" Version:\t\t\t    %x (current)\n",(*pelf32).e_ident[EI_VERSION]);
	j=(*pelf32).e_ident[EI_OSABI];
	machinarch(j,'a');
	printf(" ABI Version:\t\t\t    %x\n",(*pelf32).e_ident[EI_ABIVERSION]);
	(*pelf32).e_type=*(uint16_t*)(&buffer[0x10]);
	type((*pelf32).e_type);
	(*pelf32).e_machine=*(uint16_t*)(&buffer[0x12]);
	machinarch('a',(*pelf32).e_machine);	
	(*pelf32).e_version = *(uint32_t*)(&buffer[0x14]);
	printf(" Version:\t\t\t    %#x\n",(*pelf32).e_version);
	(*pelf32).e_entry = *(uint32_t*)(&buffer[0x18]);
	printf(" Entry point address:\t\t    %#x\n",(unsigned int)(*pelf32).e_entry);	
	(*pelf32).e_phoff=*(uint32_t*)(&buffer[0x1C]);
	printf(" Start of program headers:\t    %u (bytes into file)\n",(unsigned int)(*pelf32).e_phoff);
	(*pelf32).e_shoff=*(uint32_t*)(&buffer[0x20]);
	printf(" Start of section headers:\t    %u (bytes into file)\n",(unsigned int)(*pelf32).e_shoff);
	(*pelf32).e_flags=*(uint32_t*)(&buffer[0x24]);
	printf(" Flags:\t\t\t\t    0x%#x\n",(*pelf32).e_flags);
	(*pelf32).e_ehsize=*(uint16_t*)(&(buffer[0x28]));
	printf(" Size of this header:\t\t    %d (bytes)\n",(*pelf32).e_ehsize);
	(*pelf32).e_phentsize = *(uint16_t*)(&buffer[0x2A]);
	printf(" Size of program headers:\t    %d (byts)\n",(*pelf32).e_phentsize);
	(*pelf32).e_phnum = *(uint16_t*)(&buffer[0x2C]);
	printf(" Number of program headers:\t    %d\n",(*pelf32).e_phnum);
	(*pelf32).e_shentsize = *(uint16_t*)(&buffer[0x2E]);
	printf(" Size of section headers:\t    %d (bytes)\n",(*pelf32).e_shentsize);
	(*pelf32).e_shnum = *(uint16_t*)(&buffer[0x30]);
	printf(" Number of section headers:\t    %d\n",(*pelf32).e_shnum);
	(*pelf32).e_shstrndx = *(uint16_t*)(&buffer[0x32]);
	printf(" Section header string table index: %d\n",(*pelf32).e_shstrndx);
}
void elf64(char * buffer)
{
	Elf64_Ehdr *pelf64, elf;
	pelf64 = &elf;
	int i,j;
	printf("\nELF Header:\n");
	printf(" Magic:  ");
	for(i = 0; i < EI_NIDENT; i++)
	{
		(*pelf64).e_ident[i] = buffer[i];
		printf(" %02x",(*pelf64).e_ident[i]);
	}
	printf("\n"); 
	if((*pelf64).e_ident[EI_CLASS]==0x1)
		printf(" Class:\t\t\t\t    ELF32\n");
	else if((*pelf64).e_ident[EI_CLASS]==0x2)
		printf(" Class:\t\t\t\t    ELF64\n");
	if((*pelf64).e_ident[EI_DATA]==0x1)
		printf(" Data:\t\t\t\t    2's complement, little endian\n");
	else if((*pelf64).e_ident[EI_DATA]==0x2)
		printf(" Data:\t\t\t\t    2's complement, big endian\n");
	printf(" Version:\t\t\t    %x (current)\n",(*pelf64).e_ident[EI_VERSION]);
	j=(*pelf64).e_ident[EI_OSABI];
	machinarch(j,'a');
	printf(" ABI Version:\t\t\t    %x\n",(*pelf64).e_ident[EI_ABIVERSION]);
	(*pelf64).e_type=*(uint16_t*)(&buffer[0x10]);
	type((*pelf64).e_type);
	(*pelf64).e_machine=*(uint16_t*)(&buffer[0x12]);
	machinarch('a',(*pelf64).e_machine);	
	(*pelf64).e_version = *(uint32_t*)(&buffer[0x14]);
	printf(" Version:\t\t\t    %#x\n",(*pelf64).e_version);
	(*pelf64).e_entry = *(uint64_t*)(&buffer[0x18]);
	printf(" Entry point address:\t\t    %#x\n",(unsigned int)(*pelf64).e_entry);	
	(*pelf64).e_phoff=*(uint64_t*)(&buffer[0x20]);
	printf(" Start of program headers:\t    %u (bytes into file)\n",(unsigned int)(*pelf64).e_phoff);
	(*pelf64).e_shoff=*(uint64_t*)(&buffer[0x28]);
	printf(" Start of section headers:\t    %u (bytes into file)\n",(unsigned int)(*pelf64).e_shoff);
	(*pelf64).e_flags=*(uint64_t*)(&buffer[0x30]);
	printf(" Flags:\t\t\t\t    0x%#x\n",(*pelf64).e_flags);
	(*pelf64).e_ehsize=*(uint16_t*)(&(buffer[0x34]));
	printf(" Size of this header:\t\t    %d (bytes)\n",(*pelf64).e_ehsize);
	(*pelf64).e_phentsize = *(uint16_t*)(&buffer[0x36]);
	printf(" Size of program headers:\t    %d (byts)\n",(*pelf64).e_phentsize);
	(*pelf64).e_phnum = *(uint16_t*)(&buffer[0x38]);
	printf(" Number of program headers:\t    %d\n",(*pelf64).e_phnum);
	(*pelf64).e_shentsize = *(uint16_t*)(&buffer[0x3A]);
	printf(" Size of section headers:\t    %d (bytes)\n",(*pelf64).e_shentsize);
	(*pelf64).e_shnum = *(uint16_t*)(&buffer[0x3C]);
	printf(" Number of section headers:\t    %d\n",(*pelf64).e_shnum);
	(*pelf64).e_shstrndx = *(uint16_t*)(&buffer[0x3E]);
	printf(" Section header string table index: %d\n",(*pelf64).e_shstrndx);
}
void machinarch(char j,char k)
{
	int i;
	char isa[12], abi[16];
	if(k != 'a')
	{
		isa[0]=0x00;
		isa[1]=0x02;
		isa[2]=0x03;
		isa[3]=0x08;
		isa[4]=0x14;
		isa[5]=0x16;
		isa[6]=0x28;
		isa[7]=0x49;
		isa[8]=0x04;
		isa[9]=0x3E;
		isa[10]=0xB7;
		isa[11]=0x29;
		for(i = 0; i < 12;i++)
		{
			if(isa[i] == k)
				break;
		}
		
		if(i==0)
			printf(" Machine:\t\t\t    No specific instruction set\n");
		else if(i==1)
			printf(" Machine:\t\t\t    Sun spark\n ");
		else if(i==2)
			printf(" Machine:\t\t\t    Intel 80386\n");
		else if(i==3)
			printf(" Machine:\t\t\t    MIPS R3000 big-endian\n ");
		else if(i==4)
			printf(" Machine:\t\t\t    PowerPC\n ");
		else if(i==5)
			printf(" Machine:\t\t\t    IBM S390\n ");
		else if(i==6)
			printf(" Machine:\t\t\t    ARM \n");
		else if(i==7)
			printf(" Machine:\t\t\t    Silicon Graphics SVx\n ");
		else if(i==8)
			printf(" Machine:\t\t\t    Motorola m68k family\n");
		else if(i==9)
			printf(" Machine:\t\t\t    AMD x86-64 architecture \n");
		else if(i==10)
			printf(" Machine:\t\t\t    ARM AARCH64\n ");
		else if(i==11)
			printf(" Machine:\t\t\t    Digital Alpha\n ");
	}	

	else
	{
		abi[0]=0x00;
		abi[1]=0x01;
		abi[2]=0x02;
		abi[3]=0x03;
		abi[4]=0x06;
		abi[5]=0x07;
		abi[6]=0x08;
		abi[7]=0x09;
		abi[8]=0xA;
		abi[9]=0xB;
		abi[10]=0xC;
		abi[11]=0x64;
		abi[12]=0x97;
		abi[13]=255;
		for(i = 0; i < 14; ++i)
		{
			if(abi[i]==j)
				break;	
		}
		if(i==0)
			printf(" OS/ABI:\t\t\t    UNIX - System V\n");
		else if(i==1)
			printf(" OS/ABI:\t\t\t    HP-UX\n");
		else if(i==2)
			printf(" OS/ABI:\t\t\t    NetBSD\n");
		else if(i==3)
			printf(" OS/ABI:\t\t\t    Linux\n");
		else if(i==4)
			printf(" OS/ABI:\t\t\t    Sun Solaris\n");
		else if(i==5)
			printf(" OS/ABI:\t\t\t    IBM AIX\n");
		else if(i==6)
			printf(" OS/ABI:\t\t\t    SGI IRIX\n");
		else if(i==7)
			printf(" OS/ABI:\t\t\t    FreeBSD\n");
		else if(i==8)
			printf(" OS/ABI:\t\t\t    Compaq Tru64 UNIX\n");
		else if(i==9)
			printf(" OS/ABI:\t\t\t    Novell Modesto\n");
		else if(i==10)
			printf(" OS/ABI:\t\t\t    OpenBSD\n");
		else if(i==11)
			printf(" OS/ABI:\t\t\t    ARM EABI\n");
		else if(i==12)
			printf(" OS/ABI:\t\t\t    ARM\n");
		else if(i==13)
			printf(" OS/ABI:\t\t\t    Standalone (embedded) application\n");
	}
}
void type(uint16_t s)
{
	if (ET_NONE==s)
		printf(" Type:\t\t\t\t    NO file Type\n");
	else if(ET_REL==s)
		printf(" Type:\t\t\t\t    REL (Relocatable file)\n");
	else if(ET_EXEC==s)
		printf(" Type:\t\t\t\t    EXEC (Executable file)\n");
	else if(ET_DYN==s)
		printf(" Type:\t\t\t\t    DYN (Shared object file)\n");
	else if(ET_CORE==s)
		printf(" Type:\t\t\t\t    CORE (Core file)\n");
	else if(ET_NUM==s)
		printf(" Type:\t\t\t\t    NUM (Number of defined type)\n");
	else if(ET_LOOS==s)
		printf(" Type:\t\t\t\t    LOOS (Os-specific range start)\n");
	else if(ET_HIOS==s)
		printf(" Type:\t\t\t\t    HIOS (Os-specific range end)\n");
	else if(ET_LOPROC==s)
		printf(" Type:\t\t\t\t    LOPROC (Processor-specific range start)\n");
	else if(ET_HIPROC==s)
		printf(" Type:\t\t\t\t    HIPROC (Processor-specific range end)\n");
}
