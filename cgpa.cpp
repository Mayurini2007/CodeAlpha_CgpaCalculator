#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Structure to store individual course details
struct Course {
    string name;
    double grade;
    double credits;
};

int main() {
    int numCourses;
    double totalPoints = 0.0;
    double totalCredits = 0.0;
    vector<Course> courses;

    cout << "==============================" << endl;
    cout << "   ADVANCED CGPA CALCULATOR   " << endl;
    cout << "==============================" << endl;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        Course temp;
        cout << "\n--- Course " << i + 1 << " ---" << endl;
        cout << "Course Name/Code: ";
        cin.ignore(); // Clears the buffer
        getline(cin, temp.name);
        
        cout << "Grade Point (0.0 - 4.0): ";
        cin >> temp.grade;
        
        cout << "Credit Hours: ";
        cin >> temp.credits;

        // Math for the totals
        totalPoints += (temp.grade * temp.credits);
        totalCredits += temp.credits;

        // Store course in our list
        courses.push_back(temp);
    }

    if (totalCredits == 0) {
        cout << "\nError: Total credits cannot be zero." << endl;
    } else {
        double gpa = totalPoints / totalCredits;

        // Display individual course summary
        cout << "\n\n========== COURSE SUMMARY ==========" << endl;
        cout << left << setw(15) << "Course" << setw(10) << "Grade" << "Credits" << endl;
        cout << "------------------------------------" << endl;
        
        for (const auto& c : courses) {
            cout << left << setw(15) << c.name 
                 << setw(10) << fixed << setprecision(2) << c.grade 
                 << c.credits << endl;
        }

        // Final CGPA Display
        cout << "====================================" << endl;
        cout << "Total Grade Points: " << totalPoints << endl;
        cout << "Total Credit Hours: " << totalCredits << endl;
        cout << "FINAL CGPA:         " << gpa << endl;
        cout << "====================================" << endl;
    }

    return 0;
}