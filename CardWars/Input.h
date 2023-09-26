#pragma once
#include <string>
#include <vector>

class Input
{

public:
	static std::string GetString(std::string message);
	static int GetInteger(std::string message, int min, int max);
	static int GetMenuSelection(std::vector<std::string> menuOptions);
	static void PressEnter(bool silent = false);

private:
	static void ClearInputBuffer();
};

