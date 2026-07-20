# CGPA Calculator (C++)

A console-based C++ program that calculates semester GPA and overall CGPA from course grades and credit hours.

## Features
- Input any number of courses with name, letter grade, and credit hours
- Converts letter grades (A, A-, B+, ... F) to grade points on a 4.0 scale
- Calculates total credits and total grade points (grade × credit hours)
- Computes semester GPA, and optionally combines it with a previous CGPA to produce the overall CGPA
- Displays a clean, formatted result table
- Input validation for grades, credit hours, and course count

## How It Works
1. The user enters the number of courses.
2. For each course, the program reads the name, letter grade, and credit hours.
3. `gradeToPoints()` maps the letter grade to a 4.0-scale value.
4. Grade points for a course = grade value × credit hours.
5. Semester GPA = total grade points ÷ total credits.
6. If a previous CGPA and its credit hours are provided, the overall CGPA is the credit-weighted average of old and new grade points.

## Build & Run
```bash
g++ main.cpp -o cgpa
./cgpa        # cgpa.exe on Windows
```

## Example Output
```
Course              Grade   Credits   Grade Points
------------------------------------------
Math                A       3.00      12.00
Physics             B+      4.00      13.20
------------------------------------------
Total Credits      : 7.00
Total Grade Points : 25.20
Semester GPA       : 3.60
Overall CGPA       : 3.60
```

## Concepts Used
Structs, `std::vector`, functions, input validation, formatted output with `<iomanip>`
