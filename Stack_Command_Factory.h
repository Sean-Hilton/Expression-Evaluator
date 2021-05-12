#include "Command_Factory.h"
#include "Stack.h"
class Stack_Command_Factory :public Command_Factory
{
public:
	Stack_Command_Factory(void);
	virtual ~Stack_Command_Factory(void);
	
	
	virtual Add_Command* create_Add_Command(void);
	virtual Sub_Command* create_Sub_Command(void);
	virtual Mult_Command* create_Mult_Command(void);
	virtual Div_Command* create_Div_Command(void);
	virtual Mod_Command* create_Mod_Command(void);
	virtual Num_Command* create_Num_Command(int);
	virtual Paren_Command* create_Paren_Command(void);
};
