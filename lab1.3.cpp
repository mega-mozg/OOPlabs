// Алекс 19 слесарь 5000
// Иван 25 токарь 5500
// Елена 30 токарь 5200
// Петр 22 токарь 5300
// Марина 28 слесарь 5100
// Андрей 24 токарь 5400
//3
#include <iostream>
#include <string>

using namespace std;

// Структура представления информации о работнике
struct worker {
    string familiya;
    int age;
    string specialnost;
    double oklad;
};

//Функция для ввода информации о работниках на заводе
void vvodWorkers(worker workers[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Введите фамилию работника " << i + 1 << ": ";
        cin >> workers[i].familiya;

        cout << "Введите возраст работника " << i + 1 << ": ";
        cin >> workers[i].age;

        cout << "Введите специальность работника " << i + 1 << ": ";
        cin >> workers[i].specialnost;

        cout << "Введите средний оклад работника " << i + 1 << ": ";
        cin >> workers[i].oklad;

        cout << endl;
    }
}

// Функция для подсчета количества слесарей и токарей
void countWorkers(const worker workers[], int size, int& slesars, int& tokars) {
    slesars = 0;
    tokars = 0;

    for (int i = 0; i < size; ++i) {
        if (workers[i].specialnost == "слесарь") {
            slesars++;
        } else if (workers[i].specialnost == "токарь") {
            tokars++;
        }
    }
}

int main() {
    const int zavods = 3; // количество заводов
    const int workersZavods = 2; // количество работников на каждом заводе

    worker zavod[zavods][workersZavods]; // массив структур для каждого завода

    // Ввод информации по каждому заводу
    for (int i = 0; i < zavods; ++i) {
        cout << "Введите информацию по заводу " << i + 1 << ":" << endl;
        vvodWorkers(zavod[i], workersZavods);
    }

    // Подсчет количества слесарей и токарей для каждого завода
    for (int i = 0; i < zavods; ++i) {
        int vseSlesars, vseTokars;
        countWorkers(zavod[i], workersZavods, vseSlesars, vseTokars);
    
        cout << "Общее количество слесарей на заводе " << i + 1 << ": " << vseSlesars << endl;
        cout << "Общее количество токарей на заводе " << i + 1 << ": " << vseTokars << endl;
    }

    return 0;
}