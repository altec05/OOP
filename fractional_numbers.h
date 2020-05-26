
#ifndef FRACT_H
#define FRACT_H

#include "numbers.h"

namespace variant9123 {

    // Структура дробных чисел
    class fractional_numbers : public numbers {
    public:
        // Считывание и вывод дробных чисел
        void OutSpecific(std::ofstream &ofstr);
        bool InSpecific(std::ifstream &ifstr);
        double ToDouble();
    private:
        types num_type; // Тип объекта
        std::string measure; // Единица измерения
        // Простые дроби (числитель, знаменатель – пара целых чисел)
        int numerator; // Числитель
        int denominator; // Знаменатель
    };

}

#endif //FRACT_H
