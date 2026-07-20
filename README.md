# CodeAlpha_CGPACalculator

**CodeAlpha C++ Internship — Task 1: CGPA Calculator**

A console-based C++ program that calculates semester GPA and overall CGPA.

## Features
- Input any number of courses with name, letter grade, and credit hours
- Converts letter grades (A, B+, C-, etc.) to grade points on a 4.0 scale
- Calculates total credits and total grade points (grade × credit hours)
- Computes semester GPA and combines with previous CGPA for overall CGPA
- Displays a clean, formatted result table
- Input validation for grades, credits, and course count

## How to Run
```bash
g++ main.cpp -o cgpa
./cgpa        # (cgpa.exe on Windows)
```

## Example Output
```
Course              Grade   Credits   Grade Points
------------------------------------------
Math                A       3.00      12.00
Physics             B+      4.00      13.20
------------------------------------------
Semester GPA       : 3.60
Overall CGPA       : 3.60
```

## Concepts Used
Structs, vectors, functions, input validation, formatted output (iomanip)
