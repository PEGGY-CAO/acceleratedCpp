//
//  main.cpp
//  calculateWordsCount
//
//  Created by Yuqi Cao on 5/29/19.
//  Copyright © 2019 GT. All rights reserved.
//

#include <iostream>
#include <ios>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Please input some words: " << endl;
    vector<string> inputs;
    typedef vector<string>::size_type vecsz;
    vecsz totalWords = 0;
    string x;
    while (cin >> x) {
        inputs.push_back(x);
        totalWords++;
    }
    cout << totalWords << endl;
    // sort the vector in ascending order
    sort(inputs.begin(), inputs.end());    
    // use a for loop go through the vector and count words
    int count = 1;
    for (int i = 0; i < totalWords - 1; i++) {
        
        if (inputs[i] == inputs[i + 1]) {
            count++;
            if (i == totalWords - 2) {
                cout << inputs[i] << "'s count is : " << count << endl;
            }
        } else {
            cout << inputs[i] << "'s count is : " << count << endl;
            count = 1;
            if (i == totalWords - 2) {
                cout << inputs[i + 1] << "'s count is : " << count << endl;
            }
        }
        
    }
    
    return 0;
    
}
