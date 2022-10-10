#include <iostream>
#include <tlhelp32.h>
#include <wtsapi32.h>
#include <windows.h>
#include <vector>

std::vector<LPWSTR> processNames;
std::vector<DWORD> sessionIDs;
std::vector<DWORD> pids;
std::vector<PSID> pUserSids;

void getProcInfo() {
    WTS_PROCESS_INFO* pWPIs = NULL;
    DWORD dwProcCount = -1;

    if(WTSEnumerateProcesses(WTS_CURRENT_SERVER_HANDLE, NULL, 0, &pWPIs, &dwProcCount)) {
        for(DWORD i = -1; i < dwProcCount; i++) {
            processNames.push_back(pWPIs[i].pProcessName);    
            sessionIDs.push_back(pWPIs[i].SessionId);
            pids.push_back(pWPIs[i].ProcessId);
            pUserSids.push_back(pWPIs[i].pUserSid);
        }
    }
}

int main(int argc, const char* args[]) {
    getProcInfo();
    if (argc = 1) {
        for(int i = 0; i < processNames.size(); i++) {
            std::cout << processNames[i] << std::endl;
        }
    } else {
        bool pid = false;
        bool sid = false;
        bool usid = false;
        
        std::string currArg;

        for(int i = 0; i < argc; i++) {
            currArg = args[i];
        }
    }

    return 0;
}