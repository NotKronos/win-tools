//
// Created by NotKronos on 2022-10-05.
//

#include <iostream>
#include <fstream>

int main(int argc, const char* args[]) {
    std::fstream file;

    std::string filename;

    for(int i = 1; i < argc; i++) {
        filename = args[i];

        file.open(filename);
        if(file) {
            std::cerr << "[mkfile]: file already exists" << std::endl;
            file.close();
        }
        else {
            file.open(filename, std::ios::out);
            if(!file) {
                std::cerr << "[mkfile]: error in creating file" << std::endl;
            } else {
                std::clog << "[mkfile]: file " << filename << " created successfully" << std::endl;
            }
            file.close();
        }
    }

    return 0;
}
