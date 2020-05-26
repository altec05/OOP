
#include "container.h"
#include "polar_numbers.h"

namespace variant9123 {

    // Проверка на переполнение
    bool numbers_array::OverflowTest() {
        bool res = len >= max_len;
        if(res) { // При переполнении
            std::cout << "Container is full. Stopping reading." << std::endl;
        }
        return res;
    }

    // Считывание и вывод всех чисел в контейнер
    void numbers_array::In(std::ifstream &ifstr) {
        while (!ifstr.eof()) {
            if(!OverflowTest()) {
                numbers *num = numbers::In(ifstr);
                if (!num) { // При ошибке
                    std::cout << "Error! Wrong object #" << len <<std::endl;
                    Clear(); // Очистка контейнера
                    return;
                }
                arr[len] = num;
                len++;
            } else return;
        }
    }

    void numbers_array::Out(std::ofstream &ofstr, types ignore) {
        if(len == 0) {
            ofstr << "Container is empty. " << std::endl;
            return;
        }
        for(int i = 0; i < len; i++) {
            // Выводим элементы
            if(arr[i]->GetType() == ignore) continue;
            arr[i]->OutSpecific(ofstr);
        }
        std::cout << "Writing is finished." << std::endl;
    }

    // Очистка контейнера "c"
    void numbers_array::Clear() {
        for(int i = 0; i < len; i++) {
            switch(arr[i]->GetType()) {
                case types::COMPLEX:
                    delete (complex_numbers*)arr[i];
                    break;
                case types::FRACTION:
                    delete (fractional_numbers*)arr[i];
                    break;
                case types::POLAR:
                    delete (polar_numbers*)arr[i];
            }
        }
        len = 0;
    }
    // Увеличить длину массива
    void numbers_array::IncrementLen() {
        len++;
    }
    // Получить значение длины
    int numbers_array::GetLen() {
        return len;
    }

    void numbers_array::Sort() {
        for(int i = 0; i < len-1; i++) {
            for(int j = i+1; j < len; j++) {
                if (numbers::Compare(arr[i], arr[j])) {
                    numbers* temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}