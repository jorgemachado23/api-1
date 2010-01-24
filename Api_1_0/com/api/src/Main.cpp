#include "Training.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>

using namespace api;
	
int main(int argc, char **argv)
{
	Training entrenamiento;
	
	entrenamiento.RunTrainingTorrent();
	
	//Training *entrenamiento = new Training();
	
	//entrenamiento->RunTrainingTorrent();
	
	char *net;
	char *mask;
	char *dev;
	int ret;
	
	char errbuf[PCAP_ERRBUF_SIZE];
	
	bpf_u_int32 netp;
	
	bpf_u_int32 maskp;
	
	struct in_addr addr;
	
	if ((dev = pcap_lookupdev(errbuf)) == NULL) //conseguimos la primera interfaz libre
	{
		printf("ERROR %s\n",errbuf);
		exit(-1);
	}
	printf("Nombre del dispositivo: %s\n",dev); //mostramos el nombre del dispositivo
	
	if ((ret = pcap_lookupnet(dev,&netp,&maskp,errbuf))== -1 ) //consultamos las direccion de red y las mascara
	{
		printf("ERROR %s\n",errbuf);
		exit(-1);
	}
	
	addr.s_addr = netp; //Traducimos la direccion de red a algo legible
	
	if ((net = inet_ntoa(addr))==NULL)
	{
		perror("inet_ntoa");
		exit(-1);
	}
	
	printf("Direccion de Red: %s\n",net);
	
	addr.s_addr = maskp; //Idem para la mascara de subred
	
	mask = inet_ntoa(addr);
	
	if ((net=inet_ntoa(addr))==NULL)
	{
		perror("inet_ntoa");
		
		exit(-1);
	}
	printf("Mascara de Red: %s\n",mask);

	fscanf(stdin,"%s");
	
	return 0; 
}
