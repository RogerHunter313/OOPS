#include <iostream>
#include <cstring>
using namespace std;

class Student {
    int age;

public:
    char *name;
                        // parameter below is student s = main.s1 is being called using copy constructor but the inbuilt
                        // one is gone due to the parameterized copy constructor being built
                        // an infinite loop could be called because our copy constructor needs a copy constructor
                        // for its argument. now we have Student const &s = main.s1
    Student(Student const &s) { //if we want a deep copy constructor, we must make a parameterized one
        this->age = s.age;    // because the default will be a shallow copy
        this->name = new char[strlen(s.name)+1];
        strcpy(this->name, s.name);
    }
    Student(int age, char *name) {
        this->age = age;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    void display() {
        cout << name << " " << age << endl;
    }

};

int main() {
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();

    Student s2(s1);  // copy constructor called which
                     // is a shallow copy made by inbuilt copy constructor
                     // just the pointers in s1 are copied to s2
    s2.name[0] = 'x';
    s1.display();
    s2.display();
}
