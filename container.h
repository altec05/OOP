
#ifndef CONT_H
#define CONT_H

#include "complex_numbers.h"
#include "fractional_numbers.h"

namespace variant9123 {

    // Контейнер на основе одномерного массива элементов с проверкой на переполнение.
    class numbers_array {
    private:
        enum {max_len = 100}; // Максимальная длина
        int len; // Текущая длина
    public:
        // Очистка контейнера "c"
        void Clear();
        // Проверка на переполнение
        bool Overflow_test();
        // Увеличить длину массива
        void increment_len();
        // Получить значение длины
        int get_len();
        // Считывание и вывод всех чисел в контейнер
        void In(std::ifstream &ifstr);
        void Out(std::ofstream &ofstr, types ignore = types::NONE);
        numbers *arr[max_len];
    };

}

#endif //CONT_H
