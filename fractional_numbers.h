
#ifndef FRACT_H
#define FRACT_H

#include "numbers.h"

namespace variant9123 {

    // Структура дробных чисел
    class fractional_numbers : public numbers {
    public:
        // Считывание и вывод дробных чисел
        void OutSpecific(std::ofstream &ofstr);
        void InSpecific(std::ifstream &ifstr);
        void MultiMethod(numbers *numb, std::ofstream &ofstr);
        void FractMethod(std::ofstream &ofstr);
        void ComplMethod(std::ofstream &ofstr);
    private:
        types num_type; // Тип объекта
        // Простые дроби (числитель, знаменатель – пара целых чисел)
        int numerator; // Числитель
        int denominator; // Знаменатель
    };

}

#endif //FRACT_H
