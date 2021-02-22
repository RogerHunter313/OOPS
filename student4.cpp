#include <iostream>
using namespace std;

class Student {
    public:
        int age;
        const int rollNumber;
        int &x;  // age reference variable

        Student(int r, int a) : rollNumber(r), age(a), x(this->age){ // <-initialization list here avoids setting rollNumber to garbage
            //rollNumber = r;  // notice there is no int before rollNumber meaning rollNumber has already
                            // created with a garbage value
        }

};

int main() {
    Student s1(5, 50); //default constructor called trying to set a const int rollNumber to a garbage value
                // but if we want our object to have different const data memebers...use a constructor
                // with initialization list
    Student s2(3, 100);

    return 0;
}


