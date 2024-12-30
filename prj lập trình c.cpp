#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct Date {
    int month, day, year;
};

struct Student {
    char studentId[10];
    char classroomId[10];
    char name[20];
    struct Date date0fBirth;
    bool gender;
    char email[30];
    char phone[20];
    char password[20];
};

struct Classroom {
    char classroomId[10];
    char teacherId[10];
    char classroomName[10];
    struct Student student[];
};

struct Teacher {
    char teacherId[10];
    char classroomId[10];
    char Name[20];
    struct Date date0fBirth;
    bool gender;
    char Email[30];
    char Phone[20];
    char password[20];
    struct Classroom classroom[];
};
struct Student students[50]; 
//student
void addStudent();

void displayAllStudent();

void deleteStudent(char studentId[]);

void editStudent(char studentId[]);

void searchStudent(char studentId[]);

//teachers
void addTeacher();

void displayAllTeacher();

void deleteTeacher(char teacherId[]);

void editTeacher(char teacherId[]);

void searchTeacher(char teacherId[]);
int main(){
    int choice;
    char studentId[10];
    do {
        printf("\tSTUDENT MENU\n");
 	    printf("=======================\n");
        printf("[1] Add A New student.\n");
        printf("[2] Show All students.\n");
        printf("[3] Search A student.\n");
        printf("[4] Edit A student.\n");
        printf("[5] Delete A student.\n");
        printf("[0] Exit the program.\n");
	    printf("=======================\n");
        printf("Enter The Choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                break;
            }
            case 2: {
                displayAllStudent();
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 0: {
                break;
            }
            default: {
                printf("lựa chọn không hợp lí");
            }

        }
    } while (choice != 0);
}
int countStudents = 0;

void displayAllStudent() {
    printf("\n *** All students ***\n");
    if (countStudents == 0) {
        printf("no student \n");
        return;
    }
    for (int i = 0; i < countStudents; i++) {
        printf("%s %s %s %s", students[i].studentId, students[i].name, students[i].email, students[i].phone);
    }
}




void deleteStudent(char studentId[]) {
    printf("**** Delete a Student **** \n");
    if (countStudents == 0) {
        printf("There are no students");
        return;
    } else {
        int position = -1;
        for (int i = 0; i < countStudents; i++) {
            if (strcmp(studentId, students[i].studentId)) {
                position = i;
                break;
            }
        }
        struct Student newStudents[countStudents - 1];
        for (int i = 0; i < position; i++) {
            newStudents[i] = students[i];
        }
        for (int i = position + 1; i < countStudents; i++) {
            newStudents[i - 1] = students[i];
        }
        for (int i = 0; i < countStudents - 1; i++) {
            students[i] = newStudents[i];
        }
        countStudents--;
    }
}



void updateStudent(char studentId[]) {
    printf("**** Edit a Student **** \n");
    if (countStudents == 0) {
        printf("no student");
        return;
    } else {
        int position = -1;
        for (int i = 0; i <= countStudents; i++) {
            if (strcmp(studentId, students[i].studentId)) {
                position = i;
                break;
            }
        }

        //  hiển thị dữ liệu cũ của học sinh
        printf("%s \n %s \n %s", students[position].name, students[position].email, students[position].phone);
        printf("***Update The New Student ****");
        fgets(students[position].name, 50, stdin);
        fgets(students[position].email, 50, stdin);
        fgets(students[position].phone, 50, stdin);
        printf("Student updated successfully");
    }
}



void searchStudent(char studentId[]) {
    printf("Enter the student you are looking for");
    if (countStudents == 0) {
        printf("no student");
    } else {
        int position = -1;
        for (int i = 0; i < countStudents; i++) {
            if (strcmp(studentId, students[i].studentId)) {
                position = i;
                break;
            }

        }

        printf("%s \n %s \n %s \n %s", students[position].studentId, students[position].name, students[position].email,
               students[position].phone);
    }
}
