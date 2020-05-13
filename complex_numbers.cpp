
#include "complex_numbers.h"

namespace variant9123 {
    // Считывание и вывод комплексных чисел
    void complex_numbers::InSpecific(std::ifstream &ifstr) {
        if(!ifstr.eof()) return;
        ifstr >> real;
        if(!ifstr.eof()) return;
        ifstr >> imaginary; // Считываем мнимую и действительную часть
        if(!ifstr.eof()) return;
        ifstr >> measure;
        if (!ifstr.eof()) ifstr.get(); // Переход на новую строку
    }

    void complex_numbers::OutSpecific(std::ofstream &ofstr) {
        ofstr << "[COMPLEX NUMBER = (" << ToDouble() << ") ";
        // Вывод комплексного числа в виде xi + y
        ofstr << imaginary << "i"; // xi
        // Вывод действительного числа со знаком "+"
        if (real >= 0) ofstr << "+" << real << " " << measure << "]" << std::endl;
        else ofstr << real << " " << measure << "]" << std::endl; // Со знаком "-"
    }

    double complex_numbers::ToDouble() {
        return sqrt(real*real + imaginary*imaginary);
    }

}