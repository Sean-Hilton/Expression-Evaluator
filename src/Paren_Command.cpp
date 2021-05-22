#include "Paren_Command.h"

Paren_Command::Paren_Command(void)
{}

Paren_Command::~Paren_Command(void)
{}

int Paren_Command::precedOf(void)
{
	return (1);
}

void Paren_Command::execute(Stack<int>& stack)
{

}

std::string Paren_Command::symb(void) {
	return ("(");
}
