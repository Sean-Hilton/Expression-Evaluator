#ifndef modcom
#define modcom
#include "BinaryCommand.h"

class Mod_Command : public BinaryCommand {
public:
	virtual int evaluate(int num1, int num2)const;
	virtual int precedOf(void);
	virtual std::string symb(void);

};
#endif