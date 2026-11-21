#include "SeriesTasks.h"

#include <cmath>
#include <iterator>

namespace lab5 {

double series2(const std::vector<double>& numbers) {
    double product = 1.0;

    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
        product *= *it;
    }

    return product;
}

double series3(const std::vector<double>& numbers) {
    double sum = 0.0;

    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
        sum += *it;
    }

    return sum / 10.0; // По условию задачи даны ровно десять чисел.
}

std::pair<std::vector<double>, double> series6(const std::vector<double>& numbers) {
    std::vector<double> fractions;
    double product = 1.0;
    auto output = std::back_inserter(fractions);

    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
        double integerPart = 0.0;
        double fraction = std::modf(*it, &integerPart);

        *output = fraction; // Добавить дробную часть в конец вектора.
        ++output;
        product *= fraction;
    }

    return {fractions, product};
}

std::vector<int> series34(const std::vector<std::vector<int>>& groups) {
    std::vector<int> results;
    auto output = std::back_inserter(results);

    for (auto groupIt = groups.cbegin(); groupIt != groups.cend(); ++groupIt) {
        int sum = 0;
        bool hasTwo = false;

        for (auto it = groupIt->cbegin(); it != groupIt->cend(); ++it) {
            sum += *it;
            if (*it == 2) {
                hasTwo = true;
            }
        }

        *output = hasTwo ? sum : 0;
        ++output;
    }

    return results;
}

} // namespace lab5
