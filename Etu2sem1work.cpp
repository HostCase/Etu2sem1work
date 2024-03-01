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
int main(){
    int totalStudents=1;
    return 0;
}



