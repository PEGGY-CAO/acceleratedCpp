#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::streamsize;

int main() {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    //two or more string literals in a program, separated only by whitespace, 
    //are automatically concatenated.
    cout << "Enter all your homework grades, "
        "followed by end-of-file: ";

    //the number and sum of grades read so far
    int count = 0;
    double sum = 0;

    //declare a variable to read in
    double x;

    //if cin >> x succeeded, keep the while loop
    while (cin >> x) {
        ++count;
        sum += x;
    }
    
    //the <ios> header defines streamsize
    //prec is used to store the original precision
    streamsize prec = cout.precision();
    //the <iomanip> header defines the manipulator setprecision(), like endl
    //causing subsequent output on that stream to appear with the given significant digits
    //then we have to reset cout's precision to what it was before we changed it
    cout << "Your final grade is " << setprecision(3) 
        << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
        << setprecision(prec) << endl;
    return 0;
}