

#ifndef COMP_H
#define COMP_H

#include "numbers.h"

namespace variant9123 {

    // Класс комплексных чисел
    class complex_numbers : public numbers {
    public:
        // Считывание и вывод комплексных чисел
        void OutSpecific(std::ofstream &ofstr);
        // Функция считывает свойства числа
        void InSpecific(std::ifstream &ifstr);
    private:
        types num_type; // Тип объекта
        std::string measure; // Единица измерения
        // Комплексные (действительная и мнимая части – пара действительных чисел)
        double real;
        double imaginary;
    };

}

#endif //COMP_H
