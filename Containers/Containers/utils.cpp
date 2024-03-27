#include "utils.h"

#include <algorithm>
#include <iterator>

//std::ostream& operator<<(std::ostream& out, const std::vector<double>& vector)
//{
//    out << "[ ";
//    // auto display_iterator = std::ostream_iterator<double>(out, " ");
//    auto display = [&out](double d) { out << d << " "; };
//    if (vector.size() <= 10)
//    {
//        //std::ranges::copy(vector, display_iterator);
//        std::ranges::for_each(vector, display);
//    }
//    else 
//    {
//        // std::copy_n(vector.begin(), 5, display_iterator);
//        std::for_each_n(vector.begin(), 5, display);
//        out << "... ";
//        // std::copy_n(vector.end() - 5, 5, display_iterator);
//        std::for_each_n(vector.end() - 5, 5, display);
//    }
//    return out << "]";
//}
