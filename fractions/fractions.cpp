#include <iostream>
#include <iomanip>
#include <cmath>
#include "rational.h"

using namespace std;

//Overload Output Operator
ostream& operator<<(ostream& os, Rational& rhs) {
    Rational overload;

    os << rhs.numerator << "/" << rhs.denominator;

    return os;
}

//Overload Input Operator
istream& operator>>(istream& is, Rational& rhs) {
    Rational overload;
    char dummy;

    cout << "Input a Fraction in the format 'num/den': ";
    is >> rhs.numerator >> dummy >> rhs.denominator;

    if(!cin) {
        throw Rational::Alpha();
    };

    if(rhs.denominator == 0) {
        throw Rational::ZeroDen();
    };

    return is;
}

//Menu Display Prototype
void displayMenu();

//Input Fraction
void Rational::inputFraction() {
    char dummy;

    cout << "Input a Fraction in the format 'num/den':" << endl;
    cin >> numerator >> dummy >> denominator;

    while (denominator == 0) {
        cout << "Cannot accept a 0 denominator" << endl;
        cout << "Input a Fraction in the format 'num/den':" << endl;
        cin >> numerator >> dummy >> denominator;
    }
}

//Display Fraction
void Rational::displayFraction() {
    cout << numerator << "/" << denominator;
}

//Display Float
void Rational::displayFloat() {
    float floating = static_cast<float>(numerator) / static_cast<float>(denominator);
    cout <<  fixed << setprecision(3) << floating;
}

//Constructor
Rational::Rational(int num, int denom) {
    numerator = num;
    denominator = denom;
}

//Default
Rational::Rational() {
    numerator = 1;
    denominator = 1;
}

//Add
Rational Rational::add(Rational rhs) {
    Rational result;
    result.numerator = (numerator * rhs.denominator) + (denominator * rhs.numerator);
    result.denominator = denominator * rhs.denominator;

    if (result.numerator == 0 || result.denominator == 0) {
        result.normalizeFraction(result);
        return result;
    } else {
        result.normalizeFraction(result);
        result.euclid();
        return result;
    }
}

//Add Overload
Rational Rational::operator+(Rational rhs) {
    Rational result;
    result = add(rhs);
    return result;
}

//Subtract
Rational Rational::subtract(Rational rhs) {
    Rational result;
    result.numerator = (numerator * rhs.denominator) - (denominator * rhs.numerator);
    result.denominator = denominator * rhs.denominator;

    if (result.numerator == 0 || result.denominator == 0) {
        result.normalizeFraction(result);
        return result;
    } else {
        result.normalizeFraction(result);
        result.euclid();
        return result;
    }
}

//Subtract Overload
Rational Rational::operator-(Rational rhs) {
    Rational result;
    result = subtract(rhs);
    return result;
}

//Multiply
Rational Rational::multiply(Rational rhs) {
    Rational result;
    result.numerator = (numerator * rhs.numerator);
    result.denominator = (denominator * rhs.denominator);

    if (result.numerator == 0 || result.denominator == 0) {
        result.normalizeFraction(result);
        return result;
    } else {
        result.normalizeFraction(result);
        result.euclid();
        return result;
    }
}

//Multiply Overload
Rational Rational::operator*(Rational rhs) {
    Rational result;
    result = multiply(rhs);
    return result;
}

//Divide
Rational Rational::divide(Rational rhs) {
    Rational result;
    result.numerator = (numerator * rhs.denominator);
    result.denominator = (denominator * rhs.numerator);

    if (result.numerator == 0 || result.denominator == 0) {
        result.normalizeFraction(result);
        return result;
    } else {
        result.normalizeFraction(result);
        result.euclid();
        return result;
    }
}

//Divide Overload
Rational Rational::operator/(Rational rhs) {
    Rational result;
    result = divide(rhs);
    return result;
}

//Euclid
void Rational::euclid() {
    int a = abs(numerator);
    int b = abs(denominator);

    while(a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    numerator = numerator / a;
    denominator = denominator / b;
}

void Rational::normalizeFraction(Rational) {
    if(denominator < 0) {
        numerator *= (-1);
        denominator *= (-1);
    }
}

//Overload Less Than
bool Rational::operator<(Rational rhs) {
    if((static_cast<float>(numerator)/static_cast<float>(denominator)) < (static_cast<float>(rhs.numerator)/static_cast<float>(rhs.denominator))) {
        return true;
    } else {
        return false;
    }
}

//Overload Greater Than
bool Rational::operator>(Rational rhs) {
    if((static_cast<float>(numerator)/static_cast<float>(denominator)) > (static_cast<float>(rhs.numerator)/static_cast<float>(rhs.denominator))) {
        return true;
    } else {
        return false;
    }
}

//Overload Equal To
bool Rational::operator==(Rational rhs) {
    if((static_cast<float>(numerator)/static_cast<float>(denominator)) == (static_cast<float>(rhs.numerator)/static_cast<float>(rhs.denominator))) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char * argv[]) {

    //Add line for visual
    cout << endl;

    if (argc != 2) {
        cout << "Welcome to the Rational Program!" << endl << endl;
    }

    if (argc == 2) {
        cout << "Welcome to the Rational Program, " << argv[1] << "!" << endl << endl;
    }

    Rational r1, r2;
    Rational result;
    int choice = 0;

    do {
        displayMenu();

        //Read in the desired value
        cin >> choice;
        cout << endl;

        //Catch invalid user input
        while(!cin || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(50, '\n');
            cout << "Invalid Choice. Please try again: ";
            cin >> choice;
        }

        //Execute correct menu option based on value
        switch(choice) {
            case 1:
                try {
                    cin >> r1;
                    cin >> r2;
                } catch (Rational::ZeroDen) {
                    cout << endl;
                    cout << "No zero denominators allowed!" << endl << endl;
                    break;
                } catch (Rational::Alpha) {
                    cout << endl;
                    cin.clear(); //clear
                    cin.ignore(50, '\n'); //ignore
                    cout << "No alpha characters allowed!" << endl << endl;
                    break;
                }

                cout << endl;

                if (r1 > r2) {
                    cout << "Fraction 1 is greater than Fraction 2" << endl << endl;
                } else if (r1 < r2) {
                    cout << "Fraction 1 is less than Fraction 2" << endl << endl;
                } else if (r1 == r2) {
                    cout << "Fraction 1 is equal to Fraction 2" << endl << endl;
                }

                break;
            case 2:
                result = r1 + r2;
                cout << r1;
                cout << " + ";
                cout << r2;
                cout << " = ";
                cout << result;
                cout << " or ";
                result.displayFloat();
                cout << endl << endl;
                break;
            case 3:
                result = r1 - r2;
                cout << r1;
                cout << " - ";
                cout << r2;
                cout << " = ";
                cout << result;
                cout << " or ";
                result.displayFloat();
                cout << endl << endl;
                break;
            case 4:
                result = r1 * r2;
                cout << r1;
                cout << " * ";
                cout << r2;
                cout << " = ";
                cout << result;
                cout << " or ";
                result.displayFloat();
                cout << endl << endl;
                break;
            case 5:
                result = r1 / r2;
                cout << r1;
                cout << " / ";
                cout << r2;
                cout << " = ";
                cout << result;
                cout << " or ";
                result.displayFloat();
                cout << endl << endl;
                break;
        }
    } while (choice < 6);

    cout << "Goodbye!!!" << endl;

    return 0;
}

void displayMenu() {
    cout << "1. Input two fractions" << endl;
    cout << "2. Add and display result" << endl;
    cout << "3. Subtract and display result" << endl;
    cout << "4. Multiply and display result" << endl;
    cout << "5. Divide and display result" << endl;
    cout << "6. Quit" << endl << endl;
    cout << "Selection Choice: ";
}
