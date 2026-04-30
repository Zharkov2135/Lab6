#include <iostream>
using namespace std;

long long absll(long long x) {
    return (x < 0) ? -x : x;
}

long long gcd_ll(long long a, long long b) {
    a = absll(a);
    b = absll(b);
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return (a == 0 ? 1 : a);
}

class Fraction {
private:
    long long num; // chyselnyk
    long long den; // znamennyk

    void normalize() {
        if (den == 0) {
            cout << "Pomylka: znamennyk ne mozhe dorivniuvaty 0. Vstanovleno 1.\n";
            den = 1;
        }
        if (den < 0) { // znak u chyselnyk
            den = -den;
            num = -num;
        }
        long long g = gcd_ll(num, den);
        num /= g;
        den /= g;
    }

public:
    // Konstruktor bez parametriv
    Fraction() : num(0), den(1) {}

    // Parametryzovanyi konstruktor
    Fraction(long long n, long long d) : num(n), den(d) {
        normalize();
    }

    // Destruktor
    ~Fraction() {
        cout << "Destruktor: obiekt Fraction znyshcheno (" << num << "/" << den << ")\n";
    }

    void input() {
        cout << "Vvedit chyselnyk: ";
        cin >> num;
        cout << "Vvedit znamennyk: ";
        cin >> den;
        normalize();
    }

    void print() const {
        cout << num << "/" << den;
    }

    double value() const {
        return (double)num / (double)den;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(num * other.den - other.num * den, den * other.den);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(num * other.num, den * other.den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.num == 0) {
            cout << "Pomylka: dilennia na nul nemozhlyve.\n";
            return Fraction(0, 1);
        }
        return Fraction(num * other.den, den * other.num);
    }
};

int main() {
    Fraction a;        // za zamovchuvanniam
    Fraction b;        // vvid z klaviatury
    Fraction c(3, 4);  // parametryzovanyi

    cout << "Drib a (za zamovchuvanniam) = ";
    a.print();
    cout << ", znachennia = " << a.value() << "\n\n";

    cout << "Vvedennia drobu b:\n";
    b.input();

    cout << "\nDrib b = ";
    b.print();
    cout << ", znachennia = " << b.value() << "\n";

    cout << "Drib c (3/4) = ";
    c.print();
    cout << ", znachennia = " << c.value() << "\n\n";

    Fraction sum = b + c;
    Fraction dif = b - c;
    Fraction mul = b * c;
    Fraction div = b / c;

    cout << "b + c = "; sum.print(); cout << " (znachennia = " << sum.value() << ")\n";
    cout << "b - c = "; dif.print(); cout << " (znachennia = " << dif.value() << ")\n";
    cout << "b * c = "; mul.print(); cout << " (znachennia = " << mul.value() << ")\n";
    cout << "b / c = "; div.print(); cout << " (znachennia = " << div.value() << ")\n";

    return 0;
}
