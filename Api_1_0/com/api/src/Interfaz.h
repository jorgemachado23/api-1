#ifndef INTERFAZ_H_
#define INTERFAZ_H_
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;
namespace api{

class Interfaz
{	
	
	public:
		Interfaz(); //Constructor
		virtual ~Interfaz(); //Destructor	
		int Inicio();
		int Aplicaciones();
		int AppOpciones(char *app);
};
}

#endif /*INTERFAZ_H_*/
