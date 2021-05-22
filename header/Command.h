#ifndef com
#define com
#include "Stack.h"



class Command {
public:
	
	



	virtual void execute( Stack <int>& s_) = 0;
	virtual int precedOf(void) = 0;
	virtual std::string symb(void) = 0;
};
#endif
