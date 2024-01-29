// 1.	В здании аэропорта на экранах отображается информация о самолетах, 
// а именно: ин-формация о пункте отправления, пункте назначения, 
// номере рейса, времени прибытия, времени отправления, номере секции для регистрации. 
// Экраны – это средство, которое помогает свое-временно зарегистрировать и отправить пассажиров.  
// Важно, чтобы информация на экранах была понятной и верной. 
// Создайте необходимую информацию в виде таблицы для такого экрана, с помощью класса Aeroflot, 
// содержащего в описании следующие поля: номер рейса; название пункта отправления; 
// название пункта назначения рейса; время прибытия; время отправления; место регистрации.
// Напишите код программы, выполняющей следующие действия: ввод с клавиатуры зна-чений полей объектов; 
// сортировку записей в таблице в алфавитном порядке по названию пунк-тов назначения; 
// вывод на консоль значений полей объектов класса в виде таблицы рейсов; если таких рейсов нет, выдать соответствующее сообщение

// 3 1 Бишкек Ош 6:00 5:00 123 2 Бишкек Москва 7:00 2:00 234 3 Бишкек Дубай 12:00 2:00 345
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class aeroflot {
public:
  int number;
  string otkuda;
  string kuda;
  string pribytie;
  string otpravlenie;
  int numRegstr;

  aeroflot() {}

  aeroflot(int number, string otkuda, string kuda, string pribytie, string otpravlenie, int numRegstr) {
    this->number = number;
    this->otkuda = otkuda;
    this->kuda = kuda;
    this->pribytie = pribytie;
    this->otpravlenie = otpravlenie;
    this->numRegstr = numRegstr;
  }
};

bool sravnit(aeroflot a, aeroflot b) {
  return a.kuda < b.kuda;
}

int main() {
  int n;
  cout << "Введите количество рейсов: ";
  cin >> n;

  aeroflot* raises = new aeroflot[n];

  // Ввод данных с клавиатуры
  for (int i = 0; i < n; ++i) {
    cout << "Введите данные для рейса #" << i + 1 << ":\n";
    cout << "Номер рейса: ";
    cin >> raises[i].number;
    cout << "Пункт отправления: ";
    cin >> raises[i].otkuda;
    cout << "Пункт назначения: ";
    cin >> raises[i].kuda;
    cout << "Время прибытия:";
    cin >> raises[i].pribytie;
    cout << "Время отправления:";
    cin >> raises[i].otpravlenie;
    cout << "Номер секции для регистрации: ";
    cin >> raises[i].numRegstr;
  }

  // Сортировка рейсов по пункту назначения
  sort(raises, raises + n, sravnit);

  // Вывод данных
  cout << "\nТаблица рейсов:\n";
  cout << "------------------------------------------------------------------------\n";
  cout << "| Номер | Отправление | Назначение | Прибытие | Отправление | Секция |\n";
  cout << "------------------------------------------------------------------------\n";
  for (int i = 0; i < n; ++i) {
    cout << "| " << raises[i].number << "     | " << raises[i].otkuda << "   | " << raises[i].kuda << "   | " << raises[i].pribytie << "    | " << raises[i].otpravlenie << "   | " << raises[i].numRegstr << "    |\n";
  }
  cout << "------------------------------------------------------------------------\n";

  delete[] raises;

  return 0;
}
