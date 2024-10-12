#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <iomanip>

using namespace std;
using namespace boost::multiprecision;

int main() {
    // Определяем максимальное значение
    cpp_int max_value("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364140");
    cpp_int start_value("1");

    // Итерируем от start_value до max_value
    for (cpp_int i = start_value; i <= max_value; ++i) {
        // Выводим текущее значение в шестнадцатичном формате
        cout << hex << setfill('0') << setw(64) << i << endl;
    }

    return 0;
}
