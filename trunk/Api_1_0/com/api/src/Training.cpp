#include "Training.h"
#include <stdio.h>
#include <string>
#include "fann.h"
namespace api
{
 	/*********************************************************************/
 	/*********************************************************************/
 	/******************** Atributos de la clase **************************/
 	/*********************************************************************/
 	/*********************************************************************/	
	
	
	const unsigned int num_input = 160; //cantidad de neuronas de entrada
	const unsigned int num_output = 1; //cantidad de salidas
	const unsigned int num_layers = 3; //numero de capas de la red
	const unsigned int num_neurons_hidden_2 = 10; // numero de neuronas internas
	const float desired_error = (const float) 0.001; //constante para el error
	const unsigned int max_epochs = 50000;
	const unsigned int epochs_between_reports = 1000;
	
	/*******Contructor********/
 	Training::Training()
	{
	}
	
	/******Destructor*******/
	Training::~Training()
	{
	}
 	
 	/*******************************************************************/
 	/*******************************************************************/
 	/******************** Metodos de la clase **************************/
 	/*******************************************************************/
 	/*******************************************************************/
 	
 	/****Metodo que corre el entrenamiento y genera en un archivo****/
 	/****La red neuronal que necesita para correr el bloqueador*****/
 	void Training::RunTrainingTorrent()
 	{
 		//Crea una la estructura con las contastes establecidad anteriormente 
 		struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden_2, num_output);

		//Se define la funcion de activacion para las neuronas escondidas en este caso Sinosoidal
		fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
		
		//Se define la funcion de activacion para la salida que sera sinosiodal
		fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
		
		//Se define donde se encuentra el archivo de data y junto con el los parametros para entrenamiento
		fann_train_on_file(ann, "/root/workspace/API/Entrenamiento_Torrent5.dat", max_epochs, epochs_between_reports, desired_error);
		
		//Se especifica en que archivo se va a guardar la estructura, es decir la red neuronal entrenada
		fann_save(ann, "Torrent.net");
 		
 		printf("Se concluyo el entrenamiento sin contratiempos");
 	}
	
}
