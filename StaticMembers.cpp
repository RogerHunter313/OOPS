#include <iostream>
using namespace std;

class Student {
    static int totalStudents;

    public:
        int rollNumber;
        int age;

        Student() {
            Student::totalStudents++;
        }

        int getRollNumber() {
            return rollNumber;
        }
        static int getTotalStudents() {
            return totalStudents;  // you'll have to call this in main with the scope
                                    // resolution operator
        }
};

int Student::totalStudents = 1;  // initialize static data members

int main() {
    Student s1;
    cout <<s1.rollNumber << " " << s1.age << endl;

    cout <<s1.totalStudents << endl;
    s1.totalStudents = 20;
    Student s2;
    cout << s2.totalStudents << endl;

    cout << Student::totalStudents << endl;

}
