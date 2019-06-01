//
//  main.cpp
//  reportLongShort
// Exercise 3-4. Write a program to report the length of the longest and shortest string in its input.
//  Created by Yuqi Cao on 6/1/19.
//  Copyright © 2019 GT. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string x;
    cout << "Please input some strings: " << endl;
    
    string::size_type longest = 0, shortest = 0;
    string longestOne, shortestOne;
    cin >> x;
    longestOne = x;
    shortestOne = x;
    longest = x.size();
    shortest = x.size();
    
    while(cin >> x) {
        string::size_type length = x.size();
        if (length > longest) {
            longest = length;
            longestOne = x;
        }
        if (length < shortest) {
            shortest = length;
            shortestOne = x;
        }
    }
    
    cout << "The longest string is: " << longestOne << endl;
    cout << "The shortest string is: " << shortestOne << endl;
    
    return 0;
}
