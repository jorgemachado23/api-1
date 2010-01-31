#ifndef RUNIA_H_
#define RUNIA_H_
#include "fann.h"
namespace api{

class RunIA
{
	public:
		RunIA();
		virtual ~RunIA();
		void Run(fann_type entrada[160]);
};

}

#endif /*RUNIA_H_*/
