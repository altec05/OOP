
#include "polar_numbers.h"

namespace variant9123 {

    // Считывание и вывод дробных чисел
    void polar_numbers::OutSpecific(std::ofstream &ofstr) {
        ofstr << "[POLAR NUMBER = ";
        // Вывод комплексного числа в виде x/y
        ofstr << angle << ";" << radius << "]\n"; // Вывод числителя
    }

    void polar_numbers::InSpecific(std::ifstream &ifstr) {
        ifstr >> angle >> radius; // Считываем числитель и знаменатель
        if(!ifstr.eof()) ifstr.get(); // Переход на новую строку
    }

}