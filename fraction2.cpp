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

    Fraction f1(10, 5);
    Fraction f2(15, 4);

    Fraction const f3(3, 4);  // works after we create a default constructor
                        // compiler won't allow us to call any normal function through f3
                        // since it is a constant function.  f3 requires const functions
    cout << f3.getNumerator()<<" "<<f3.getDenominator(); //this will be alright

   // f3.setNumerator(10);  //this will cause an error.  can't change const f3
    return 0;

    return 0;
}
