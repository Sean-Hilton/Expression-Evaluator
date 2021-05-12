#pragma once
#include "Command.h"

#include "Command.h"
class Num_Command : public Command
{
public:
	Num_Command(void);
	Num_Command(int);
	virtual void execute(Stack <int>& s_);
	virtual int precedOf(void);
	virtual std::string symb(void);


	int num;
};