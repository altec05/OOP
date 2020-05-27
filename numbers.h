
#ifndef NUMB_H
#define NUMB_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

namespace variant9123 {

    // Перечисляемый тип
    enum types {
        COMPLEX = 1, //Комплексные числа
        FRACTION = 2 // Простые дроби
    };

    class numbers {
    public:
        // Функции получения и установки num_type
        void set_type(int num);
        types get_type();
        // Статическую функцию можно вызывать без создания объекта
        // Считывание числа из файла
        static numbers *In(std::ifstream &ifstr);
        // Виртуальные функции должны быть переопределены потомками
        // Функция считывает свойства числа
        virtual void InSpecific(std::ifstream &ifstr) = 0;
        // Функция выводит свойства числа
        virtual void OutSpecific(std::ofstream &ofstr) = 0;

        virtual void MultiMethod(numbers *numb, std::ofstream &ofstr) = 0;
        virtual void FractMethod(std::ofstream &ofstr) = 0;
        virtual void ComplMethod(std::ofstream &ofstr) = 0;
    private:
        types num_type; // Тип объекта
    };

}

#endif //NUMB_H
