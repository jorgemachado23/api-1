#ifndef RUNIA_H_
#define RUNIA_H_
#include "fann.h"
namespace api{

class RunIA
{
	public:
		RunIA(); //Constructor
		virtual ~RunIA(); // Destructor
		void Run(fann_type entrada[160],char *ip_e,char *ip_s,int port_e,int port_s); //Funcion que se encarga de correr en la IA el paquete
};

}

#endif /*RUNIA_H_*/