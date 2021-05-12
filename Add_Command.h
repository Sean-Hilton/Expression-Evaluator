#ifndef addcom
#define addcom
#include "BinaryCommand.h"


class Add_Command : public BinaryCommand {
public:
	virtual int evaluate(int num1, int num2)const;

	virtual int precedOf(void);
	virtual std::string symb(void);
};
#endif
