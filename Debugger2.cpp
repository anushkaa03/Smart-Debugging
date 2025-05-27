#include "Debugger.h"
#include <iostream>
#include <algorithm> // for std::transform
#include <fstream>
#include <cstdlib> // for system()

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
}

void Debugger::checkMemoryLeaks() {
    std::cout << "Checking for memory leaks using Valgrind...\n";
    std::string command = "valgrind --leak-check=full --track-origins=yes ./my_program 2> valgrind_output.txt";
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Memory leak check completed. See valgrind_output.txt for details.\n";
    } else {
        std::cerr << "Error: Valgrind check failed.\n";
    }
}

void Debugger::displayGuide() {
    std::cout << "Debugging Guide:\n";
    std::cout << "1. Use GDB for step-by-step debugging.\n";
    std::cout << "2. Use Valgrind to check for memory leaks.\n";
    std::cout << "   Command: valgrind --leak-check=full --track-origins=yes ./my_program\n";
    std::cout << "   Redirect output: valgrind --leak-check=full --track-origins=yes ./my_program 2> valgrind_output.txt\n";
}

