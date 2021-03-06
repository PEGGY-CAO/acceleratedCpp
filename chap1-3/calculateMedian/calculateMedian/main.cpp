//
//  main.cpp
//  calculateMedian
//
//  Created by Yuqi Cao on 1/21/19.
//  Copyright © 2019 GT. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <ios>
#include <string>
#include <vector>
#include <iomanip>

using std::cin;     using std::sort;
using std::cout;    using std::streamsize;
using std::string;  using std::vector;
using std::endl;    using std::setprecision;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Please enter your first name: \t";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl << "Input another name";
    cin >> name;
    cout << "HI YA" << name << endl;
    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    
    //two or more string literals in a program, separated only by whitespace,
    //are automatically concatenated.
    cout << "Enter all your homework grades, "
        "followed by end-of-file: ";
    vector<double> homework;
    double x;
    while (cin >> x) {
        homework.push_back(x);
    }
    
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size == 0) {
        cout << endl << "You must enter your grades. Plz try again." << endl;
        return 1;
    }
    
    sort(homework.begin(), homework.end());
    
    vec_sz mid = size / 2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid + 1]) / 2 : homework[mid];
    
    streamsize prec = cout.precision();
    cout << "Your final grade is : " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * median
    << setprecision(prec) << endl;
    
    return 0;
    
}
