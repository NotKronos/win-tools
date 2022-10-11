#include "utils.h"

bool endsWith(std::string const& fullString, std::string const& ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    }
    else {
        return false;
    }
}

bool checkArgs(const char* givenArg, const char* arg, const char* flag) {
    if ((strcmp(givenArg, arg) == 0 || strcmp(givenArg, flag) == 0)) return true;
    else return false;
}