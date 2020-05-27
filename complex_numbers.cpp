
#include "complex_numbers.h"

namespace variant9123 {
    // Считывание и вывод комплексных чисел
    void complex_numbers::InSpecific(std::ifstream &ifstr) {
        ifstr >> real >> imaginary; // Считываем мнимую и действительную часть
        if (!ifstr.eof()) ifstr.get(); // Переход на новую строку
    }

    void complex_numbers::OutSpecific(std::ofstream &ofstr) {
        ofstr << "[COMPLEX NUMBER = ";
        // Вывод комплексного числа в виде xi + y
        ofstr << imaginary << "i"; // xi
        // Вывод действительного числа со знаком "+"
        if (real >= 0) ofstr << "+" << real << "]" << std::endl;
        else ofstr << real << "]" << std::endl; // Со знаком "-"
    }

    void complex_numbers::MultiMethod(numbers *numb, std::ofstream &ofstr) {
        numb->ComplMethod(ofstr);
    }

    void complex_numbers::FractMethod(std::ofstream &ofstr) {
        ofstr << "--complex and fractional--";
    }

    void complex_numbers::ComplMethod(std::ofstream &ofstr) {
        ofstr << "--complex and complex--";
    }

}