#include "term/term.h"
#include <iostream>
#include <filesystem>
#include <windows.h>
#include <lmcons.h>
#include <string>

std::string Terminal::wd() {
    return std::filesystem::current_path().string();
}

std::string Terminal::username() {
    TCHAR username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    if(!GetUserName(username, &username_len)) {
        std::cerr << "<win-tools> [ERROR]: Cannot get username";
        return "!";
    }
    std::wstring wstr(&username[0]);
    std::string str(wstr.begin(), wstr.end());
    return str;
}

std::string Terminal::hostname() {
    TCHAR  infoBuf[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD  bufCharCount = MAX_COMPUTERNAME_LENGTH + 1;
	if (!GetComputerName(infoBuf, &bufCharCount)) {
        std::cerr << "<win-tools> [ERROR]: Cannot get hostname";
		exit(0);
	}
    std::wstring wstr(&infoBuf[0]);
    std::string str(wstr.begin(), wstr.end());
    return str;
}

void Terminal::prompt() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string cwd = wd();
	cwd.erase(cwd.begin(), cwd.begin() + 2);
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << username() + "@" + hostname() + ":";
	SetConsoleTextAttribute(hConsole, 9);
	std::cout << cwd + " $ ";
	SetConsoleTextAttribute(hConsole, 15);
}

std::string Terminal::command() {
    std::string command;
    std::getline(std::cin, command);
    return command;
} 


