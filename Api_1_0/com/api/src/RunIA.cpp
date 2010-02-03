#include "RunIA.h"
#include "fann.h"
namespace api{
	
	
	
 	/*********************************************************************/
 	/*********************************************************************/
 	/******************** Atributos de la clase **************************/
 	/*********************************************************************/
 	/*********************************************************************/	
	
	/*******Contructor********/	
	RunIA::RunIA()
	{
	}
	/******Destructor*******/
	RunIA::~RunIA()
	{
	}
	
	void RunIA::Run(fann_type entrada[160],char *ip_e,char *ip_s,int port_e,int port_s)
	{
		//constante que permite la diferenciacion del paquete
		#define UMBRAL_RECONOCIMIENTO 0.6
		
    	//punteros que contienen el valor de la salida del calculo sobre la red neuronal
		fann_type *calc_out,*calc_out2;
		
		//estructuras que contienen la informacion del entrenamiento realizado
		struct fann *ann = fann_create_from_file("Torrent.net");
		
		struct fann *ann2 = fann_create_from_file("MSN.net");
		
		//se calculan las salidas para dar una respuesta
		calc_out = fann_run(ann, entrada);
		calc_out2 = fann_run(ann2, entrada);
			
			//se verifica la respuesta segun la salida
			if(*calc_out > UMBRAL_RECONOCIMIENTO)
		 		printf("Es torrent (%f)\n\n",calc_out[0]);
	 		else
	 			if (*calc_out < 0 && *calc_out2 > UMBRAL_RECONOCIMIENTO)
		 		printf("Es msn(%f)\n\n",calc_out2[0]);
		 		else
		 		printf("No puedo identificar el paquete\n\n");
		 		
		
	}
}