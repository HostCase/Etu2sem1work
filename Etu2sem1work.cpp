#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;
typedef struct {
    int number_of_group;
    int id_of_student_in_group;
} group_t;

typedef struct {
    int exam_grades[3];
    int credit_grades[5];
} grades_t;

typedef struct {
    string name;
    string surname;
    string patronymic;
    char gender;
    group_t group;
    grades_t grades;
} student_t;

void loadFromFile(student_t* students, int& ammountstudents, const string& studentsbase) {
    ifstream file(studentsbase);
    if (file.is_open()) {
        file >> ammountstudents;
        for (int studentcount = 0; studentcount < ammountstudents;studentcount+=1) {
            file >> students[studentcount].name;
            file >> students[studentcount].surname;
            file >> students[studentcount].patronymic;
            file >> students[studentcount].gender;
            file >> students[studentcount].group.number_of_group;
            file >> students[studentcount].group.id_of_student_in_group;

            for (int i = 0; i < 3; ++i) {
                file >> students[studentcount].grades.exam_grades[i];
            }

            for (int i = 0; i < 5; ++i) {
                file >> students[studentcount].grades.credit_grades[i];
            }

        }

        file.close();
    }
    else {
        cerr << "Unable to open file for reading." << endl;
    }
}

void addStudent(student_t* students, int& ammountstudents) {

    cout << "Enter the name of the new student: ";
    cin >> students[ammountstudents].name;

    cout << "Enter the surname of the new student: ";
    cin >> students[ammountstudents].surname;

    cout << "Enter the patronymic of the new student: ";
    cin >> students[ammountstudents].patronymic;

    cout << "Enter the gender of the new student (M/F): ";
    cin >> students[ammountstudents].gender;

    cout << "Enter the group number of the new student: ";
    cin >> students[ammountstudents].group.number_of_group;

    cout << "Enter the ID in group of the new student: ";
    cin >> students[ammountstudents].group.id_of_student_in_group;

    cout << "Enter exam grades for the new student (3 grades): ";
    for (int i = 0; i < 3; ++i) {
        cin >> students[ammountstudents].grades.exam_grades[i];
    }

    cout << "Enter credit grades for the new student (5 grades): ";
    for (int i = 0; i < 5; ++i) {
        cin >> students[ammountstudents].grades.credit_grades[i];
    }
    ammountstudents += 1;
}
void editStudents(const student_t* students, int ammountstudents) {

}

void displayStudents(const student_t* students, int ammountstudents) {
    

        for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
            cout << "Name: " << students[studentcount].name << endl;
            cout << "Surname: " << students[studentcount].surname << endl;
            cout << "Patronymic: " << students[studentcount].patronymic << endl;
            cout << "Gender: " << students[studentcount].gender << endl;
            cout << "Group number: " << students[studentcount].group.number_of_group << endl;
            cout << "ID in group: " << students[studentcount].group.id_of_student_in_group << endl;



        cout << "Exam grades: ";
        for (int i = 0; i < 3; ++i) {
            cout << students[studentcount].grades.exam_grades[i] << " ";
        }
        cout << endl;


        cout << "Credit grades: ";
        for (int i = 0; i < 5; ++i) {
            cout << students[studentcount].grades.credit_grades[i]<<" ";
        }
        cout << endl;

        cout << "-" << endl;
        Sleep(150);
    }
}

void saveToFile(const student_t* students, int ammountstudents, const string& studentsbase) {
    ofstream file;
    file.open(studentsbase, ios::out);
    if (file.is_open()) {
        file << ammountstudents<< "\n";
        for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
            file << students[studentcount].name << "\n";
            file << students[studentcount].surname << "\n";
            file << students[studentcount].patronymic << "\n";
            file << students[studentcount].gender << "\n";
            file << students[studentcount].group.number_of_group << "\n";
            file << students[studentcount].group.id_of_student_in_group << "\n";

            for (int i = 0; i < 3; ++i) {
                file << students[studentcount].grades.exam_grades[i] << "\n";
            }

            for (int i = 0; i < 5; ++i) {
                file << students[studentcount].grades.credit_grades[i] << "\n";
            }

        }

        file.close();
    }
    else {
        cerr << "Unable to open file for reading." << endl;
    }
}


int main() {
    int ammountstudents = 0;
    student_t *students = new student_t[100000];
    loadFromFile(students, ammountstudents, "studentsbase.txt");
    if (ammountstudents == 0) {
        addStudent(students, ammountstudents);
    }
    int choice;
    do {
        cout << "Choose an action:" << endl;
        cout << "1. Create a new student record" << endl;
        cout << "2. Edit an existing student record" << endl;
        cout << "3. Display all student data" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students, ammountstudents);
            break;
        case 2:
            editStudents(students, ammountstudents);
            break;
        case 3:
            displayStudents(students, ammountstudents);
            break;
        case 4:
            saveToFile(students, ammountstudents, "studentsbase.txt");
            cout << "Exiting program." << endl;
            break; 
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}