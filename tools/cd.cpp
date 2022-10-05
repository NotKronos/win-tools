#include <iostream>
#include <filesystem>

int main(int argc, const char* argv[]) {
    if(argc > 2) {
        std::cerr << "[cd]: Too many arguments" << std::endl; 
        return 1;
    }

    if (argc == 1) {
        std::cerr << "[cd]: No arguments specified" << std::endl;
        return 1;
    }

    std::string current_path = std::filesystem::current_path().string();
    std::string arg(argv[1]);

    if(arg.rfind("..", 0) == 0) {
        std::filesystem::current_path(arg);
    }

    else {
        std::filesystem::path path;
        path = std::filesystem::current_path() / ("C:" + arg);

        if(std::filesystem::is_directory(path)) 
            std::filesystem::current_path(path);
        else    
            std::cerr << "[cd]: No such directory" << std::endl;
    }
    return 0;
}
