import os
from colorama import Fore, Style, init
from src.analyzer import run_cppcheck
from src.memory_checker import run_valgrind_wsl
from src.ui.report_utils import print_colored_report  # note: filename must be reports_utils.py

# Initialize colorama for color output
init(autoreset=True)

def main():
    print("✅ CLI is running...")
    print(Fore.CYAN + "🧠 Smart Debugger - Cppcheck Analysis\n")

    # Absolute path to sample.cpp (you can modify if needed)
    cpp_file = os.path.abspath(os.path.join("test", "sample.cpp"))

    # ---------------- Cppcheck ----------------
    run_cppcheck(cpp_file)
    print(Fore.GREEN + "\n📄 Cppcheck Report:\n")
    print_colored_report("reports/cppcheck_report.txt")

    # ---------------- Valgrind ----------------
    print(Fore.CYAN + "\n🔍 Valgrind Memory Analysis (via WSL)...\n")
    run_valgrind_wsl(cpp_file)
    print(Fore.GREEN + "\n📄 Valgrind Report:\n")
    print_colored_report("reports/valgrind_report.txt")

main()