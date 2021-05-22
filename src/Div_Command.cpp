#include "Div_Command.h"


	

	  int Div_Command::evaluate(int num1, int num2)const 
	  {
		  

		 bool exception_caught = true;
		 try
		 {
			 if (num2 == 0)
				 throw std::logic_error("ERROR...Cannot divide by zero...ERROR");
		 }
		 catch (std::logic_error e)
		 {
			 std::cout << e.what() << std::endl;
			 return 0;
		 }
		 exception_caught = false;
		 if(exception_caught==false)
			return num1 / num2;     
	  }

	  int Div_Command::precedOf(void)
	  {
		 return (2);
	  }

	  std::string Div_Command::symb(void)
	  {
		 return ("/");
	  }
