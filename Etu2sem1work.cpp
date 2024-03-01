#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int ammountstudents;
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

void loadFromFile(vector<student_t>& students, const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        file >> ammountstudents;
        while (!file.eof()) {
            student_t newStudent;
            file >> newStudent.name;
            file >> newStudent.surname;
            file >> newStudent.patronymic;
            file >> newStudent.gender;
            file >> newStudent.group.number_of_group;
            file >> newStudent.group.id_of_student_in_group;

            for (int i = 0; i < 3; ++i) {
                file >> newStudent.grades.exam_grades[i];
            }

            for (int i = 0; i < 5; ++i) {
                file >> newStudent.grades.credit_grades[i];
            }

            students.push_back(newStudent);
        }

        file.close();
    }
    else {
        cerr << "Unable to open file for reading." << endl;
    }
}





void addStudent(vector<student_t>& students) {
    student_t newStudent;

    cout << "Enter student's name: ";
    cin >> newStudent.name;
    cout << "Enter student's surname: ";
    cin >> newStudent.surname;
    cout << "Enter student's patronymic: ";
    cin >> newStudent.patronymic;
    cout << "Enter student's gender (M/F): ";
    cin >> newStudent.gender;
    cout << "Enter student's group number: ";
    cin >> newStudent.group.number_of_group;
    cout << "Enter student's ID in group: ";
    cin >> newStudent.group.id_of_student_in_group;

    cout << "Enter student's exam grades (3 grades separated by spaces): ";
    for (int i = 0; i < 3; ++i) {
        cin >> newStudent.grades.exam_grades[i];
    }

    cout << "Enter student's credit grades (5 grades separated by spaces): ";
    for (int i = 0; i < 5; ++i) {
        cin >> newStudent.grades.credit_grades[i];
    }

    students.push_back(newStudent);
    cout << "New student added successfully." << endl;
    ammountstudents +=1;

}

void saveToFile(const vector<student_t>& students, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        file<< ammountstudents<< "\n";
        for (const student_t& student : students) {
            file << student.name << "\n";
            file << student.surname << "\n";
            file << student.patronymic << "\n";
            file << student.gender << "\n";
            file << student.group.number_of_group << "\n";
            file << student.group.id_of_student_in_group << "\n";

            for (int grade : student.grades.exam_grades) {
                file << grade << " ";
            }
            file << "\n";

            for (int grade : student.grades.credit_grades) {
                file << grade << " ";
            }
            file << "\n";
        }

        file.close();
        cout << "Data saved to file." << endl;
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }
}

void displayStudents(const vector<student_t>& students) {
    for (const student_t& student : students) {
        cout << "Name: " << student.name << endl;
        cout << "Surname: " << student.surname << endl;
        cout << "Patronymic: " << student.patronymic << endl;
        cout << "Gender: " << student.gender << endl;
        cout << "Group number: " << student.group.number_of_group << endl;
        cout << "ID in group: " << student.group.id_of_student_in_group << endl;

        cout << "Exam grades: ";
        for (int grade : student.grades.exam_grades) {
            cout << grade << " ";
        }
        cout << endl;

        cout << "Credit grades: ";
        for (int grade : student.grades.credit_grades) {
            cout << grade << " ";
        }
        cout << endl;

        cout << "-" << endl;
    }
}



int main() {
    int ammountstudents = 0;
    vector<student_t> students;

    loadFromFile(students, "students_data.txt");
    if (ammountstudents == 0) {
        addStudent(students);
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
            addStudent(students);
            break;
        case 2:
            // Implement edit functionality
            break;
        case 3:
            displayStudents(students);
            break;
        case 4:
            saveToFile(students, "students_data.txt");
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}