
#ifndef POLAR_H
#define POLAR_H

#include "numbers.h"

namespace variant9123 {

    // Структура дробных чисел
    class polar_numbers : public numbers {
    public:
        void OutSpecific(std::ofstream &ofstr);
        void InSpecific(std::ifstream &ifstr);
        double ToDouble();
    private:
        types num_type; // Тип объекта
        std::string measure; // Единица измерения
        double angle; // угол [радиан]
        int radius; // Расстояние до точки
    };

}

#endif //POLAR_H
