
#include "fractional_numbers.h"

namespace variant9123 {

    // Считывание и вывод дробных чисел
    void fractional_numbers::OutSpecific(std::ofstream &ofstr) {
        ofstr << "[FRACTIONAL NUMBER = ";
        // Вывод комплексного числа в виде x/y
        ofstr << numerator << "/"; // Вывод числителя
        if(denominator >= 0) ofstr << denominator << "]" << std::endl; // Вывод положительного знаменателя
        else ofstr << "(" << denominator << ")]" << std::endl; // Вывод знаменателя в скобках
    }

    void fractional_numbers::InSpecific(std::ifstream &ifstr) {
        ifstr >> numerator >> denominator; // Считываем числитель и знаменатель
        if(!ifstr.eof()) ifstr.get(); // Переход на новую строку
    }

}