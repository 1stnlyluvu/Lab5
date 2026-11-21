#include "pch.h"
#include <algorithm>
#include <iterator>
#include <istream>
#include <ostream>
#include <string>
#include <vector>
#include <list>
#include <deque>


// STL1Iter2: количество положительных чисел.
// std::istream — входной поток.
int STL1Iter2(std::istream& input)
{
    // std::istream_iterator — итератор чтения из потока.
    std::istream_iterator<double> begin(input);
    std::istream_iterator<double> end; // Конец потока.

    // std::count_if — подсчёт по условию.
    // static_cast<int> — преобразование в int; [] — лямбда.
    return static_cast<int>(std::count_if(begin, end, [](double x) {
        return x > 0;
    }));
}

// STL1Iter3: количество слов длиной 6.
int STL1Iter3(std::istream& input)
{
    std::istream_iterator<std::string> begin(input);
    std::istream_iterator<std::string> end;

    return static_cast<int>(std::count_if(begin, end, [](const std::string& word) {
        return word.size() == 6; // Длина слова.
    }));
}

// STL1Iter6: запись символов через пробел.
// std::vector — динамический массив.
// std::ostream — выходной поток.
void STL1Iter6(const std::vector<char>& symbols, std::ostream& output)
{
    // std::ostream_iterator — итератор записи в поток.
    std::ostream_iterator<char> out(output, " ");

    // std::copy — копирование элементов через итераторы.
    std::copy(symbols.cbegin(), symbols.cend(), out);
}

// STL2Seq34: чередование элементов двух списков.
// std::list — двусвязный список.
void STL2Seq34(std::list<int>& L1, std::list<int>& L2)
{
    auto i1 = L1.begin();
    auto i2 = L2.begin();
    auto N = L1.size();

    for (decltype(N) i = 0; i < N; ++i)
    {
        // splice — перенос элемента между списками.
        L2.splice(i2, L1, i1++);
        ++i2;
    }
}

// STL3Alg34: удвоение первой половины в обратном порядке.
// std::deque — двусторонняя очередь.
void STL3Alg34(std::deque<int>& D)
{
    auto middle = D.begin() + D.size() / 2; // Начало второй половины.

    // std::transform — преобразование элементов; rbegin() — обратный итератор.
    std::transform(D.begin(), middle, D.rbegin(), [](int x) {
        return x * 2;
    });
}
