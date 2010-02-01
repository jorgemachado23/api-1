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
	/************************Funcion Conversor*****************************/	
	/***Toma un caracter y lo convierte en un String de 8 posiciones*******/
	/***Equivalente a su valor en bytes***********************************/	

	string Core::Conversor(char c) 
	{  
		try{ 
		
			int base1=2, base2=10;	
			
			unsigned long alg,mult=1,n1=(int)c,n2=0;
		 	
		 	string val; 
		   
				while (n1 > 0) 
			   	{ 
			     	alg = n1 % base1; 
			      	
			      	n1 /= base1; 
			      	
			      	n2 += (alg*mult); 
			      	
			      	mult *= base2; 
			   	}
		   	
			   	std::stringstream ss;
			  	
			  	ss << n2;
			  	
			  	val=ss.str();
		  	
			  	while (val.size()<8)
			  	{
			  	
			  	val="0"+val;
			  	
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