#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct {
    int number_of_group;
    int id_of_student_in_group;
} group_t;

typedef struct {
    int group_list_number;
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

void saveToFile(const student_t& student, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        file << student.name << "\n";
        file << student.surname << "\n";
        file << student.patronymic << "\n";
        file << student.gender << "\n";
        file << student.group.number_of_group << "\n";
        file << student.group.id_of_student_in_group << "\n";
        file << student.grades.group_list_number << "\n";

        for (int grade : student.grades.exam_grades) {
            file << grade << " ";
        }
        file << "\n";

        for (int grade : student.grades.credit_grades) {
            file << grade << " ";
        }
        file << "\n";

        file.close();
        cout << "Data saved to file." << endl;
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }
}

int main() {
    int ammountofstudents = 1;
    student_t student = { "Alice", "Smith", "Ann", 'F', {123, 1}, {456, {90, 85, 88}, {75, 80, 70, 85, 90}} };
    saveToFile(student, "student_data.txt");
    student_t student1 = { "OLEG", "ZOPA", "Ann", 'F', {123, 1}, {456, {90, 85, 88}, {75, 80, 70, 85, 90}} };
    saveToFile(student, "student_data.txt");
    return 0;
}