#include <iostream>
#include "student.cpp"
using namespace std;

int main() {
    Student s1(10, 100);  // paramterized constructor
    cout << "S1 :";       // user defined with a cout
    s1.display();

    Student s2(s1);  // we are using the internal
    cout << "S2 :";  // copy constructor in which a cout
    s2.display();    // was not coded

    Student *s3 = new Student (20, 200);
    cout << "S3 :";
    s3->display();

    Student s4(*s3);  // need to dereference the pointer
    Student *s5 = new Student(*s3);
    Student *s6 = new Student(s1);  //s1 wasn't a pointer

    delete s3;
    delete s5;
    delete s6;

    return 0;

}
