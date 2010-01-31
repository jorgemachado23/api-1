#ifndef ENTRENAMIENTO_H_
#define ENTRENAMIENTO_H_

namespace api
{

class Training
{
	public:
		Training();// constructor
		virtual ~Training(); //destructor
		void RunTrainingTorrent(); //funcion que realiza el entrenamiento
		void RunTrainingMSN();// funcion que realiza el entrenamiento para el protocolo Messenger
};

}

#endif /*ENTRENAMIENTO_H_*/
