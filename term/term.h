#pragma <once>
#include <iostream>

class Terminal {
public:
    std::string binPath;

    static std::string username();
    static std::string hostname();
    static std::string wd();

    static void prompt();
    
    static std::string command();
};
//