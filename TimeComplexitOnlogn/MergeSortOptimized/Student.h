#ifndef ALGORITHMSTUDY_STUDENT_H
#define ALGORITHMSTUDY_STUDENT_H


#include <iostream>
#include <algorithm>

using namespace :: std;

struct Student{
    string name;
    int score;

    bool operator>(const Student &otherstudent){
        return score > otherstudent.score;
    }
    friend ostream& operator<<(ostream &os, const Student &student){
        os << "Student:" << student.name <<"Score:"<< student.score << endl;
        return os;
    }
};

#endif
