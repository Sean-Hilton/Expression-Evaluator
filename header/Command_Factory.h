#ifndef ComFac
#define ComFac



#include "Add_Command.h"
#include "Sub_Command.h"
#include "Mult_Command.h"
#include "Div_Command.h"
#include "Mod_Command.h"
#include "Num_Command.h"
#include "Paren_Command.h"
class Command_Factory
{
public:
	Command_Factory(void){}
	virtual ~Command_Factory(void) {}
	
	
	virtual Add_Command *create_Add_Command(void) = 0;
	virtual Sub_Command *create_Sub_Command(void) = 0;
	virtual Mult_Command *create_Mult_Command(void) = 0;
	virtual Div_Command *create_Div_Command(void) = 0;
	virtual Mod_Command * create_Mod_Command(void)=0;
	virtual Num_Command* create_Num_Command (int) = 0;
	virtual Paren_Command* create_Paren_Command(void) = 0;

private:
	
	
};
#endif 
