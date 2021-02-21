#include <iostream>
using namespace std;

class Student {

    // private:  //classes are default to private
        int age;

    public:
        // remember the default constructor will not exist if there are
        // parameterized constructor(s).
        Student () {
            cout << "constructor called" << endl;
        }

        // parameterized constructor
        Student (int r) {
            cout << "Constructor two called" << endl;
            rollNumber = rollNumber;
        }

        Student(int age, int rollNumber) {
            cout << endl << "Constructor 3 called" << endl;
            cout <<"this " << this << endl;  //pointer to object
            this->age =age;
            this->rollNumber = rollNumber;
        }

        int rollNumber;

        void display() {
            cout << age << " " << rollNumber << endl;
        }

    int getAge() {
        return age;
    }

    void setAge(int a, int password) {
        if (password != 123) {
            return;
        }
        if(a<0) {
            return;
        }

        age = a;
    }
    ~Student() { //our destructor will be called
        cout << "Deconstructor called " << endl;
    }

};
