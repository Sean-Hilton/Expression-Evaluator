#include "Stack_Command_Factory.h"



Stack_Command_Factory::Stack_Command_Factory(void)
	
{}

Stack_Command_Factory::~Stack_Command_Factory(void)
{}


Add_Command* Stack_Command_Factory::create_Add_Command(void)
{
	return new  Add_Command;
}

Sub_Command* Stack_Command_Factory::create_Sub_Command(void)
{
	return new Sub_Command;
}

Mult_Command* Stack_Command_Factory::create_Mult_Command(void)
{
	return new Mult_Command;
}
Div_Command* Stack_Command_Factory::create_Div_Command(void)
{
	return new Div_Command;
}
Mod_Command* Stack_Command_Factory::create_Mod_Command(void)
{
	return new Mod_Command;
}
Num_Command* Stack_Command_Factory::create_Num_Command(int num)
{
	return new Num_Command(num);
}
Paren_Command* Stack_Command_Factory::create_Paren_Command(void)
{
	return new Paren_Command;
}