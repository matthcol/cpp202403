#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
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


// simple template
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

// template with concept C++20
template< std::ranges::input_range R, std::weakly_incrementable O >
    requires std::indirectly_copyable<std::ranges::iterator_t<R>, O>
std::ranges::copy_result<std::ranges::borrowed_iterator_t<R>, O> copy_essential(
    R&& range, 
    O result,
    std::ranges::range_difference_t<R> bin=5
) 
{
    auto n = std::ranges::distance(range);
    if (n <= 2*bin)
    {
        return std::ranges::copy(range, result);
    }
    else
    {
        std::ranges::copy_n(range.begin(), bin, result);

        auto start = std::ranges::next(range.begin(), n-bin);
        return std::ranges::copy_n(start, bin, result);
    }
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

