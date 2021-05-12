
#include "Add_Command.h"



	

	int Add_Command::evaluate(int num1, int num2)const {
		return num1 + num2;
	}

	 int Add_Command::precedOf(void)
	{
		return (3);
	}
	 std::string Add_Command::symb(void)
	{
		return ("+");
	}

