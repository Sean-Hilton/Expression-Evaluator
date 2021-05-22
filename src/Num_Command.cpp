#include "Num_Command.h"


Num_Command::Num_Command(void)
	:num(0)
{}


Num_Command::Num_Command(int num)
	:num(num)
{}


void Num_Command::execute(Stack <int>& s_)
{
	s_.push(num);
}



int Num_Command::precedOf(void)
{
	return (0);
}
 std::string Num_Command::symb(void)
{
	
	return ("5");
}
