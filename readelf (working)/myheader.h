#include <stdio.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

void elf32(char *);
void elf64(char *);
void machinarch(char,char);
void type(uint16_t);
