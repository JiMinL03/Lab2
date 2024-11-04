#include <stdio.h>
#include <Windows.h>
int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // 자식 프로세스 생성
    if (!CreateProcess(NULL, "child_process.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "CreateProcess failed.\n");
        return -1;
    }

    // 자식 프로세스의 종료를 대기
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("waiting\n");

    // 핸들 닫기
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}