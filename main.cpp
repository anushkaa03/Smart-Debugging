#include <iostream>
#include <fstream>
#include "Debugger.h"

int main() {
    Debugger debugger;
    std::string code;
    int lineNumber = 1;

    std::ofstream logFile("debug_log.txt");
    if (!logFile) {
        std::cerr << "Error: Could not open log file.\n";
        return 1;
    }

    std::cout << "Enter C++ code to debug (end with 'END'):\n";
    while (std::getline(std::cin, code) && code != "END") {
        debugger.analyzeCodeLine(code, lineNumber++, logFile);  // ✅ this logs
    }

    logFile.close();
    debugger.runDebuggingTools();
    return 0;
}
