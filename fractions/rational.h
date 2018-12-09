// -----------------------------------------------------------------
// This class represents a fraction and is able to manipulate those
// fractions based on user choice
// ----------------------------------------------------------

class Rational {
    private:
        int numerator;
        int denominator;

        void euclid();
        void normalizeFraction(Rational);
    public:
        Rational(int num, int denom);
        Rational();
        void inputFraction();
        void displayFraction();
        void displayFloat();

        Rational add(Rational rhs);
        Rational operator+(Rational rhs);

        Rational subtract(Rational rhs);
        Rational operator-(Rational rhs);

        Rational multiply(Rational rhs);
        Rational operator*(Rational rhs);

        Rational divide(Rational rhs);
        Rational operator/(Rational rhs);

        bool operator<(Rational rhs);
        bool operator>(Rational rhs);
        bool operator==(Rational rhs);

        friend std::ostream& operator<<(std::ostream& os, Rational& rhs);
        friend std::istream& operator>>(std::istream& is, Rational& rhs);

        class ZeroDen{};
        class Alpha{};
};

