#include <iostream>
#include <complex>
using namespace std;

class ComplexNumbers {
    private:
        int real;
        int imaginary;

    public:
        ComplexNumbers(int real, int imaginary){ //parameterized constructor
            this->real = real;
            this->imaginary = imaginary;
        }
        void print() {
            cout << real << " + " << imaginary << "i" <<endl;
        }
        void plus(ComplexNumbers const &c2) {
            real = real + c2.real;
            imaginary = imaginary + c2.imaginary;
        }
        void multiply(ComplexNumbers const &c2) {
            int temp = real; // keep the old real value in temp
            real = real*c2.real - imaginary*c2.imaginary; //PEMDAS
            imaginary = temp*c2.imaginary + imaginary*c2.real; // use temp
        }
};

int main() {
    complex<int> complexNumber1(3, 4);
    complex<int> complexNumber2(2, 5);

    cout << complexNumber1 << " + "
    << complexNumber2 << " = "
    << complexNumber1 + complexNumber2 << endl;

    cout << complexNumber1 << " * "
    << complexNumber2 << " = "
    << complexNumber1 * complexNumber2 << endl;
    //just kidding!

    //time to use FOIL
    int real1, imaginary1, real2, imaginary2;
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
}

