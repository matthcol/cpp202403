#include <iostream>
#include <vector>


void demoVector() {
    std::vector<double> temperatures; // default constructor
    std::cout << temperatures.size() << std::endl;

    // create vector with initializer list
    std::vector<double> temperatures2{ 6.5, 14.25, 30.0 };
    // alt F1: display hint type for auto
    for (auto t : temperatures2) {
        std::cout << t << " ";
    }
    std::cout << std::endl;
} // temperatures, temperatures2 destroyed

int main()
{
    demoVector();
 
}
