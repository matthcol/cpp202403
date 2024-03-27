#include "exerciseAlgorithm.h"

#include <random>
#include <algorithm>

void exerciseAlgorithm(double mean, double stdev)
{
	// random generation
    // generate random numbers with a Gauss distribution
    std::random_device rd{};
    std::mt19937 gen{ rd() };

    // values near the mean are the most likely
    // standard deviation affects the dispersion 
    // of generated values from the mean
    std::normal_distribution d{ mean, stdev };

    // draw a sample from the normal distribution and round it to an integer
    auto random_double = [&d, &gen] { return d(gen); };

    size_t n = 1000000;
    // 1. create vector of n values, filled with function random_double

    // 2. Find min and max

    // 3. find first value near the mean with margin epsilon=1E-3
    // What is the value just before, the value just after

    // 4. with threshold=40:
    // - count values > threshold
    // - filter values >  threshold and store result in a new vector

    // 5. sort result with double ascending order

    // 6. sort result with double descending order

    // 7. idem 4 filter (values), but store result in a (sorted) set

    // 8. compute sum of all values
    // verify mean

    // 9. transform each value with sqrt and collect result into a vector
}
