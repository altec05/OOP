
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

    bool fractional_numbers::InSpecific(std::ifstream &ifstr) {
        bool bad_flag = false;
        if(ifstr.eof()) return false;
        ifstr >> numerator;
        if(ifstr.fail()) bad_flag = true;
        if(ifstr.eof() || bad_flag) return false;
        ifstr >> denominator; // Считываем числитель и знаменатель
        if(ifstr.fail()) bad_flag = true;
        if(denominator == 0) {
            std::cout << "Error: division by zero!" << std::endl;
            return false;
        }
        if(ifstr.eof() || bad_flag) return false;
        ifstr >> measure;
        if(ifstr.fail()) bad_flag = true;
        if(!ifstr.eof()) ifstr.get(); // Переход на новую строку
        if(bad_flag) return false;
        return true;
    }

    double fractional_numbers::ToDouble() {
        return (double)(numerator)/(denominator);
    }

}