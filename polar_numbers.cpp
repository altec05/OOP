
#include "polar_numbers.h"

namespace variant9123 {

    // Считывание и вывод дробных чисел
    void polar_numbers::OutSpecific(std::ofstream &ofstr) {
        ofstr << "[POLAR NUMBER = (" << ToDouble() << ") ";
        // Вывод комплексного числа в виде x/y
        ofstr << angle << ";" << radius << " " << measure << "]\n"; // Вывод числителя
    }

    bool polar_numbers::InSpecific(std::ifstream &ifstr) {
        bool bad_flag = false;
        if(ifstr.eof()) return false;
        ifstr >> angle;
        if(ifstr.fail()) bad_flag = true;
        if(ifstr.eof() || bad_flag) return false;
        ifstr >> radius; // Считываем числитель и знаменатель
        if(ifstr.fail()) bad_flag = true;
        if(ifstr.eof() || bad_flag) return false;
        ifstr >> measure;
        if(ifstr.fail()) bad_flag = true;
        if(!ifstr.eof()) ifstr.get(); // Переход на новую строку
        if(bad_flag) return false;
        return true;
    }

    double polar_numbers::ToDouble() {
        return radius*sin(angle);
    }

    void polar_numbers::MultiMethod(numbers *numb, std::ofstream &ofstr) {
        numb->PolarMethod(ofstr);
    }

    void polar_numbers::FractMethod(std::ofstream &ofstr) {
        ofstr << "--polar and fractional--";
    }

    void polar_numbers::PolarMethod(std::ofstream &ofstr) {
        ofstr << "--polar and polar--";
    }

    void polar_numbers::ComplMethod(std::ofstream &ofstr) {
        ofstr << "--polar and complex--";
    }
}