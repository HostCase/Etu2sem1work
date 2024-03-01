#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

void saveToFile(const vector<student_t>& students, const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        for (const student_t& student : students) {
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
        }

        file.close();
        cout << "Data saved to file." << endl;
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }
}

vector<student_t> readFromFile(const string& filename) {
    ifstream file(filename);
    vector<student_t> students;
    student_t student;

    while (getline(file, student.name)) {
        getline(file, student.surname);
        getline(file, student.patronymic);
        file >> student.gender;
        file >> student.group.number_of_group;
        file >> student.group.id_of_student_in_group;
        file >> student.grades.group_list_number;

        for (int i = 0; i < 3; ++i) {
            file >> student.grades.exam_grades[i];
        }

        for (int i = 0; i < 5; ++i) {
            file >> student.grades.credit_grades[i];
        }

        students.push_back(student);
    }

    file.close();
    cout << "Data read from file." << endl;

    return students;
}

int main() {
    vector<student_t> students = {
        {"Alice", "Smith", "Ann", 'F', {123, 1}, {456, {90, 85, 88}, {75, 80, 70, 85, 90}}},
        {"Bob", "Johnson", "William", 'M', {124, 2}, {457, {85, 82, 89}, {70, 75, 65, 80, 85}}}
    };

    saveToFile(students, "students_data.txt");

    vector<student_t> loadedStudents = readFromFile("students_data.txt");

    // Вывод данных всех студентов на экран
    for (const student_t& student : loadedStudents) {
        cout << "Name: " << student.name << "\n";
        cout << "Surname: " << student.surname << "\n";
        cout << "Patronymic: " << student.patronymic << "\n";
        cout << "Gender: " << student.gender << "\n";
        cout << "Group Number: " << student.group.number_of_group << "\n";
        cout << "Student ID in Group: " << student.group.id_of_student_in_group << "\n";
        cout << "Group List Number: " << student.grades.group_list_number << "\n";
        cout << "Exam Grades: ";
        for (int grade : student.grades.exam_grades) {
            cout << grade << " ";
        }
        cout << "\nCredit Grades: ";
        for (int grade : student.grades.credit_grades) {
            cout << grade << " ";
        }
        cout << endl;
        cout << "-" << endl;
    }

    return 0;
}