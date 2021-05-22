#ifndef divcom
#define divcom
#include "BinaryCommand.h"


class Div_Command : public BinaryCommand {
public:

	virtual int evaluate(int num1, int num2)const;
	virtual int precedOf(void);
	virtual std::string symb(void);
};
#endif
