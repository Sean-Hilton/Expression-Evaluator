#ifndef multcom
#define multcom
#include "BinaryCommand.h"

class Mult_Command : public BinaryCommand {
public:

	virtual int evaluate(int num1, int num2)const;
	virtual int precedOf(void);
	virtual std::string symb(void);

};
#endif
