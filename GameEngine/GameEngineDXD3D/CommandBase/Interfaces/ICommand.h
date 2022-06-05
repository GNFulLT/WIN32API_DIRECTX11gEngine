#pragma once
#ifndef ICOMMAND_H
#define ICOMMAND_H
class ICommand 
{
public:
	virtual ~ICommand() 
	{}
	virtual void Execute() const = 0;
};
#endif