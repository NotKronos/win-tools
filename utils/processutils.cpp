#include "utils.h"

void getProcInfo(std::vector<LPWSTR> processNames, std::vector<DWORD> sessionIDs, std::vector<DWORD> pids, std::vector<PSID> pUserSids) {
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