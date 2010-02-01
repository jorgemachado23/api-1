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
	
	int *decToBin(int decimal, int nBits, int binary[]) {
	    int i;
	
	    int flag = 0;
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
	
 	/***********************************************************************/	
	/************************Funcion Conversor*****************************/	
	/***Toma un caracter y lo convierte en un String de 8 posiciones*******/
	/***Equivalente a su valor en bytes***********************************/	

	string Core::Conversor(char c) 
	{  
		try{ 
		
			int n1=(int)c;
			
			int *n2;
			
			int n3[8];
		 	
		 	string val="";
		 	
		 	n2=decToBin(n1,8,n3);
   	
	
			for (int i = 0; i< 8 ; i++)
			{
				if (n3[i] == 1)
				{
					val = val + "1" ;
				}
				else
					if(n3[i] == 0) 
					{
					
					val=val +"0";
					
					}
			}
	
   			return val; 
	   }
	   catch(...)
	   {
	   		printf("Error en la conversion del caracter");
	   		
	   		return NULL;
	   }
	} 
	
} 