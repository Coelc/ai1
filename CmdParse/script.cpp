#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace boost::multiprecision;

int main() {
    // Определяем максимальное значение
    cpp_int max_value("0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364140");
    cpp_int start_value("0x1");

    auto start_time = chrono::steady_clock::now(); // Начальное время
    int output_interval = 60; // Интервал вывода в секундах

    // Итерируем от start_value до max_value
    for (cpp_int i = start_value; i <= max_value; ++i) {
        auto current_time = chrono::steady_clock::now();
        auto elapsed_time = chrono::duration_cast<chrono::seconds>(current_time - start_time).count();

        // Проверяем, прошло ли 60 секунд
        if (elapsed_time >= output_interval) {
            // Выводим текущее значение в шестнадцатичном формате
            cout << hex << setfill('0') << setw(64) << i << endl;
            start_time = current_time; // Сбрасываем таймер
        }
    }

    return 0;
}
