#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator, int denominator) {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        void print() {
            cout << numerator << " / "  << denominator << endl;
        }
        void add(Fraction const &f2) { // passing an object. pass it as a reference to avoid copy constructor
                                        // also have it const so this object, f1 and change the data members of f2
            int lcd = this->denominator*f2.denominator;  // "this" is the created object, f1
            int x = lcd / denominator;  // don't really need a this operator
            int y = lcd/ f2.denominator;

            cout << (numerator*x) + (f2.numerator*y) << " / " << lcd << endl;
            simplify();  // it's already in the object
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
            cout << numerator << " / " << denominator << endl;
        }



};

int main() {

    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f2.add(f1);

    return 0;
}
