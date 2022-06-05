#pragma once
#ifndef ICOMMAND_MANAGER_H
#define ICOMMAND_MANAGER_H

#include "ICommand.h"
#include <queue>
class ICommandManager {
	virtual ~ICommandManager(){};
	virtual void ExecuteAll() = 0;

};

#endif