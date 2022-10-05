//
// Created by NotKronos on 2022-10-05.
//

#include <iostream>
#include <filesystem>

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "[mkdir]: Not enough arguments" << std::endl;
    }
    else {
        for (int i = 1; i < argc; i++) {
            if (std::filesystem::create_directory(argv[i])) {
                std::clog << "[mkdir]: Created directory: " << argv[i] << std::endl;
            }
            else {
                std::cerr << "[mkdir]: Cannot create directory: " << argv[i] << std::endl;
            }
        }
    }
}
