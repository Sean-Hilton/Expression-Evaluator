#include "Queue.h"
#include "Stack.h"
#include "Array.h"
#include "Stack_Command_Factory.h"
#include <sstream>
#include <string>
#include <iostream>


Queue<Command*> infix_to_postfix(const std::string& infix, Stack_Command_Factory factory);
bool checkforop(std::string& token);
Command* chooseOp(std::string, Stack_Command_Factory);
int evalPostfix(Queue<Command*> commands, Stack_Command_Factory& factory);



int main() {
	std::string infix = "";
	std::string postfixstr;
	bool T = true;
	Stack <int> s;
	Stack_Command_Factory factory; // temporarily hold operations
	Queue <Command*> postfix;	// Queue of command * in postfix format
	int finaleval;
	std::cout << "Please enter an expression:\n";
        std::cout << "Type QUIT to exit \n\n";
  
	bool continueloop = true;
	while (continueloop==true)
	{
		
		
		//Gets the input as infix notation
		std::getline(std::cin, infix);
		std::size_t entry = infix.find_first_not_of("0123456789+-*/%() ");
		
		try
		{
			
			//check for input to quit program
			if (infix == "QUIT" || infix == "quit" )
				continueloop = false;
				
			
			
			//if entry contains other data throw error
			else if (entry != std::string::npos)  
				throw std::logic_error("Invalid Expression\n");

			else {
				postfix = infix_to_postfix(infix, factory);
				finaleval = evalPostfix(postfix, factory);
				std::cout << "Result:" << finaleval << "\n" << std::endl;
				}
		}
		catch (std::logic_error e)
		{
			std::cout << e.what() << std::endl;
			
		}

		
	}





}




/***
Function for transforming infix notation to postfix notation

***/
Queue<Command*> infix_to_postfix(const std::string& infix, Stack_Command_Factory factory)
{


	Queue <Command*> commands;
	Stack <Command*> operations;
	Stack <int> operand;
	
	
	std::string word;
	std::istringstream input(infix);
	std::string token;

	int intver = 5;
	std::string postfix = "";
	Command* cmd = 0;
	Command* cmd2 = 0;  // holds command as stack is getting popped
	while (!input.eof()) {
		input >> token;
		try
		{
			
			
			//if first token is operator throw error
			if (token != "(" && checkforop(token) && commands.is_empty()) 
				throw std::logic_error("Syntax Error");
			
		}
		catch (std::logic_error e)
		{
			std::cout << e.what() << std::endl;

		}


		//check for operand
		if (!checkforop(token) && token != ")")
		{  

			intver = stoi(token);
			cmd = factory.create_Num_Command(intver);

			commands.enqueue(cmd);

		}
		
		//check for operation
		else if (checkforop(token))  
		{
			cmd = chooseOp(token, factory);
			if (operations.is_empty() || (operations.top()->precedOf() > cmd->precedOf())) //if top is lower prec
				operations.push(cmd);
			else
			{
				while (!operations.is_empty() && operations.top()->symb() != "(" && operations.top()->precedOf() <= cmd->precedOf()) //if top is higher prec
				{
					if (cmd->symb() == "(")
						operations.push(cmd);
					else
					{
						cmd2 = operations.top();
						commands.enqueue(cmd2);

						operations.pop();
					}
				}
				operations.push(cmd);
			}
		}

		else if (token == ")")
		{
			while (operations.top()->symb() != "(")
			{
				commands.enqueue(operations.top());
				operations.pop();
			}
			delete operations.top();
			operations.pop();
		}
	}
	
	
	//pop to queue until stack is empty
	while (!operations.is_empty())  
	{
		commands.enqueue(operations.top());
		operations.pop();
	}
	return commands;
}


//check to see if token is an operation
bool checkforop(std::string& token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "(") {
		return true;
	}
	else {
		return false;
	}
}

Command* chooseOp(std::string token, Stack_Command_Factory factory)
{
	Command* cmd = 0;
	if (token == "+")
		cmd = factory.create_Add_Command();
	else if (token == "-")
		cmd = factory.create_Sub_Command();
	else if (token == "*")
		cmd = factory.create_Mult_Command();
	else if (token == "/")
		cmd = factory.create_Div_Command();
	else if (token == "%")
		cmd = factory.create_Mod_Command();
	else if (token == "(")
		cmd = factory.create_Paren_Command();
	return cmd;
}


//function to evaluate the postfix expression
int evalPostfix(Queue<Command*> commands, Stack_Command_Factory& factory)
{
	Stack<int> s;

	Command* cmd = 0;

	char token2;
	std::stringstream str;
	int operand_count = 0;
	int result = 0;



	while (!commands.is_empty())
	{
		cmd = commands.dequeue();
		cmd->execute(s);
		delete cmd;
	}

	result = s.top();
	return result;
}
