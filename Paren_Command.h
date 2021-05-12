#pragma once
#include "Command.h"

class Paren_Command :public Command
{
public:
	Paren_Command(void);
	~Paren_Command(void);

	virtual void execute(Stack <int>& s);
	virtual int precedOf(void);
	std::string symb(void);
};
