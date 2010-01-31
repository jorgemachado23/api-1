#include "Training.h"
#include "RunIA.h"
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
//	
//	entrenamiento.RunTrainingTorrent();
//	
//	entrenamiento.RunTrainingMSN();
	
	
	FILE *file_in;
	
	long i = 0;
	
    file_in=fopen("/home/user/Desktop/pruebas/paquete.txt","r");
	
	fann_type entrada[160];
	
	        while(!feof(file_in))
        	{
        	
        	char aux = getc(file_in);
        	
	        	if ( aux == '0' )
	        	{
	        		entrada[i]=0;
	        		i = i + 1;
	        	}
	        	else 
		        	if (aux == '1')
		        	{
		        		entrada[i]=1;
		        		i= i + 1;
		        	}
	        	
			}
	
	RunIA corrida;
	
	corrida.Run(entrada);
	
	fscanf(stdin,"%s");
}
