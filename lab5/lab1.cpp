// 1.Типы данных полезны там, где ошибки могут быть вызваны арифметическим переполне-нием, которое не допустимо.
// Создайте и откомпилируйте класс Int. Перегрузите четыре бинарных целочисленных 
// арифметических операции (+, -, *, /) и унарные операции постфиксной и префиксной   
// форм ин-кремента с помощью внутренней операторной функции так, чтобы их можно было использо-вать 
// для операций с объектами класса Int. 
// Если результат какой-либо из них выходит за границы типа int (в 32-битной системе), 
// имеющее значения от 2 147 483 648 до -2 147 483 648, то операция должна послать сообщение об ошибке и 
// завершить программу.  Для выявления ошибки арифметического переполнения используйте концепцию исключения.
//  Для облегчения проверки переполнения выполняйте вычисления с использованием ти-па  long double. 
// При описании унарных операций используйте указатель this.

#include <iostream>
#include <limits>

using namespace std;

// Класс для работы с целыми числами с проверкой на переполнение
class Int {
private:
    long double value;

public:
    // Конструктор по умолчанию
    Int() : value(0) {}

    // Конструктор с одним аргументом для инициализации значения
    Int(long double initialValue) : value(initialValue) {
        checkOverflow();
    }

    // Метод для проверки на переполнение
    void checkOverflow() const {
        if (value > numeric_limits<int>::max() || value < numeric_limits<int>::min()) {
            cerr << "Ошибка арифметического переполнения. Завершение программы." << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Перегрузка операторов для арифметических операций
    Int operator+(const Int& other) const {
        Int result(value + other.value);
        result.checkOverflow();
        return result;
    }

    Int operator-(const Int& other) const {
        Int result(value - other.value);
        result.checkOverflow();
        return result;
    }

    Int operator*(const Int& other) const {
        Int result(value * other.value);
        result.checkOverflow();
        return result;
    }

    Int operator/(const Int& other) const {
        if (other.value == 0) {
            cerr << "Ошибка деления на ноль. Завершение программы." << endl;
            exit(EXIT_FAILURE);
        }

        Int result(value / other.value);
        result.checkOverflow();
        return result;
    }

    // Перегрузка унарных операторов инкремента
    Int operator++() {
        value++;
        checkOverflow();
        return *this;
    }

    Int operator++(int) {
        Int temp = *this;
        value++;
        checkOverflow();
        return temp;
    }

    // Перегрузка оператора вывода для удобного вывода объектов класса
    friend ostream& operator<<(ostream& out, const Int& obj) {
        out << obj.value;
        return out;
    }
};
int main() {
    // Тестирование класса Int
    Int a(214748);
    Int b(2);
    
    Int sum = a + b;
    cout << "Сумма: " << sum << endl;

    Int difference = a - b;
    cout << "Разность: " << difference << endl;

    Int product = a * b;
    cout << "Произведение: " << product << endl;

    Int quotient = a / b;
    cout << "Частное: " << quotient << endl;
    
    Int inc = ++b;
    cout << "Инкремент: " << inc << endl;      

    Int c(2147483647);
    Int increment = ++c;
    cout << "Инкремент: " << increment << endl;

    return 0;
}