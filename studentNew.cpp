#include <iostream>
#include "student.cpp"
using namespace std;

int main() {
    Student s1;
    Student *s2 = new Student;

    s1.setAge(20, 123);
    s2->setAge(30, 124); //wrong password

    s1.display();
    s2->display();

    Student s4(10);
    s4.display();

    Student *s5 = new Student(2);
    s5->display();

    Student s6(10, 100);
    s6.display();

    Student s7(12, 99);
    cout << "Address of s7 " << &s7 << endl;

    Student s8(20, 200);
    cout << "Address of s8 " << &s8 << endl;

    return 0;
}
