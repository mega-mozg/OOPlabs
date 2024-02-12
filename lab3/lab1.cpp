// Разработайте программу с классом Timer, в которой таймер действует как таймер обратного отсчета. 
// При создании объекта типа timer ему присваивается начальное значение времени. 
// В результате вызова функции run() таймер начинает отсчет в сторону уменьшающихся значений, 
// пока не достигнет значения 0, после чего зазвонит звонок. Создайте 3 варианта конструк-тора, т.е. к
// онструктор перегрузите 3 раза для того, чтобы можно было указывать время в секундах с помощью целого 
// числа или строки, или в минутах и секундах, если указываются два целых числа.
// Эта программа использует библиотечную функцию clock(), возвращающую число ти-ков, прошедших с момента запуска программы. 
// Поделив это значение на макрос CLK_TCK, получаем значение в секундах. 
// Прототипы для clock() и CLK_TCK содержатся в заголовоч-ном файле time.h.

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Timer {
private:
    int seconds;

public:
    // Конструктор, время в секундах
    Timer(int initialSeconds) : seconds(initialSeconds) {}

    // Конструктор, время в формате строки (чч:мм:сс)
    Timer(const string& timeString) {
        int hours, minutes, secs;
        sscanf(timeString.c_str(), "%d:%d:%d", &hours, &minutes, &secs);
        seconds = hours * 3600 + minutes * 60 + secs;
    }

    // Конструктор, время в минутах и секундах
    Timer(int minutes, int secs) : seconds(minutes * 60 + secs) {}

    // Функция запуска таймера
    void run() {
        while (seconds > 0) {
            cout << "Осталось времени: " << seconds << " секунд\n";
            cout << "Тик-так...\n";
            cout << "------------------------\n";
            //добавление заддержки
            this_thread::sleep_for(chrono::seconds(1));
            seconds--;
        }
        cout << "Время истекло! Звонок!\n";
    }
};

int main() {
    Timer timer1(10);
    timer1.run();

    Timer timer2("00:00:15");
    timer2.run();

    Timer timer3(0, 20);
    timer3.run();

    return 0;
}
