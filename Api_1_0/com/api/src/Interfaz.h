#ifndef INTERFAZ_H_
#define INTERFAZ_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
namespace api{

class Interfaz
{

	public:
		Interfaz(bool msn,bool torrent); //Constructor
		virtual ~Interfaz(); //Destructor
                bool act_msn; //atributo
                bool act_torrent;//atributo
                vector <string> ip_exc; //atributo
		int Inicio();
		int Aplicaciones();
		int AppOpciones(int app);
                int ExcepcionesIP();
                int AgregarIP();
                int EliminarIP();
                int ValidarEliminar(int n);
};
}

#endif /*INTERFAZ_H_*/


