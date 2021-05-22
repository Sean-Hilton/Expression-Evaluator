
#include "Mod_Command.h"




	 int Mod_Command::evaluate(int num1, int num2)const
	 {
		 
		 bool exception_caught = true;
		 try {
			 if (num2 == 0)
				 throw std::logic_error("ERROR...Cannot mod by zero...ERROR");
		 }
		 catch (std::logic_error e) {
			 std::cout << e.what() << std::endl;
			 return 0;
			 
		 }
		 exception_caught = false;
		 if(exception_caught==false)
			return num1 % num2;
		 
		 
	 }

	 int Mod_Command::precedOf(void)
	 {
		return (2);
	 }
	 std::string Mod_Command::symb(void)
	 {
		return ("%");
	 }

