#include "Training.h"
#include "RunIA.h"
#include "Sniffer.h"
#include "Interfaz.h"
#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

using namespace api;
	
int main(int argc, char **argv)
{
        bool act_msn=false;

        bool act_torrent=false;
   
	Interfaz *interfazg = new Interfaz(act_msn,act_torrent);

	interfazg->Inicio();
	
//	Training entrenamiento;
//	
//	entrenamiento.RunTrainingMSN();
//	
//	entrenamiento.RunTrainingTorrent();
//	
//	Sniffer sniffer;
//	
//	sniffer.RunSniffing(argc, argv);
	
	return 0;	
}
