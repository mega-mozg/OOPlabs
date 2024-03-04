// 2.	 Опишите класс fraction, у которого есть одно закрытое целочисленное поле chislo типа double.  
// Перегрузите для этого класса арифметические операции сложения, 
// вычи-тания, умножения и деления так, чтобы они могли оперировать как с объектами класса, 
// так и с числами (то есть выполнять, например, не только действие 3/4 +2/5, но и 1/2 + 4 или 2* 5/6). 
// Также перегрузите унарную операцию инкремента в префиксной или постфиксной форме увеличения дроби. 
// Продемонстрируйте работу класса. Используйте конструктор по умолча-нию и конструктор с одни аргументом для инициализации поля класса.

#include <iostream>
#include <limits>

using namespace std;

// Класс для работы с дробями и числами
class Fraction {
private:
    double chislo;

public:
    // Конструктор по умолчанию
    Fraction() : chislo(0) {}

    // Конструктор с одним аргументом для инициализации значения
    Fraction(double initialValue) : chislo(initialValue) {}

    // Перегрузка операторов для арифметических операций с дробями и числами
    Fraction operator+(const Fraction& other) const {
        Fraction result(chislo + other.chislo);
        return result;
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result(chislo - other.chislo);
        return result;
    }

    Fraction operator*(const Fraction& other) const {
        Fraction result(chislo * other.chislo);
        return result;
    }

    Fraction operator/(const Fraction& other) const {
        if (other.chislo == 0) {
            cerr << "Ошибка деления на ноль. Завершение программы." << endl;
            exit(EXIT_FAILURE);
        }

        Fraction result(chislo / other.chislo);
        return result;
    }

    // Перегрузка унарных операторов инкремента
    Fraction operator++() {
        chislo++;
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        chislo++;
        return temp;
    }

    // Перегрузка оператора вывода для удобного вывода объектов класса
    friend ostream& operator<<(ostream& out, const Fraction& obj) {
        out << obj.chislo;
        return out;
    }
};

int main() {
    // Тестирование класса Fraction
    Fraction frac1(3.0 / 6.0);
    Fraction frac2(0.5/2);

    Fraction sumFrac = frac1 + frac2;
    cout << "Сумма дробей: " << sumFrac << endl;

    Fraction diffFrac = frac1 - frac2;
    cout << "Разность дробей: " << diffFrac << endl;

    Fraction prodFrac = frac1 * frac2;
    cout << "Произведение дробей: " << prodFrac << endl;

    Fraction quotFrac = frac1 / frac2;
    cout << "Частное дробей: " << quotFrac << endl;

    Fraction frac3(1.5);
    Fraction incrementFrac = ++frac3;
    cout << "Инкремент дроби: " << incrementFrac << endl;
    return 0;
}