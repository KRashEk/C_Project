#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <netinet/ip_icmp.h> //Provides declaration for icmp header
#include <netinet/tcp.h>     // Provide declaration for tcp header
#include <netinet/udp.h>     // provide declaration for udp header
#include <netinet/ip.h>      // provide declaration for ip header
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define PACKETSIZE 65536

void Processpacket(unsigned char* , int );
void print_tcp_packet(unsigned char* , int);
void writefile(char*);
void PrintData (unsigned char* , int );
void print_udp_packet(unsigned char *, int);
int Filedesc;
int sock_raw;
int tcp=0,udp=0,icmp=0,others=0,igmp=0,total=0,i,j;
struct sockaddr_in source,dest;

int main(int argc, char* argv[])
{
	int saddr_size, data_size;
	struct sockaddr saddr;
	struct in_addr in;
	
	unsigned char *buffer = (unsigned char*)malloc(PACKETSIZE);
	if(Filedesc = open("Log.txt",O_RDWR )==-1);
		Filedesc = creat("Log.txt",0644);
	//if(Filedesc < 0)
	//{
	//	printf("Unable to create file\n");
	//	exit(-1);
	//}
//	else
	printf("Start sniffing\n");
	//socket tayar karyach mhanje to sniff karu shakel

	sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
	
	if(sock_raw < 0)
	{
		printf("Socket Error\n");
		return 1;
	}
	while(1)
	{
		saddr_size = sizeof saddr;
		//packet recive karaych
		data_size = recvfrom(sock_raw, buffer, PACKETSIZE, 0, &saddr , &saddr_size);
		if(data_size <0)
		{
			printf("Recvfrom error , failed to get packets\n");
			return 1;
		}
		//Now process the packet
		Processpacket(buffer, data_size);
	}
	close(sock_raw);
	printf("Finished");
}

void Processpacket(unsigned char* buffer, int size)
{
	//Ip header packet madhun vegla kadhne
	struct iphdr *iph = (struct iphdr*)buffer;
	++total;
	switch(iph->protocol)
	{
		case 1://ICMP Protocol
			++icmp;
			//PrintIcmpPacket(Buffer, Size);
			break;
		case 2: //IGMP Protocol
			++igmp;
			break;
		case 6: //TCP Protocol
			++tcp;
			print_tcp_packet(buffer, size);
			break;
		case 17://UDP Protocol
			++udp;
			print_udp_packet(buffer, size);
			break;
		default: //Some Other Protocol like ARP etc.
			++others;
			break;
	}

	printf("TCP : %d   UDP : %d   ICMP : %d   IGMP : %d   Others : %d   Total : %d\r",tcp,udp,icmp,igmp,others,total);
}

void print_ip_header(unsigned char* Buffer, int Size)
{
	unsigned short iphdrlen;
	char str[1000] ;
	struct iphdr *iph = (struct iphdr*)Buffer;
	iphdrlen = iph->ihl*4;
	//ntohs mhanje network byte order host machin shi match karane
	memset(&source, 0, sizeof(source));
	source.sin_addr.s_addr = iph->saddr;
	
	memset(&source, 0, sizeof(dest));
	dest.sin_addr.s_addr =  iph->daddr;
	
	sprintf(str,"*****IP Header*****\n");
	writefile(str);
	sprintf(str,"|-IP Version	:%d\n",(unsigned int)iph->version);
	writefile(str);
	sprintf(str,"|-IP Header Length :%d DWORDS or %d Bytes\n",(unsigned int)iph->ihl,((unsigned int)(iph->ihl))*4);
	writefile(str);
	sprintf(str,"|Type of Service 	:%d\n",(unsigned int)iph->tos);
	writefile(str);
	sprintf(str,"|-IP Total Length	:%d Bytes(Size of Packet)\n",ntohs(iph->tot_len));
	writefile(str);
	sprintf(str,"|-Identification	:%d\n",ntohs(iph->id));	
	writefile(str);
	sprintf(str,"|-TTL		:%d\n",(unsigned int)iph->ttl);
	writefile(str);
	sprintf(str,"|-Protocol		:%d\n",(unsigned int)iph->protocol);
	writefile(str);
	sprintf(str,"|-Checksum		:%d\n",ntohs(iph->check));
	writefile(str);
	sprintf(str,"|-Source IP	:%s\n",inet_ntoa(source.sin_addr));
	writefile(str);
	sprintf(str,"|-Destination IP	:%s\n",inet_ntoa(dest.sin_addr));	
	writefile(str);
}
void writefile(char *string)
{
	int count = strlen(string);
	size_t Numtowrite = write(Filedesc,string,count);
	return;	
}
void print_tcp_packet(unsigned char* Buffer, int Size)
{
	unsigned short iphdrlen;
	char str[500];
	struct iphdr *iph = (struct iphdr *)Buffer;
	iphdrlen = iph->ihl*4;
	
	struct tcphdr *tcph = (struct tcphdr*)(Buffer + iphdrlen);
	sprintf(str,"\n\n****************TCP Packet*****************\n");
	writefile(str);
	print_ip_header(Buffer,Size);
	sprintf(str,"\nTCP Header\n");
	writefile(str);
	sprintf(str,"	|-Source Port		:%u\n",ntohs(tcph->source));
	writefile(str);
	sprintf(str,"	|-Destination Port	:%u\n",ntohs(tcph->dest));
	writefile(str);
	writefile(str);

	sprintf(str,"	|-Sequence Number	:%u\n",ntohl(tcph->ack_seq));
	writefile(str);
	sprintf(str,"	|-Acknowledge Number	:%u\n",ntohl(tcph->ack_seq));
	writefile(str);
	sprintf(str,"	|-Header Length		|%d DWORDS or %d BYTES\n", (unsigned int)tcph->doff,(unsigned int)tcph->doff*4);
	writefile(str);
	sprintf(str,"	|-Urgent Flag		|%d\n",(unsigned int)tcph->urg);
	writefile(str);
    	sprintf(str,"   |-Acknowledgement Flag : %d\n",(unsigned int)tcph->ack);
	writefile(str);
    	sprintf(str,"   |-Push Flag            : %d\n",(unsigned int)tcph->psh);
	writefile(str);
    	sprintf(str,"   |-Reset Flag           : %d\n",(unsigned int)tcph->rst);
	writefile(str);
    	sprintf(str,"   |-Synchronise Flag     : %d\n",(unsigned int)tcph->syn);
	writefile(str);
    	sprintf(str,"   |-Finish Flag          : %d\n",(unsigned int)tcph->fin);
	writefile(str);
    	sprintf(str,"   |-Window         : %d\n",ntohs(tcph->window));
	writefile(str);
    	sprintf(str,"   |-Checksum       : %d\n",ntohs(tcph->check));
	writefile(str);
    	sprintf(str,"   |-Urgent Pointer : %d\n",tcph->urg_ptr);
	writefile(str);
    	sprintf(str,"		DATA Dump                   ");
	writefile(str);
    	sprintf(str,"IP Header\n");
	writefile(str);
	PrintData(Buffer,iphdrlen);	
	sprintf(str,"TCP Header");
	writefile(str);
	PrintData(Buffer + iphdrlen, tcph->doff*4);	
	sprintf(str,"Data Payload\n");
	writefile(str);
	PrintData(Buffer + iphdrlen + tcph->doff*4,(Size - tcph->doff*4-iph->ihl*4));
	sprintf(str,"\n*********************************************************");	
	writefile(str);
}

void print_udp_packet(unsigned char* Buffer, int Size)
{
	unsigned short iphdrlen;
	struct iphdr *iph = (struct iphdr*)Buffer;
	iphdrlen = iph->ihl*4;
	char str[500];
	
	struct udphdr *udph = (struct udphdr*)(Buffer + iphdrlen);
	
	sprintf(str,"\n\n**********************UDP Packet*****************\n");
	writefile(str);
	print_ip_header(Buffer,Size);

	sprintf(str, "\nUDP Header\n");
	writefile(str);
	sprintf(str, "	|-Source Port	   : %d\n", ntohs(udph->source));
	writefile(str);
	sprintf(str, "	|-Destination port : %d\n", ntohs(udph->dest));
	writefile(str);
	sprintf(str, "	|-UDP Length	   : %d\n", ntohs(udph->len));
	writefile(str);
	sprintf(str, "	|-UDP Checksum	   : %d\n", ntohs(udph->check));
	writefile(str);
	sprintf(str,"\n");
	writefile(str);
	strcpy(str,"IP Header\n");
	writefile(str);
	PrintData(Buffer, iphdrlen);
	
	strcpy(str, "UDP Header\n");
	writefile(str);
	PrintData(Buffer+iphdrlen, sizeof udph);

	strcpy(str, "Data PayLoad\n");
	writefile(str);
		
	PrintData(Buffer + iphdrlen + sizeof(udph) ,(Size - sizeof(udph) - iph->ihl * 4));
	strcpy(str,"\n****************************************************");
	writefile(str);
}

void PrintData(unsigned char* data, int Size)
{
	char str[500];
	for(i = 0; i < Size; i++)
	{
		if( i != 0 && i % 16 == 0)
		{
			strcpy(str,"		");
			writefile(str);
			for(j = i -16; j < i ; j++)
			{
				if(data[j] >= 32 & data[j] <=128)
					sprintf(str,"&c",(unsigned char)data[j]);
				else strcpy(str, ".");
				writefile(str);
			}
			strcpy(str,"\n");
			writefile(str);
		}
		if(i % 16 == 0) 
		{
			sprintf(str, "	 %02X",(unsigned int)data[i]);
			writefile(str);
		}
		if(i == Size - 1)
		{
			for(j = 0 ; j <15-i%16; j++)
				strcpy(str,"		");
			writefile(str);
			for(j = i - i % 16; j <= i; j++)
			{
				if(data[j]>=32 && data[j]<=128) 
					sprintf(str, "%c",(unsigned char)data[j]);
				
				else
					strcpy(str,".");
			writefile(str);
				
			}
			strcpy(str,"\n");
			writefile(str);
		}
	}
	
}
