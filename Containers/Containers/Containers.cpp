#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>

#include "exerciseAlgorithm.h"


void demoVectorDouble() {
    // vectors stored in the stack
    std::vector<double> temperatures; // default constructor
    std::cout << temperatures.size() << std::endl;

    std::vector<double> temperatures20(20, 21.0);

    // create vector with initializer list
    std::vector<double> temperatures3{ 6.5, 14.25, 30.0 };
    // alt F1: display hint type for auto
    for (auto t : temperatures3) {
        std::cout << t << " ";
    }
    std::cout << std::endl;

    std::vector<double> temperaturesCopy(temperatures3);
    std::cout << temperaturesCopy.size();

    temperatures3[1] = 16.75;
    std::cout << "value after modification: " << temperatures3[1] << std::endl;
} // temperatures, temperatures2, ... destroyed and calls destructors of each object

void demoConstructorWithAssignment() {
    // longest syntax for stack objects
    std::vector<double> temperatures = std::vector<double>();
    std::vector<double> temperatures2 = { 12.5, 24.3 };
    std::vector<double> temperatures3 = std::vector<double>({ 12.5, 24.3 });
}

void demoVectorHeapRawPointer() {
    // raw pointer
    std::vector<double>* temperatures_ptr = new std::vector<double>();
    std::vector<double>* temperatures2_ptr = new std::vector<double>(1000);
    std::vector<double>* temperatures3_ptr = new std::vector<double>{12.5, 25.2};
    if ((temperatures_ptr == nullptr) 
        || (temperatures2_ptr==nullptr) 
        || (temperatures3_ptr==nullptr)) 
    {
        std::cout << "not enough memory" << std::endl;
        return;
    }

    std::cout << temperatures2_ptr->size() << std::endl;

    delete temperatures_ptr;
    delete temperatures2_ptr;
    delete temperatures3_ptr;
    // NB: if other code after: reset ptr to nullptr
    //temperatures_ptr = nullptr;
    //temperatures2_ptr = nullptr;
    //temperatures3_ptr = nullptr;
}

void demoVectorHeapSmartPointer() {
    // std::unique_ptr<std::vector<double>> 
    auto temperatures_ptr = std::make_unique<std::vector<double>>();
    auto  temperatures2_ptr = std::make_shared<std::vector<double>>(1000);
    std::shared_ptr<std::vector<double>> temperatures3_ptr(temperatures2_ptr);  // share with temperatures2_ptr
    std::unique_ptr<std::vector<double>> temperatures4_ptr(new std::vector<double>{1.0, 2.0, 3.0});
    auto temperatures5_ptr = std::make_unique<std::vector<double>>(std::initializer_list<double>{ 1.0, 2.0, 3.0 });
    if ((temperatures_ptr == nullptr)
        || (temperatures2_ptr == nullptr)
        || (temperatures3_ptr == nullptr))
    {
        std::cout << "not enough memory" << std::endl;
        return;
    }

    std::cout << temperatures2_ptr->size() << std::endl;
    std::cout << "Shared counters: " << temperatures2_ptr.use_count()
        << " " << temperatures3_ptr.use_count();
} // call destructor of smart pointers (deallocate memory if counter at 0)

void demoVectorString()
{
    std::vector<std::string> cities;
    // std::vector<std::string&> citiesError;
}


void demoVectorIterate() {
    std::vector<double> temperatures{ 12.3, 14.5, 16.7, 29.7, 12.8, -4.0 };
    for (auto temperature : temperatures) { // loop by copy
        std::cout << temperature << std::endl;
    }
    for (auto& temperature : temperatures) { // loop by reference
        if (temperature < 0.0)
        {
            temperature = 0.0;
        }
    }
    for (auto temperature : temperatures) { // loop by copy
        std::cout << temperature << std::endl;
    }

    auto it = temperatures.cbegin();
    std::vector<double> temperatureExtract(it + 1, it + 5);
    for (auto temperature : temperatureExtract) { // loop by copy
        std::cout << temperature << std::endl;
    }
    auto first = it + 1;
    auto last = temperatures.cend() - 2;
    std::vector<double> temperatureExtract2(first, last);

    std::cout << std::endl;
    std::for_each(temperatureExtract2.cbegin(), temperatureExtract2.cend(),
        [](auto t) { std::cout << t << " "; }
    );
    std::cout << std::endl;

    std::copy(temperatures.cbegin(), temperatures.cend(), std::ostream_iterator<double>(std::cout, ", "));

    // C++20
    std::ranges::copy(temperatures.cbegin(), temperatures.cend(), std::ostream_iterator<double>(std::cout, ", "));
    std::ranges::copy(temperatures, std::ostream_iterator<double>(std::cout, ", "));
}

void demoArray() {
    std::array<double, 1000> temperatures;
}

int main()
{
    // demoVectorDouble();
    //demoVectorHeapRawPointer();
    // demoVectorHeapSmartPointer();
    // demoVectorIterate();
    exerciseAlgorithm(21.0, 3.0);
 
}
