
#include "container.h"

namespace variant9123 {

    // Проверка на переполнение
    bool numbers_array::Overflow_test() {
        bool res = len >= max_len;
        if(res) { // При переполнении
            std::cout << "Container is full. Stopping reading." << std::endl;
        }
        return res;
    }

    // Считывание и вывод всех чисел в контейнер
    void numbers_array::In(std::ifstream &ifstr) {
        while (!ifstr.eof()) {
            if(!Overflow_test()) {
                numbers *num = numbers::In(ifstr);
                if (!num) { // При ошибке
                    Clear(); // Очистка контейнера
                    return;
                }
                arr[len] = num;
                len++;
            } else return;
        }
    }

    void numbers_array::Out(std::ofstream &ofstr) {
        if(len == 0) {
            ofstr << "Container is empty. " << std::endl;
            return;
        }
        for(int i = 0; i < len; i++) {
            // Выводим элементы
            arr[i]->OutSpecific(ofstr);
        }
        std::cout << "Writing is finished." << std::endl;
    }

    // Очистка контейнера "c"
    void numbers_array::Clear() {
        for(int i = 0; i < len; i++) {
            switch(arr[i]->get_type()) {
                case types::COMPLEX:
                    delete (complex_numbers*)arr[i];
                    break;
                case types::FRACTION:
                    delete (fractional_numbers*)arr[i];
                    break;
            }
        }
    }
    // Увеличить длину массива
    void numbers_array::increment_len() {
        len++;
    }
    // Получить значение длины
    int numbers_array::get_len() {
        return len;
    }

    void numbers_array::OutPairs(std::ofstream &ofstr) {
        ofstr << "-----Printing-pairs-with-multimethod-----" << std::endl;
        for(int i = 0; i < len-1; i++) {
            for(int j = 0; j < len; j++) {
                if(i == j) continue;
                arr[i]->MultiMethod(arr[j], ofstr);
                ofstr << std::endl;
                arr[i]->OutSpecific(ofstr);
                arr[j]->OutSpecific(ofstr);
            }
        }
    }
}