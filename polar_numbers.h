
#ifndef POLAR_H
#define POLAR_H

#include "numbers.h"

namespace variant9123 {

    // Структура дробных чисел
    class polar_numbers : public numbers {
    public:
        void OutSpecific(std::ofstream &ofstr);
        bool InSpecific(std::ifstream &ifstr);
        double ToDouble();
        void MultiMethod(numbers *numb, std::ofstream &ofstr);
        void FractMethod(std::ofstream &ofstr);
        void PolarMethod(std::ofstream &ofstr);
        void ComplMethod(std::ofstream &ofstr);
    private:
        types num_type; // Тип объекта
        std::string measure; // Единица измерения
        double angle; // угол [радиан]
        int radius; // Расстояние до точки
    };

}

#endif //POLAR_H
