
#include "fractional_numbers.h"

namespace variant9123 {

    // Считывание и вывод дробных чисел
    void fractional_numbers::OutSpecific(std::ofstream &ofstr) {
        ofstr << "[FRACTIONAL NUMBER = (" << ToDouble() << ") ";
        // Вывод комплексного числа в виде x/y
        ofstr << numerator << "/"; // Вывод числителя
        if(denominator >= 0) ofstr << denominator << " " << measure << "]" << std::endl; // Вывод положительного знаменателя
        else ofstr << "(" << denominator << ") " << measure << "]" << std::endl; // Вывод знаменателя в скобках
    }

    void fractional_numbers::InSpecific(std::ifstream &ifstr) {
        if(!ifstr.eof()) return;
        ifstr >> numerator;
        if(!ifstr.eof()) return;
        ifstr >> denominator; // Считываем числитель и знаменатель
        if(denominator == 0) {
            std::cout << "Error: division by zero!" << std::endl;
            return;
        }
        if(!ifstr.eof()) return;
        ifstr >> measure;
        if(!ifstr.eof()) ifstr.get(); // Переход на новую строку
    }

    double fractional_numbers::ToDouble() {
        return (double)(numerator)/(denominator);
    }

}