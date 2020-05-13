
#include "polar_numbers.h"

namespace variant9123 {

    // Считывание и вывод дробных чисел
    void polar_numbers::OutSpecific(std::ofstream &ofstr) {
        ofstr << "[POLAR NUMBER = (" << ToDouble() << ") ";
        // Вывод комплексного числа в виде x/y
        ofstr << angle << ";" << radius << " " << measure << "]\n"; // Вывод числителя
    }

    void polar_numbers::InSpecific(std::ifstream &ifstr) {
        if(!ifstr.eof()) return;
        ifstr >> angle;
        if(!ifstr.eof()) return;
        ifstr >> radius; // Считываем числитель и знаменатель
        if(!ifstr.eof()) return;
        ifstr >> measure;
        if(!ifstr.eof()) ifstr.get(); // Переход на новую строку
    }

    double polar_numbers::ToDouble() {
        return radius*sin(angle);
    }
}