#include <iostream>
#include <cstring>
using namespace std;

class Student {
    int age;
    char *name;

public:
    Student(int age, char *name) {
        this->age = age;
        this->name = new char[strlen(name)+1];  // allocates memory for char array + 1 for null char
        strcpy(this->name, name);  // copy the actual contents from the old char array to new one
        //this->name = name;   //shallow copy (copying only the address)
    }
    void display() {
        cout << name << " " << age << endl;
    }

};

int main() {
    //Student s1;  //can't use the default constructor
                //if a parameterized constructor is already created
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();
    name[3] = 'e';
    Student s2(30, name);
    s2.display();

    s1.display();
    return 0;
}
