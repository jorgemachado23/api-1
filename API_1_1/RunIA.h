#ifndef RUNIA_H_
#define RUNIA_H_
#include "fann.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
namespace api{

class RunIA
{
	public:
		RunIA(bool msn, bool torrent,vector <string> ip_e); //Constructor
		virtual ~RunIA(); // Destructor
				bool act_msn; //atributo
                bool act_torrent;//atributo
                vector <string> ip_exc; //atributo
		void Run(fann_type entrada[160],string ip_e,string ip_s,int port_e,int port_s); //Funcion que se encarga de correr en la IA el paquete
};

}

#endif /*RUNIA_H_*/
