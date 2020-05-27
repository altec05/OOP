
#include "complex_numbers.h"

namespace variant9123 {
    // Считывание и вывод комплексных чисел
    bool complex_numbers::InSpecific(std::ifstream &ifstr) {
        bool bad_flag = false;
        if(ifstr.eof()) return false;
        ifstr >> real;
        if(ifstr.fail()) bad_flag = true;
        if(ifstr.eof() || bad_flag) return false;
        ifstr >> imaginary; // Считываем мнимую и действительную часть
        if(ifstr.fail()) bad_flag = true;
        if(ifstr.eof() || bad_flag) return false;
        ifstr >> measure;
        if(ifstr.fail()) bad_flag = true;
        if (!ifstr.eof()) ifstr.get(); // Переход на новую строку
        return !bad_flag;
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

    void complex_numbers::MultiMethod(numbers *numb, std::ofstream &ofstr) {
        numb->ComplMethod(ofstr);
    }

    void complex_numbers::FractMethod(std::ofstream &ofstr) {
        ofstr << "--complex and fractional--";
    }

    void complex_numbers::PolarMethod(std::ofstream &ofstr) {
        ofstr << "--complex and polar--";
    }

    void complex_numbers::ComplMethod(std::ofstream &ofstr) {
        ofstr << "--complex and complex--";
    }
}