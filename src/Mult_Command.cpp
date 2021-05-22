
#include "Mult_Command.h"


	 int Mult_Command::evaluate(int num1, int num2)const 
	 {
		return num1 * num2;
	 }

	 int Mult_Command::precedOf(void)
	 {
		return (2);
	 }
	 std::string Mult_Command::symb(void)
	 {
		return ("*");
	 }
