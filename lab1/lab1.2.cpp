#include <iostream>
#include <cmath>

using namespace std;

// перегруженные функции power()
double power(char n, int p = 2)
{
    return pow(static_cast<double>(n), p);
}

double power(short int n, int p = 2)
{
    return pow(static_cast<double>(n), p);
}

double power(long int n, int p = 2)
{
    return pow(static_cast<double>(n), p);
}

double power(float n, int p = 2)
{
    return pow(static_cast<double>(n), p);
}

double power(double n, int p = 2)
{
    return pow(n, p);
}

int main()
{
    // Вызов функции power() с различными типами аргументов
    cout << "char: " << power('A') << endl;
    cout << "short int: " << power(static_cast<short int>(5)) << endl;
    cout << "long int: " << power(static_cast<long int>(10)) << endl;
    cout << "float: " << power(3.14f) << endl;
    cout << "double: " << power(2.5) << endl;

    return 0;
}
