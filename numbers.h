
#ifndef NUMB_H
#define NUMB_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

namespace variant9123 {

    // Перечисляемый тип
    enum types {
        NONE = 0,
        COMPLEX = 1, //Комплексные числа
        FRACTION = 2, // Простые дроби
        POLAR = 3 // Полярные координаты
    };

    class numbers {
    public:
        // Функции получения и установки num_type
        void SetType(int type_id);
        types GetType();
        // Статическую функцию можно вызывать без создания объекта
        // Считывание числа из файла
        static numbers *In(std::ifstream &ifstr);
        // Виртуальные функции должны быть переопределены потомками
        // Функция считывает свойства числа
        virtual bool InSpecific(std::ifstream &ifstr) = 0;
        // Функция выводит свойства числа
        virtual void OutSpecific(std::ofstream &ofstr) = 0;
        virtual double ToDouble() = 0;
        static bool Compare(numbers *num1, numbers *num2);
        virtual void MultiMethod(numbers *numb, std::ofstream &ofstr) = 0;
        virtual void FractMethod(std::ofstream &ofstr) = 0;
        virtual void PolarMethod(std::ofstream &ofstr) = 0;
        virtual void ComplMethod(std::ofstream &ofstr) = 0;
    private:
        types num_type; // Тип объекта
    };

}

#endif //NUMB_H
