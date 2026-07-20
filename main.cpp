

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

// Convert a letter grade to grade points (4.0 scale)
double gradeToPoints(string grade) {
    for (auto &c : grade) c = toupper(c);
    if (grade == "A" || grade == "A+") return 4.0;
    if (grade == "A-") return 3.7;
    if (grade == "B+") return 3.3;
    if (grade == "B")  return 3.0;
    if (grade == "B-") return 2.7;
    if (grade == "C+") return 2.3;
    if (grade == "C")  return 2.0;
    if (grade == "C-") return 1.7;
    if (grade == "D+") return 1.3;
    if (grade == "D")  return 1.0;
    if (grade == "F")  return 0.0;
    return -1.0; // invalid
}

struct Course {
    string name;
    string grade;
    double creditHours;
    double gradePoints; // grade value * credit hours
};

int main() {
    cout << "==========================================\n";
    cout << "        CGPA CALCULATOR - CodeAlpha       \n";
    cout << "==========================================\n\n";

    int numCourses;
    cout << "Enter the number of courses this semester: ";
    while (!(cin >> numCourses) || numCourses <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Please enter a valid positive number: ";
    }
    cin.ignore(); // clear newline

    vector<Course> courses;
    double totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < numCourses; i++) {
        Course c;
        cout << "\n--- Course " << (i + 1) << " ---\n";

        cout << "Course name: ";
        getline(cin, c.name);

        double points = -1;
        while (points < 0) {
            cout << "Grade (A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
            cin >> c.grade;
            points = gradeToPoints(c.grade);
            if (points < 0) cout << "Invalid grade, try again.\n";
        }

        cout << "Credit hours: ";
        while (!(cin >> c.creditHours) || c.creditHours <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter valid credit hours: ";
        }
        cin.ignore();

        c.gradePoints = points * c.creditHours;
        totalCredits += c.creditHours;
        totalGradePoints += c.gradePoints;
        courses.push_back(c);
    }

    double semesterGPA = totalGradePoints / totalCredits;

    // Optional: previous CGPA for overall CGPA calculation
    char hasPrevious;
    double prevCGPA = 0, prevCredits = 0;
    cout << "\nDo you have a previous CGPA to include? (y/n): ";
    cin >> hasPrevious;
    if (hasPrevious == 'y' || hasPrevious == 'Y') {
        cout << "Enter previous CGPA: ";
        cin >> prevCGPA;
        cout << "Enter total previous credit hours: ";
        cin >> prevCredits;
    }

    double overallCGPA;
    if (prevCredits > 0)
        overallCGPA = (prevCGPA * prevCredits + totalGradePoints) / (prevCredits + totalCredits);
    else
        overallCGPA = semesterGPA;

    // Display results
    cout << fixed << setprecision(2);
    cout << "\n==========================================\n";
    cout << "               RESULT SUMMARY              \n";
    cout << "==========================================\n";
    cout << left << setw(20) << "Course" << setw(8) << "Grade"
         << setw(10) << "Credits" << "Grade Points\n";
    cout << "------------------------------------------\n";
    for (auto &c : courses) {
        cout << left << setw(20) << c.name << setw(8) << c.grade
             << setw(10) << c.creditHours << c.gradePoints << "\n";
    }
    cout << "------------------------------------------\n";
    cout << "Total Credits      : " << totalCredits << "\n";
    cout << "Total Grade Points : " << totalGradePoints << "\n";
    cout << "Semester GPA       : " << semesterGPA << "\n";
    cout << "Overall CGPA       : " << overallCGPA << "\n";
    cout << "==========================================\n";

    return 0;
}
