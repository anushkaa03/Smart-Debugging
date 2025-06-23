import subprocess
import os

def run_cppcheck(file_path):
    output_file = "reports/cppcheck_report.txt"

    # Convert to Linux path if needed
    linux_path = file_path.replace("C:\\", "/mnt/c/").replace("\\", "/")

    # Escape space in path
    linux_path = linux_path.replace(" ", "\\ ")

    command = f"cppcheck {linux_path} --enable=all --inconclusive --std=c++11 2> {output_file}"

    subprocess.run(command, shell=True)
