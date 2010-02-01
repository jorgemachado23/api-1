#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include <sstream>
#include <iostream>
#include "Core.h"

namespace api{	
	
	
	
	//Clase que contiene el procesamiento de paquetes para ser llevado a la inteligencia
	// artificial para su posterior identificacion 
	
	using namespace std;
		
	/*********************************************************************/
 	/*********************************************************************/
 	/******************** Atributos de la clase **************************/
 	/*********************************************************************/
 	/*********************************************************************/	

	/*******Contructor********/	
	Core::Core()
	{
	}
	/******Destructor*******/	
	Core::~Core()
	{
	}
	
	/***********************************************************************/	
	/************************Funcion decToBinr******************************/	
	/***Toma un areglo de enteros y devuelve su representacion binaria******/
	/**********Usando el compelemento a 2***********************************/	
	
	int* Core::decToBin(char c,int binary[]) {
	    int i;
	    
		int decimal = (int)c;
	    
	    int flag = 0;
	    
	    int nBits = 8;
	    /* Si es un número negativo, lo hacemos positivo y le restamos 1(*), */
	    /* además activamos el flag para saber que es negativo */
	
	    /* (*) El complemento a 2 es igual que el complemento a 1, que es cambiar */
	    /* 1->0, 0->1, y luego sumando 1 en binario. Aquí restamos 1 en decimal y */
	    /* luego pasamos a binario. */
	    
	    if (decimal < 0) 
	        {
	            flag = 1;
	            decimal = -decimal-1;
	        }
	
	    /* Pasamos a binario, atendiendo a lo que vale flag, en lugar de añadir (decimal%2) */
	    /* como es normal, le hacemos un XOR con flag, vemos la tabla de verdad de XOR */
	    /* |    A    (xor)   B       =   X   |  */
	    /* |     0      |        0       |   0   |  */
	    /* |     0      |        1       |   1   |  */
	    /* |     1      |        0       |   1   |  */
	    /* |     1      |        1       |   0   |  */
	    /* ------------------------------   */
	    /* Por tanto, cuando flag vale 0, al encontrar un 0, pondremos un 0, y al encontrar un 1, ponemos un 1 */
	    /*           Pero cuando flag vale 1, al encontrar un 0, pondremos un 1, y al encontrar un 1, ponemos un 0 */
	    while (decimal > 0) 
	        {
	            binary[--nBits] = flag^(decimal%2);
	            decimal/=2;
	        }
	
	    /* Con esto terminamos de llenar el array, con 0 a la izquierda si es un número positivo */
	    /* y con 1s si es un número negativo */
	    while (nBits>0)
	        binary[--nBits] = flag;
	    
	    /* Devolvemos el array */
	    return binary;
	}
	

	
} 