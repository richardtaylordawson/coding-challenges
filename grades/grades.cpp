#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class StudentStat{
    private:
        int Size;
        string Names [20];
        int Scores [20];
        float Avg, StDev, Median;
        int High_Score, Low_Score, Range;
        void Sortem (int *, string *, int); //Sorts the Data in Descending Order

    public:
        void Input (); //Input the file data into strings
        void Calc_Avg (); //Calculate the average
        void Calc_StDev (); //Calculate standard deviation
        void Calc_Median (); //Calculate the median
        void Calc_Range();  //Also calculates the high and low score
        void Output(); //Output the final data
};
// ********************************************************************************
void StudentStat::Sortem(int * ptr1, string * ptr2, int n) {
    for(int i = 0; i < (n - 1); i++) {
        for(int j = (i+1); j < n; j++) {
            int * num1 = ptr1 + i;
            int * num2 = ptr1 + j;
            string * string1 = ptr2 + i;
            string * string2 = ptr2 + j;

            if(*num1 < *num2) {
                int temp1 = *num1;
                *num1 = *num2;
                *num2 = temp1;
                string temp2 = *string1;
                *string1 = *string2;
                *string2 = temp2;
            }
        }
    }
}
// ********************************************************************************
void StudentStat::Input() {
    //File Name Variable
    string file = " ";

    //Ask for User's File
    cout << "Please enter the name of the file to read in: ";
    cin >> file;

    //Read in the file
    ifstream infile(file);

    //Invalid File
    if(!infile) {
        cout << endl << "Unable to open the file: " << file << endl;
        exit(0);
    }

    //Valid File
    while(!infile.eof()) {
        infile >> * (Names + Size);
        infile >> * (Scores + Size);
        Size++;
    }
}
// ********************************************************************************
void StudentStat::Calc_Avg() {
    float total = 0;

    for (int i = 0; i < Size; i++) {
        total += * (Scores + i);
    }

    Avg = total / Size;
}
// ********************************************************************************
void StudentStat::Calc_StDev() {
    //Used to Square
    float power = 2.0;
    float total = 0.0;

    for (int i = 0; i < Size; i++) {
        float base = * (Scores + i);

        total = pow((base - Avg), power) + total;
    }

    //Take Square Root of Total/Size for StDev
    StDev = sqrt(total/Size);
}
// ********************************************************************************
void StudentStat::Calc_Median() {
    StudentStat Studobj;

    Studobj.Sortem(Scores, Names, Size);

    int num = 0;

    if(Size % 2 == 1) {
        num = (Size / 2);
        Median = (*(Scores + num));
    } else {
        num = (Size / 2);
        Median = (((*(Scores + num - 1)) + (*(Scores + num))) / 2);
    }
}
// ********************************************************************************
void StudentStat::Calc_Range() {
    StudentStat Studobj;

    Studobj.Sortem(Scores, Names, Size);

    Range = ((* (Scores)) - (*(Scores + Size - 1)));
    High_Score = (*(Scores));
    Low_Score = (*(Scores + Size - 1));
}
// ********************************************************************************
void StudentStat::Output() {
    StudentStat Studobj;

    Studobj.Sortem(Scores, Names, Size);

    //Display the headers
    cout << endl << setw(20) << left << "Student" << setw(17) << right << "Score";
    cout << endl << setw(20) << left << "-------" << setw(17) << right << "------" << endl;


    //Print the Names and Scores
    for (int i = 0; i < Size; i++) {
        cout << setw(15) << left << * (Names + i);
        cout << setw(22) << right << * (Scores + i) << endl;
    }

    cout << "--------------Statistics--------------";
    cout << endl;
    cout << setw(15) << left << "Average:";
    cout << setw(22) << right << fixed << setprecision(2) << Avg << endl;
    cout << setw(15) << left << "St Dev:";
    cout << setw(22) << right << fixed << setprecision(2) << StDev << endl;
    cout << setw(15) << left << "Median:";
    cout << setw(22) << right << Median << endl;
    cout << setw(15) << left << "Highest Score:";
    cout << setw(22) << right << fixed << setprecision(2) << High_Score << endl;
    cout << setw(15) << left << "Lowest Score:";
    cout << setw(22) << right << fixed << setprecision(2) << Low_Score << endl;
    cout << setw(15) << left << "Range:";
    cout << setw(22) << right << Range << endl << endl;

}
// -----------------------------------------------------------------
int main() {
    StudentStat Studobj;

    cout << "****************************************************************************\n";
    cout << "*                                                                          *\n";
    cout << "*                    Welcome to the Student Stats Program                  *\n";
    cout << "*                                                                          *\n";
    cout << "****************************************************************************\n";

    Studobj.Input();

    Studobj.Calc_Avg();
    Studobj.Calc_StDev();
    Studobj.Calc_Median();
    Studobj.Calc_Range();

    Studobj.Output();

    cout << "****************************************************************************\n";
    cout << "*                                                                          *\n";
    cout << "*                                  Goodbye!!!                              *\n";
    cout << "*                                                                          *\n";
    cout << "****************************************************************************\n";

    return 0;
}

