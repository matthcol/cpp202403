#include "exerciseAlgorithm.h"

#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <format>

// comment following line
#define PARALLEL 1

#ifdef PARALLEL
#include <execution>
#define SEQ std::execution::seq,
#define PAR std::execution::par,
#else
#define SEQ
#define PAR
#endif

#include "utils.h"

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

    // test:
    double number = random_double();
    std::cout << number << std::endl;

    size_t n = 1000000;
    // 1. create vector of n values, filled with function random_double
    std::vector<double> data(n);
    std::ranges::generate(data, random_double); // C++20
    std::generate(data.begin(), data.end(), random_double); // C++17

    std::cout << "data: "
        << data
        << std::endl;

    // 2. Find min and max
    auto [minIt, maxIt] = std::minmax_element(data.cbegin(), data.cend());
    std::cout << "min-max: " << *minIt << " - " << *maxIt << std::endl;
    auto [min2It, max2It] = std::ranges::minmax_element(data);
    std::cout << "min-max: " << *min2It << " - " << *max2It << std::endl;

    // 3. find first value near the mean with margin epsilon=1E-3
    // What is the value just before, the value just after
    double margin = 1E-3;
    auto nearMeanPredicate = [mean, margin](double t) {
        return fabs(t - mean) < margin;
    };
    auto nearMeanIt = std::find_if(data.cbegin(), data.cend(), nearMeanPredicate);
    auto nearMean2It = std::ranges::find_if(data, nearMeanPredicate);
    if (nearMeanIt != data.cend()) {
        std::cout << "First value near mean: " << *nearMeanIt 
            << ", previous " << (nearMeanIt != data.cbegin() ? *(nearMeanIt-1) : std::nan("1"))
            << ", next " << (nearMeanIt != (data.end() -1) ? *(nearMeanIt + 1) : std::nan("1"))
            << std::endl;
    }
    if (nearMean2It != data.cend()) {
        std::cout << "First value near mean: " << *nearMean2It
            << ", previous " << (nearMean2It != data.cbegin() ? *(nearMean2It - 1) : std::nan("1"))
            << ", next " << (nearMean2It != (data.end() - 1) ? *(nearMean2It + 1) : std::nan("1"))
            << std::endl;
    }

    // 4. with threshold=35:
    // - count values >= threshold
    // - filter values >=  threshold and store result in a new vector
    double threshold = 33.;
    auto predicateOverThreshold = [threshold](double t) {return t >= threshold; };
    auto nOver = std::count_if(data.cbegin(), data.cend(), predicateOverThreshold);
    auto n2Over = std::ranges::count_if(data, predicateOverThreshold);
    std::cout << "Count values over " << threshold << ": " << nOver << std::endl;
    std::cout << std::format("Count values over {}: {}", threshold, n2Over) << std::endl;

    std::vector<double> dataOver;
    std::copy_if(
        data.cbegin(), data.cend(),
        std::back_inserter(dataOver),
        predicateOverThreshold
    );
    std::vector<double> dataOver2;
    std::ranges::copy_if(
        data,
        std::back_inserter(dataOver2),
        predicateOverThreshold
    );
    std::cout << "Data over " << threshold << ": " << dataOver << std::endl;
    std::cout << std::format("Data over {}: ", threshold) << dataOver2 << std::endl;
    
    // 5. sort result with double ascending order
    std::sort(dataOver.begin(), dataOver.end());
    std::ranges::sort(dataOver2);
    std::cout << "Data over " << threshold << " ASC: " << dataOver << std::endl;
    std::cout << std::format("Data over {} ASC: ", threshold) << dataOver2 << std::endl;
    
    // 6. sort result with double descending order
    std::sort(dataOver.begin(), dataOver.end(), std::greater<double>());
    std::ranges::sort(dataOver2, std::ranges::greater());
    std::cout << "Data over " << threshold << " DESC: " << dataOver << std::endl;
    std::cout << std::format("Data over {} DESC: ", threshold) << dataOver2 << std::endl;

    // 7. idem 4 filter (values), but store result in a (sorted) set
    std::multiset<double> dataOverMS;
    std::copy_if(
        data.cbegin(), data.cend(),
        std::inserter(dataOverMS, dataOverMS.begin()),
        predicateOverThreshold
    );
    std::vector<double> dataOver2MS;
    std::ranges::copy_if(
        data,
        std::inserter(dataOver2MS, dataOver2MS.begin()),
        predicateOverThreshold
    );
    std::cout << "Data MS over " << threshold << ": " << dataOverMS << std::endl;
    std::cout << std::format("Data MS over {}: ", threshold) << dataOver2MS << std::endl;


    // 8. compute sum of all values
    // verify mean (unsing reduce or accumulate)
    double sumR = std::reduce(PAR data.cbegin(), data.cend(), 0.);
    double sumA = std::accumulate(data.cbegin(), data.cend(), 0.);
    double meanR = sumR / n;
    double meanA = sumA / n;
    std::cout << "Sum temperatures (reduce): " << sumR << ", mean: " << meanR << std::endl;
    std::cout << "Sum temperatures (reduce): " << sumA << ", mean: " << meanA << std::endl;

    // 9. transform each value with sqrt and collect result into a vector
    // NB: transform can be in place
    std::vector<double> dataSqrt(n);
    std::vector<double> dataSqrt2(n);
    std::transform(data.cbegin(), data.cend(), dataSqrt.begin(), [](double t) { return sqrt(t); });
    std::ranges::transform(data, dataSqrt2.begin(), [](double t) { return sqrt(t); });
    std::cout << "SQRT(data): " << dataSqrt << std::endl;
    std::cout << "SQRT(data): " << dataSqrt2 << std::endl;
}
