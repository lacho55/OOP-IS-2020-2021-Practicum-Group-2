
#ifndef STRUCTURES_STUDENTS_H
#define STRUCTURES_STUDENTS_H

#include <iostream>

using namespace std;

const size_t MAX_NAME_LENGTH = 64;
const size_t EGN_STRING_LENGTH = 11;
const size_t MARKS_COUNT = 5;

struct Student
{
    char name[MAX_NAME_LENGTH];
    char egn[EGN_STRING_LENGTH]; //заради това, че може да започва с една или повече нули, избираме низ вместо цяло число (int)
    int facultyNumber;
    float marks[MARKS_COUNT];
};

void initialize(Student& s)
{
    cin.getline(s.name,MAX_NAME_LENGTH);
    cin.getline(s.egn, EGN_STRING_LENGTH);
    cin >> s.facultyNumber;
    for(size_t i = 0; i < MARKS_COUNT; ++i)
    {
        cin >> s.marks[i];
    }
}

void print(const Student& s)
{
    cout << "Name : " << s.name << endl;
    cout << "EGN : " << s.egn << endl;
    cout << "Faculty Number : " << s.facultyNumber << endl;

    cout << "Marks : ";

    for(size_t i = 0; i < MARKS_COUNT; ++i)
    {
        cout << s.marks[i] << ' ';
    }

    cout << endl;
}

float averageMark(const Student& s)
{
    float sum = 0;
    for(size_t i = 0; i < MARKS_COUNT; ++i)
    {
        sum += s.marks[i];
    }

    return sum / (float)MARKS_COUNT;
}

void printAverageMarks(Student* students, size_t count)
{
    cout << "Average Marks :" << endl;

    for(size_t i = 0; i < count; ++i)
    {
        cout << averageMark(students[i]) << endl;
    }
}

Student& getBestStudent(Student* students, size_t count)
{
    size_t currentBestStudentIndex = 0;
    float currentHighestAverageMark = averageMark(students[0]);

    for(size_t i = 1; i < count; ++i)
    {
        float currentAverageMark = averageMark(students[i]);

        if(currentAverageMark > currentHighestAverageMark)
        {
            currentHighestAverageMark = currentAverageMark;
            currentBestStudentIndex = i;
        }
    }

    return students[currentBestStudentIndex];
}

int main()
{
    const int studentsCount = 2;
    Student students[studentsCount];

    for(size_t i = 0; i < studentsCount; ++i)
    {
        initialize(students[i]);
        cin.get(); //прочитаме новия ред след последното въведено поле, в противен случай той ще бъде прочетен от следващия getline, вместо реално въведения низ за име
    }

    for(size_t i = 0; i < studentsCount; ++i)
    {
        print(students[i]);
    }

    printAverageMarks(students, studentsCount);

    Student& bestStudent = getBestStudent(students, studentsCount);

    print(bestStudent);

    return 0;
}


#endif //STRUCTURES_STUDENTS_H
