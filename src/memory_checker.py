import subprocess
import os

def run_valgrind_wsl(file_path):
    linux_path = file_path.replace("C:\\", "/mnt/c/").replace("\\", "/").replace(" ", "\\ ")

    # 1. Compile the file first
    exe_path = "./build/sample"
    os.makedirs("build", exist_ok=True)

    compile_cmd = f"g++ -g {linux_path} -o {exe_path}"
    subprocess.run(compile_cmd, shell=True)

    # 2. Run valgrind on the compiled binary
    valgrind_output = "reports/valgrind_report.txt"
    valgrind_cmd = f"valgrind --leak-check=full {exe_path}"

    with open(valgrind_output, "w") as outfile:
        subprocess.run(valgrind_cmd, shell=True, stdout=outfile, stderr=subprocess.STDOUT)
