import math
import pprint
import copy
import time

from numpy import var
from sympy import variations

def string2array(string) -> list:
    report = []
    for element in string.strip().split(" "):
        report.append(int(element))

    return report

def test1a(report):
    valid = True
    for i in range(len(report) - 1):
        if report[i] >= report[i + 1]:
            valid = False
            break
    
    return valid

def test1b(report):
    valid = True
    for i in range(len(report) - 1):
        if report[i] <= report[i + 1]:
            valid = False
            break
    
    return valid

def test2(report):
    valid = True
    for i in range(len(report) - 1):
        if abs(report[i] - report[i + 1]) > 3:
            valid = False
            break

    return valid

def is_safe(report) -> bool:
    return (test1a(report) or test1b(report)) and test2(report)

def remove_unsafe(report):
    variations = []

    for i in range(len(report)):
        report_copy = copy.deepcopy(report)
        report_copy.pop(i)
        variations.append(report_copy)

    for variation in variations:
        if is_safe(variation):
            return variation
        
    return report

def main():
    start = time.time();
    reports = [[]]

    with open("02/input.txt", "r") as f:
        for line in f:
            reports[-1].append(string2array(line))

    count = 0
    for report in reports[0]:
        if is_safe(remove_unsafe(report)):
            count += 1

    duration = (time.time() - start) * 1000
    print(f"Valid reports: {count} ({round(duration, 1)} ms)")
    

if __name__ == "__main__":
    main()