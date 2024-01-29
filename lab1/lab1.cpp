#include <iostream>
#include <cmath>

using namespace std;

// функция возведения в степень
double power(double n, int p = 2)
{
    return pow(n, p);
}

int main()
{
    while (true)
    {
        double n;

        cout << "Введите число: ";
        cin >> n;

        char yN; 
        cout << "Хотите ли вы ввести степень? Y/N" << endl;
        cin >> yN;

        if (yN == 'Y' || yN == 'y')
        {
            int p;
            cout << "Введите степень числа: ";
            cin >> p;
            cout << "Результат возведения в степень: " << power(n, p) << endl;
        }
        else
        {
            cout << "Результат возведения в степень: " << power(n) << endl;
        }

        char repeat;
        cout << "Хотите повторить? Y/N" << endl;
        cin >> repeat;

        if (repeat != 'Y' && repeat != 'y')
        {
            break;
        }
    }

    return 0;
}
