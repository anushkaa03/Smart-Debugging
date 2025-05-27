#include "Debugger.h"
#include <iostream>
#include <algorithm> // for std::transform
#include <fstream>

void Debugger::analyzeCode(const std::string& code) {
    codeLines.push_back(code);
    std::cout << "Code stored for analysis: " << code << std::endl;
}

void Debugger::analyzeCodeLine(const std::string& line, int lineNumber, std::ofstream& logFile) {
    std::cout << "Line " << lineNumber << ": Analyzing code: " << line << std::endl;
    logFile << "Line " << lineNumber << ": Analyzing code: " << line << std::endl;

    std::string lowerLine = line;
    std::transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);

    if (lowerLine.find("/0") != std::string::npos || lowerLine.find("/ 0") != std::string::npos) {
       std::cout << "[Warning] Division by zero detected.\n";
logFile << "[Warning] Division by zero detected.\n";

    }

    if (line.find("int ") != std::string::npos &&
        line.find("=") == std::string::npos &&
        line.find(";") != std::string::npos) {
     std::cout << "[Warning] Variable declared without initialization.\n";
logFile << "[Warning] Variable declared without initialization.\n";

    }
    if (line.find("new ") != std::string::npos || line.find("new[") != std::string::npos) {
    std::cout << "[Notice] Detected dynamic memory allocation (new or new[]).\n";
    logFile << "[Notice] Detected dynamic memory allocation (new or new[]).\n";

    memoryAllocLines.push_back(lineNumber);  // Track line with memory allocation
}

}

void Debugger::runDebuggingTools() {
    std::ofstream logFile("debug_log.txt", std::ios::app);  // Open log file once here
    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open debug_log.txt for writing.\n";
        return;
    }

    std::cout << "Running debugging tools...\n";
    logFile << "Running debugging tools...\n";

    // Analyze all stored lines, one by one
    int lineNumber = 1;
    for (const auto& line : codeLines) {
        analyzeCodeLine(line, lineNumber++, logFile);
    }

    std::cout << "Debugging completed.\n";
    logFile << "Debugging completed.\n";

    logFile.close();
    bool deleteFound = false;
for (const auto& line : codeLines) {
    if (line.find("delete") != std::string::npos || line.find("delete[]") != std::string::npos) {
        deleteFound = true;
        break;
    }
}

if (!memoryAllocLines.empty() && !deleteFound) {
    std::cout << "[Warning] Possible memory leak: 'new' used without matching 'delete'.\n";
    logFile << "[Warning] Possible memory leak: 'new' used without matching 'delete'.\n";
}

}

void Debugger::displayGuide() {
    std::cout << "Debugging Guide:\n";
    std::cout << "1. Use GDB for step-by-step debugging.\n";
    std::cout << "2. Use Valgrind to check for memory leaks.\n";
}
