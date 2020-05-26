#include "numbers.h"
#include "complex_numbers.h"
#include "fractional_numbers.h"
#include "polar_numbers.h"
namespace variant9123 {

    // Считывание числа из файла
    numbers *numbers::In(std::ifstream &ifstr) {
        numbers *element = nullptr; // Объявление экземпляра структуры
        char data[255]; // Буфер для считывания
        ifstr.getline(data, 255); // Считываем строку

        if (std::string(data) == "1") { // Если вводим комплексное число
            element = new complex_numbers;
            element->SetType(types::COMPLEX);
        } else if (std::string(data) == "2") { // Если вводим дробь
            element = new fractional_numbers;
            element->SetType(types::FRACTION);
        } else if (std::string(data) == "3") { // Если вводим полярные координаты
            element = new polar_numbers;
            element->SetType(types::POLAR);
        } else { // Если тип не найден
            delete element;
            std::cout << "Error has occurred while reading the file" << std::endl;
            return nullptr;
        }

        bool ok = element->InSpecific(ifstr); // Считываем комплексное число и сохраняем указатель
        if(!ok) return nullptr;
        return element;
    }

    void numbers::SetType(int type_id) {
        num_type = (types)type_id;
    }

    types numbers::GetType() {
        return num_type;
    }

    bool numbers::Compare(numbers *num1, numbers *num2) {
        return num1->ToDouble() > num2->ToDouble();
    }
}