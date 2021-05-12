#include "BinaryCommand.h"




	




	BinaryCommand::BinaryCommand(void)
		
	{}

	BinaryCommand::~BinaryCommand(void)
	{
	
	}

	void BinaryCommand::execute(Stack<int>& s_)
	{

	    int num1 = s_.top();
		s_.pop();
		int num2 = s_.top();
		s_.pop();
	    int result = this->evaluate(num2, num1);   
		s_.push(result);


	}











