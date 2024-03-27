#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <set>

//#include <vector>
//#include <set>
// TODO: define overload of operator<< for containers
//		display all values if size <= 10
//		else display first 5 values ... 5 last values
// - std::vector<double>
// - Bonus: in template mode for any container of any type 
//		for which << is defined

//std::ostream& operator<<(std::ostream& out, const std::vector<double>& vector);
//std::ostream& operator<<(std::ostream& out, const std::multiset<double>& vector);



template<class ContainerDouble>
std::ostream& write(std::ostream& out, const ContainerDouble& container)
{
    out << "[ ";
    // auto display_iterator = std::ostream_iterator<double>(out, " ");
    auto display = [&out](const auto& d) { out << d << " "; };
    if (container.size() <= 10)
    {
        //std::ranges::copy(vector, display_iterator);
        std::for_each(container.begin(), container.end(), display);
    }
    else
    {
        // std::copy_n(vector.begin(), 5, display_iterator);
        std::for_each_n(container.begin(), 5, display);
        out << "... ";

        // Random access iterator
        // std::copy_n(vector.end() - 5, 5, display_iterator);

        // All InputIterator
        // auto start = std::next(container.begin(), container.size() - 5);

        auto start = std::prev(container.end(), 5);
        std::for_each_n(start, 5, display);
    }
    return out << "]";
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
    return write(out, vector);
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& list) {
    return write(out, list);
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set)
{
    return write(out, set);
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& multiset) {
    return write(out, multiset);
}

