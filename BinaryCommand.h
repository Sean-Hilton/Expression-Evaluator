#ifndef BinCom
#define BinCom

#include "Command.h"
#include "Stack.h"
class BinaryCommand:public Command {

	

public:

	
	BinaryCommand();
	virtual ~BinaryCommand(void);

	virtual void execute(Stack<int> & s_);

	virtual int evaluate(int num1, int num2) const = 0;
	
	

	





	
};
#endif