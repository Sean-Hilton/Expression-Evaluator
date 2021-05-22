#include "Sub_Command.h"




    int Sub_Command::evaluate(int num1, int num2) const
	{
		return num1 - num2;
	}
    int Sub_Command::precedOf(void)
	{
		return (3);
	}
    std::string Sub_Command::symb(void)
	{
		return ("-");
	}

	
