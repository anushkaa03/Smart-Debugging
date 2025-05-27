#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <string>
#include <vector>
#include <fstream>

class Debugger {
public:
    void analyzeCode(const std::string& code);
    void runDebuggingTools();
    void displayGuide();
    void checkMemoryLeaks();
    std::vector<int> memoryAllocLines;  // Tracks line numbers with `new`/`new[]`

    // ✅ New method for analyzing each line
    void analyzeCodeLine(const std::string& line, int lineNumber, std::ofstream& logFile);
 static void log(const std::string& message);
private:
    std::vector<std::string> codeLines;
};

#endif // DEBUGGER_H
