#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction() { //default constructor

        }

        Fraction(int n, int d) : numerator(n), denominator(d) {

        }

        int getNumerator() const {  //won't work without const for a const object
            return numerator;
        }

        int getDenominator() const {
            return denominator;
        }

        void setNumerator(int n) {
            numerator =n;
        }

        void setDenominator(int d) {
            denominator = d;
        }

        void print() {
            cout << numerator << " / "  << denominator << endl;
        }
        Fraction add(Fraction const &f2) const { // passing an object. pass it as a reference to avoid copy constructor
                                        // also have it const so this object, f1 and change the data members of f2
            int lcd = this->denominator*f2.denominator;  // "this" is the created object, f1
            int x = lcd / denominator;  // don't really need a this operator
            int y = lcd/ f2.denominator;

            int num = (numerator*x) + (f2.numerator*y);

            Fraction fnew (num, lcd);  //parameterized constructor
            fnew.simplify();  // it's already in the object
            return fnew;
        }

        Fraction operator+(Fraction const &f2) const { // overloads + operator to do this function
            int lcd = this->denominator*f2.denominator;  // "this" is the created object, f1
            int x = lcd / denominator;  // don't really need a this operator
            int y = lcd/ f2.denominator;

            int num = (numerator*x) + (f2.numerator*y);

            Fraction fnew (num, lcd);  //parameterized constructor
            fnew.simplify();  // it's already in the object
            return fnew;
        }

        void simplify() {
            int gcd = -1;
            int j = min(this->numerator, this->denominator); // this is optional
            for (int i = 1; i<=j; i++) {
                if (numerator%i == 0 && denominator%i == 0) {
                    gcd = i;
                }
            }
            // an inbuilt function for gcd = __gcd(a,b);  two underscores
            // simplify
            numerator = numerator/gcd;
            denominator = denominator/gcd;
          //  cout << numerator << " / " << denominator << endl;
        }

        Fraction operator*(Fraction const &f2) const { //the whole function is const since it's not changing anything in the object
            int n = numerator * f2.numerator;
            int d = denominator * f2.denominator;

            Fraction fnew(n, d);
            fnew.simplify();
            return fnew;
        }

        bool operator==(Fraction const &f2) const {
            return (numerator == f2.numerator && denominator == f2.denominator);
        }



};

int main() {

    Fraction f1(10, 2);
    Fraction f2(15, 4);
    Fraction f3 = f1.add(f2);
    Fraction f4 = f1 + f2;

    f1.print();
    f2.print();
    f3.print();
    f4.print();

    Fraction f5 = f1 * f2;
    f5.print();

    if(f1==f2) {
        cout << "equal" << endl;
    }else {
        cout << "Not equal" << endl;
    }


    return 0;
}
