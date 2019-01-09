#include <iostream>
#include <string>

int main() {
    std::cout << "Please type your name: ";
    //define a variable: name with type std::string
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}