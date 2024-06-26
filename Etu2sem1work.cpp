﻿#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
using namespace std;

struct group_t {
    int number_of_group;
    int id_of_student_in_group;
};

struct grades_t {
    int exam_grades[3];
    int credit_grades[5];
};


struct dormitory_t {
    bool out_of_city;
    int fam_money;
};

struct student_t
{
    string name;
    string surname;
    string patronymic;
    char gender;
    group_t group;
    grades_t grades;
    dormitory_t dormitory;
};




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
            file >> students[studentcount].dormitory.out_of_city;
            file >> students[studentcount].dormitory.fam_money;
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
    while(students[ammountstudents].gender != 'M' && students[ammountstudents].gender != 'F') {
        cout << "\nUse W or F!!! " << endl;
        cin >> students[ammountstudents].gender;
    }

    cout << "Enter the group number of the new student: ";
    int numbergroup;
    cin >> numbergroup;
    students[ammountstudents].group.number_of_group = numbergroup;
    cout << "Enter the ID in group of the new student: ";
    int idingroup;
    cin >> idingroup;
    students[ammountstudents].group.id_of_student_in_group = idingroup;
    bool groupavab==0;
    while (!groupavab) {
        cout << "Enter the group number of the new student: ";
        cin >> numbergroup;
        students[ammountstudents].group.number_of_group = numbergroup;
        cout << "Enter the ID in group of the new student: ";
        cin >> idingroup;
        students[ammountstudents].group.id_of_student_in_group = idingroup;
        for (int id = 0; id < ammountstudents - 1; id++) {
            if ((students[id].group.number_of_group = numbergroup) && (students[id].group.id_of_student_in_group == idingroup)) {
                groupavab = false;
            }
            else {
                groupavab = true;
            }
        }
    }
    cout << "Enter exam grades for the new student (3 grades in one enter): ";
    for (int i = 0; i < 3; ++i) {
        cin >> students[ammountstudents].grades.exam_grades[i];
    }

    cout << "Enter credit grades for the new student (5 grades in one enter): ";
    for (int i = 0; i < 5; ++i) {
        cin >> students[ammountstudents].grades.credit_grades[i];
    }

    cout << "Enter nonresident? 1-Yes 0-No : ";
    cin >> students[ammountstudents].dormitory.out_of_city;
    cout << "Family income : ";
    cin >> students[ammountstudents].dormitory.fam_money;


    ammountstudents += 1;
}
void editStudents(student_t* students, int ammountstudents) {
    int groupOfStudentForChange;
    int numberInGroupOfStudentForChange;
    int studentcount;
    cout << "Choose group of student"<< endl;
    cin >> groupOfStudentForChange;
    cout << "Choose id in group of student"<< endl;
    cin >> numberInGroupOfStudentForChange;
    for (studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
        if ((students[studentcount].group.number_of_group == groupOfStudentForChange) & (students[studentcount].group.id_of_student_in_group == numberInGroupOfStudentForChange)) {
            break;
        }
    }
    int choiceEdit;
    if (studentcount == ammountstudents) {
        cout << "This student not found"<< endl;
        choiceEdit = 10;
    }
    else {
        cout << "You choosed student " << students[studentcount].name << " " << students[studentcount].surname << endl;
    }
    Sleep(150);
    do {
        cout << "What you want to change?" << endl;
        cout << "Choose an action:" << endl;
        cout << "1. Change name" << endl;
        cout << "2. Change surname" << endl;
        cout << "3. Change patronymic" << endl;
        cout << "4. Change gender" << endl;
        cout << "5. Change group" << endl;
        cout << "6. Change id in group" << endl;
        cout << "7. Enter new exam grades" << endl;
        cout << "8. Enter new credit grades" << endl;
        cout << "9. Change resident" << endl;
        cout << "10. Change family income" << endl;
        cout << "11. Exit" << endl;
    
        cin >> choiceEdit;
        switch (choiceEdit) {
        case 1: {
            cout << "Enter new name" << endl;
            string newinfo;
            cin >> newinfo;
            students[studentcount].name = newinfo;
            break;
        }
        case 2: {
            cout << "Enter new surname" << endl;
            string newinfo;
            cin >> newinfo;
            students[studentcount].surname = newinfo;
            break;
        }
        case 3: {
            cout << "Enter new patronymic" << endl;
            string newinfo;
            cin >> newinfo;
            students[studentcount].patronymic = newinfo;
            break;
        }
        case 4: {
            char nothing;
            cout << "Enter new gender" << endl;
            cin >> nothing;
            cout << "This feature is not available in your country" << endl;
            break;
        }
        case 5: {
            cout << "Enter new group id" << endl;
            int newinfo;
            cin >> newinfo;
            students[studentcount].group.number_of_group = newinfo;
            break;
        }
        case 6: {
            cout << "Enter new id in group" << endl;
            int newinfo;
            cin >> newinfo;
            students[studentcount].group.id_of_student_in_group = newinfo;
            break;
        }
        case 7: {
            cout << "Enter new exam grades(one grade and press enter 3 times)" << endl;
            int newinfo;
            for (int i = 0; i < 3; ++i) {
                cin>>newinfo;
                students[studentcount].grades.exam_grades[i] = newinfo;
            }
            break;
        }
        case 8: {
            cout << "Enter new credit grades(one grade and press enter 5 times)" << endl;
            int newinfo;
            for (int i = 0; i < 5; ++i) {
                cin >> newinfo;
                students[studentcount].grades.credit_grades[i] = newinfo;
            }
            break;
        }


        case 9: {
            cout << "Enter 1 - yes or 0 - no" << endl;
            bool newinfo;
            cin >> newinfo;
            students[studentcount].dormitory.out_of_city = newinfo;
            break;
        }
        case 10: {
            cout << "Enter new family income" << endl;
            int newinfo;
            cin >> newinfo;
            students[studentcount].dormitory.fam_money = newinfo;
            break;
        }




        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choiceEdit != 11);
}
void displayStudents(const student_t* students, int ammountstudents) {
    

        for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
            cout << "Name: " << students[studentcount].name << endl;
            cout << "Surname: " << students[studentcount].surname << endl;
            cout << "Patronymic: " << students[studentcount].patronymic << endl;
            cout << "Gender: " << students[studentcount].gender << endl;
            cout << "Group number: " << students[studentcount].group.number_of_group << endl;
            cout << "ID in group: " << students[studentcount].group.id_of_student_in_group << endl;
            cout << "Non-res student? 1 - yes 0 - no : " << students[studentcount].dormitory.out_of_city << endl;
            cout << "Fam money: " << students[studentcount].dormitory.fam_money << endl;
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
            file << students[studentcount].dormitory.out_of_city << "\n";
            file << students[studentcount].dormitory.fam_money << "\n";

        }

        file.close();
    }
    else {
        cerr << "Unable to open file for reading." << endl;
    }
}
void studOutOfNumber(const student_t* students, int ammountstudents) {
    int idOfStudentForSearch;
    cout << "Choose id in group of student" << endl;
    cin >> idOfStudentForSearch;
    for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
        if (students[studentcount].group.id_of_student_in_group == idOfStudentForSearch) {
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
                cout << students[studentcount].grades.credit_grades[i] << " ";
            }
            cout << "\n\n\n";

        }
    }

}
void infoAboutOneStudent(const student_t* students, int ammountstudents) {
    int groupOfStudentForSearch;
    int numberInGroupOfStudentForSearch;
    int studentcount;
    cout << "Choose group of student" << endl;
    cin >> groupOfStudentForSearch;
    cout << "Choose id in group of student" << endl;
    cin >> numberInGroupOfStudentForSearch;
    for (studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
        if ((students[studentcount].group.number_of_group == groupOfStudentForSearch) & (students[studentcount].group.id_of_student_in_group == numberInGroupOfStudentForSearch)) {
            break;
        }
    }
    cout << "Name: " << students[studentcount].name << endl;
    cout << "Surname: " << students[studentcount].surname << endl;
    cout << "Patronymic: " << students[studentcount].patronymic << endl;
    cout << "Gender: " << students[studentcount].gender << endl;
}
void studOutOfGroup(const student_t* students, int ammountstudents) {
    int groupOfStudentForSearch;
    cout << "Choose group of student" << endl;
    cin >> groupOfStudentForSearch;
    for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
        if (students[studentcount].group.number_of_group == groupOfStudentForSearch ) {
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
                cout << students[studentcount].grades.credit_grades[i] << " ";
            }
            cout <<"\n\n\n";

        }
    }

}
void sessionGrades(const student_t* students, int ammountstudents) {
    int countNoScholarship = 0;
    int countHaveFour = 0;
    int countOnlyFive = 0;
    int idOfStudTop[3] = { 0,1,2 };
    int summOfTop[3] = { 0 };

    for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
        bool noScholar = false;
        bool haveFour = false;
        int summ = 0;
        for (int i = 0; i < 3; i++) {
            summ += students[studentcount].grades.exam_grades[i];
            if (students[studentcount].grades.exam_grades[i] == 3) {
                noScholar = true;
            }
            if (students[studentcount].grades.exam_grades[i] == 4) {
                haveFour = true;
            }
        }

        for (int i = 0; i < 5; ++i) {
            summ += students[studentcount].grades.credit_grades[i];
            if (students[studentcount].grades.credit_grades[i] == 3) {
                noScholar = true;
            }
            if (students[studentcount].grades.credit_grades[i] == 4) {
                haveFour = true;
            }
        }
        if (noScholar == true) {
            countNoScholarship += 1;
        }

        if ((haveFour == true) && (noScholar == false)) {
            countHaveFour += 1;
        }

        if ((haveFour == false) && (noScholar == false)) {
            countOnlyFive += 1;
        }

        for (int i = 0; i < 3; i++) {
            if (summ > summOfTop[i]) {
                idOfStudTop[i] = studentcount;
                summOfTop[i] = summ;
                break;
            }
        }
    }

    cout << "List of top 3 students" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << students[idOfStudTop[i]].name << endl;
        cout << "Surname: " << students[idOfStudTop[i]].surname << endl << endl;
    }
    cout << "Total students with no scholarship = " << countNoScholarship << endl;
    cout << "Have four and five = " << countHaveFour << endl;
    cout << "Have only five = " << countOnlyFive << endl << endl;
}
void dorminatoryCHECK(const student_t* students, int ammountstudents) {

    int idOfStudTop[10] = { 0 };
    int summOfTop[10] = { 0 };
    int dormcount = 0;
    for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {

        if (students[studentcount].dormitory.out_of_city == true) {


            for (int i = 0; i < 10; i++) {
                if (students[studentcount].dormitory.fam_money > summOfTop[i]) {
                    idOfStudTop[i] = studentcount;
                    summOfTop[i] = students[studentcount].dormitory.fam_money;
                    dormcount += 1;
                    break;
                    
                }
            }
        }
    }
    if (dormcount != 0) {
        cout << "List of top students" << endl;
        for (int i = dormcount-1; i >-1; i--) {
            cout << "Name: " << students[idOfStudTop[i]].name << endl;
            cout << "Surname: " << students[idOfStudTop[i]].surname << endl << endl;
        }
    }
    else {
        cout << "There are no students in need of a dorminatory " << endl;
    }
}
void countGender(const student_t* students, int ammountstudents) {
    int countW=0;
    int countM=0;
    for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
        if (students[studentcount].gender == 'F') {
            countW += 1;

        }
        if (students[studentcount].gender == 'M') {
            countM += 1;

        }
    }
    cout << "We have " << countW << " womens and " << countM << " mans !" << endl;

}
void incomeCheck(const student_t* students, int ammountstudents) {
    int incomeSearch;
    cout << "Enter income " << endl;
    cin >> incomeSearch;
    for (int studentcount = 0; studentcount < ammountstudents; studentcount += 1) {
        if ((students[studentcount].dormitory.fam_money <incomeSearch) ) {
            cout << "Name: " << students[studentcount].name << endl;
            cout << "Surname: " << students[studentcount].surname << endl;
            cout << "Patronymic: " << students[studentcount].patronymic << endl;
            cout << "Gender: " << students[studentcount].gender << endl<< endl;
            
        }
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
        cout << "4. Display all students from group N" << endl;
        cout << "5. Display all students with number N" << endl;
        cout << "6. Display all info about ONE student" << endl; 
        cout << "7. Display session grades" << endl;
        cout << "8. Count woman and man" << endl;
        cout << "9. Dorm check" << endl;
        cout << "10. Minimal income check" << endl;
        cout << "11. Exit" << endl;
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
            studOutOfGroup(students, ammountstudents);
            break;
        case 5:
            studOutOfNumber(students, ammountstudents);
            break;
        case 6:
            infoAboutOneStudent(students, ammountstudents);
            break;
        case 7:
            sessionGrades(students, ammountstudents);
            break;
        case 8:
            countGender(students, ammountstudents);
            break;
        case 9:
            dorminatoryCHECK(students, ammountstudents); 
                break;
        case 10:
            incomeCheck(students, ammountstudents);
            break;
        case 11:
            saveToFile(students, ammountstudents, "studentsbase.txt");
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 11);

    return 0;
}