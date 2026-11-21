#include "SeriesTasks.h" // Подключаем объявления функций лабораторной.

#include <cmath> // Математические функции, здесь нужна std::modf.
#include <iterator> // Стандартные итераторы, здесь нужен std::back_inserter.

namespace lab5 { // Собственное пространство имён lab5, чтобы отличать наши функции от других.

double series2(const std::vector<double>& numbers) { // Series2: принимает вектор вещественных чисел по константной ссылке (без копирования и изменения).
    double product = 1.0; // Начальное произведение 1: умножение на 1 не меняет число.

    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) { // auto определяет тип итератора; cbegin — первый элемент, cend — позиция за последним, ++it — следующий элемент.
        product *= *it; // *it — значение текущего элемента; умножаем на него произведение.
    }

    return product; // Возвращаем итоговое произведение.
}

double series3(const std::vector<double>& numbers) { // Series3: принимает вектор вещественных чисел по константной ссылке.
    double sum = 0.0; // Начальная сумма 0.

    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) { // auto определяет тип итератора; cbegin — первый элемент, cend — позиция за последним, ++it — следующий элемент.
        sum += *it; // Прибавляем значение текущего элемента к сумме.
    }

    return sum / 10.0; // По условию задачи даны ровно десять чисел.
}

std::pair<std::vector<double>, double> series6(const std::vector<double>& numbers) { // std::pair возвращает два значения: std::vector<double> (дробные части) и double (произведение); вход — вектор по константной ссылке.
    std::vector<double> fractions; // Создаём пустой динамический массив дробных частей (double).
    double product = 1.0; // Начальное произведение 1: умножение на 1 не меняет число.
    auto output = std::back_inserter(fractions); // Создаём выходной итератор, добавляющий элементы в конец вектора fractions.

    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) { // auto определяет тип итератора; cbegin — первый элемент, cend — позиция за последним, ++it — следующий элемент.
        double integerPart = 0.0; // Переменная для целой части числа.
        double fraction = std::modf(*it, &integerPart); // std::modf возвращает дробную часть *it, а целую записывает по адресу &integerPart.

        *output = fraction; // Добавить дробную часть в конец вектора.
        ++output; // Для back_insert_iterator увеличение ничего не меняет; добавление происходит при присваивании через *output.
        product *= fraction; // Умножаем накопленное произведение на дробную часть.
    }

    return {fractions, product}; // Формируем пару: first — вектор дробных частей, second — произведение.
}

std::vector<int> series34(const std::vector<std::vector<int>>& groups) { // Возвращаем вектор целых чисел; принимаем вектор векторов (наборы чисел) без копирования.
    std::vector<int> results; // Создаём пустой вектор целочисленных результатов.
    auto output = std::back_inserter(results); // Создаём итератор для добавления результатов в конец вектора results.

    for (auto groupIt = groups.cbegin(); groupIt != groups.cend(); ++groupIt) { // Внешний цикл: идём по наборам, от первого до позиции за последним.
        int sum = 0; // Обнуляем сумму для текущего набора.
        bool hasTwo = false; // Флаг: пока двойку в этом наборе не нашли.

        for (auto it = groupIt->cbegin(); it != groupIt->cend(); ++it) { // Внутренний цикл: -> обращается к методам текущего набора; перебираем его числа.
            sum += *it; // Прибавляем значение текущего элемента к сумме.
            if (*it == 2) { // Проверяем, равно ли текущее число двум.
                hasTwo = true; // Запоминаем, что двойка найдена.
            }
        }

        *output = hasTwo ? sum : 0; // Тернарный оператор: если двойка есть, добавляем сумму; иначе добавляем 0.
        ++output; // Для back_insert_iterator увеличение ничего не меняет; добавление происходит при присваивании через *output.
    }

    return results; // Возвращаем вектор результатов всех наборов.
}

} // namespace lab5
