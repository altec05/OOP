#include "gtest/gtest.h"
#include "numbers.h"
#include "container.h"

using namespace std;
using namespace testing;

const bool is_testing = true;

void doTests() {
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

int main(int argc, char* argv[]) {
    if(is_testing)
        doTests();
        return 0;
    if(argc !=3) {
        cout << "incorrect command line! " << endl
             << "Waited: command in_file out_file"
             << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "Program started"<< endl;
    // Объявление numbers_array
    variant9123::numbers_array c{};
    // Считывание из файла
    c.In(ifst);
    // Вывод в файл
    c.Out(ofst);
    ofst << "-----------Sorted----------" << std::endl;
    c.Sort();
    c.Out(ofst);
    ofst << "-------ignoring--complex-------" << std::endl;
    c.Out(ofst, variant9123::types::COMPLEX);
    // Очистка контейнера
    c.Clear();
    cout << "Program ended"<< endl;
    return 0;
}
