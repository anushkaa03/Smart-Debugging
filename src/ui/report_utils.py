from colorama import Fore, Style

def print_colored_report(file_path):
    with open(file_path, "r") as file:
        for line in file:
            if "definitely lost" in line or "ERROR SUMMARY" in line or "invalid read" in line:
                print(Fore.RED + line.strip())
            elif "suppressed" in line or "still reachable" in line:
                print(Fore.YELLOW + line.strip())
            elif "HEAP SUMMARY" in line or "total heap usage" in line:
                print(Fore.CYAN + line.strip())
            else:
                print(Fore.WHITE + line.strip())
