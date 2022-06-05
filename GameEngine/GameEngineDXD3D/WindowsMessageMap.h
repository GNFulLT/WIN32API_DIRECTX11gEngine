#pragma once

#ifndef WINDOWSMESSAGEMAP_H
#define WINDOWSMESSAGEMAP_H

#include <unordered_map>
#include <Windows.h>
class WindowsMessageMap {
public:
	WindowsMessageMap();
	std::string operator()(DWORD message, LPARAM lParam, WPARAM wParam) const;
private:
	std::unordered_map<DWORD, std::string> map;
};
#endif
