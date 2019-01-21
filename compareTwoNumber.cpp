#include <iostream>

using namespace std;

int main() {

    int a = 0, b = 0;
    cout << "Plz enter a number: ";
    cin >> a;
    //cout << endl;
    cout << "Plz enter the second one: ";
    cin >> b;

    if (a > b) {
        cout << "the larger one is: " << a << endl;
    } else if (b > a) {
        cout << "the larger one is: " << b << endl;
    } else {
        cout << "they are equal.";
    }

    return 0;
}