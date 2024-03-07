#include <iostream>
#include <fstream>
#include <string>

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

void loadFromFile(student_t* students, int& ammountstudents, const string& filename) {

}

void addStudent(student_t* students, int &ammountstudents) {

}

void editStudents(const student_t* students, int ammountstudents) {

}

void displayStudents(const student_t* students, int ammountstudents) {

}

void saveToFile(const student_t* students, int ammountstudents, const string& filename) {

}


int main() {
    int ammountstudents = 0;
    student_t *students = new student_t[ammountstudents];
    loadFromFile(students, ammountstudents, "students_data.txt");
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
            saveToFile(students, ammountstudents, "students_data.txt");
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}