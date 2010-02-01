#ifndef CORE_H_
#define CORE_H_
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;
namespace api{

class Core
{	
	
	public:
		Core(); //Constructor
		virtual ~Core(); //Destructor	
		int* decToBin(char c,int binary[]);//Funcion que devuelve el valor en bytes de un char 
};
}
#endif /*CORE_H_*/
