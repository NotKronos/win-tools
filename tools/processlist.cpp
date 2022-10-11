#include <iostream>
#include "utils.h"

std::vector<LPWSTR> processNames;
std::vector<DWORD> sessionIDs;
std::vector<DWORD> pids;
std::vector<PSID> pUserSids;


int main(int argc, const char* argv[]) {
    getProcInfo(processNames, sessionIDs, pids, pUserSids);
    if (argc = 1) {
        for(int i = 0; i < processNames.size(); i++) {
            std::cout << processNames[i] << std::endl;
        }
    } else {
        bool pid = false;
        bool sid = false;
        bool usid = false;

        for(int i = 0; i < argc; i++) {
            if(checkArgs(argv[i], "--sids", "-s")) {
                sid = true;
            }
            if(checkArgs(argv[i], "--pids", "-p")) {
                pid = true;
            }
            if(checkArgs(argv[i], "--usids", "-u")) {
                usid = true;
            }
            if(checkArgs(argv[i], "--help", "-h")) {
                std::cout << "--sids, -s : print sessionIDs" << std::endl;
                std::cout << "--pids, -p : print processIDs" << std::endl;
                std::cout << "--usids, -u : print user session IDs" << std::endl;
                std::cout << "--help, -h : show this message" << std::endl;
            }
        }
        for(int i = 0; i < processNames.size(); i++) {
            std::cout << processNames[i];
            if(sid == true) std::cout << "  " << sessionIDs[i];
            if(pid == true) std::cout << "  " << pids[i];
            if(usid == true) std::cout << "  " << pUserSids[i];
            std::cout << std::endl;
        }
    }

    return 0;
}