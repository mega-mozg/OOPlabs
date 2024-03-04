// Задания:
// 1.	Для участия в ежегодном трансконтинентальном Ралли-марафоне «Дакар» по усложнен-ной трассе 
// в Южной Америке выбраны грузовики КАМАЗ и Tatra, которые после 2000 года лидируют в зачете грузовиков.
// Решите задачу сравнения скоростей движения грузовиков по разным по проходимости участкам трассы, 
// а именно: по равнине, горам, пустыне.  Создайте и выдайте на экран таблицу результатов ралли - марафона. 
// Определите победителя.
// Для решения задачи используйте классы Kamaz и Tatra, а также функцию сравнения ско-ростей FrCreater ().  
// Функция  FrCreater () возвращает число +1, если объект kamaz движется быстрее объекта tatra; нуль, 
// если их скорости одинаковы; число -1, если объект kamaz  дви-жется медленнее объекта tatra . 
// Оба класса содержат поля: «скорость» и «наименование» грузовой машины, 
// а также мето-ды: инициализация и отображение полей на экране. 
// Определитесь с идентификаторами доступа к членам класса, не нарушая принципа инкапсуляции. 
// 2.	Сделайте функцию FrCreater() дружественной: классу  Kamaz, обоим классам Kamaz и Tatra. 
// 3.	 Сделайте класс Tatra дружественным классу Kamaz.  

#include <iostream>
#include <string>
using namespace std;
class Tatra;

class Kamaz {
private:
    int speed;
    string name; 

public:
    Kamaz(int s, string n) : speed(s), name(n) {}

    void display() {
        cout << "Kamaz - Название: " << name << ", Скорость: " << speed << " км/ч" << endl;
    }

    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
    friend class Tatra;
};

class Tatra {
private:
    int speed;
    string name;

public:
    Tatra(int s, string n) : speed(s), name(n) {}

    void display() {
        cout << "Tatra - Название: " << name << ", Скорость: " << speed << " км/ч" << endl;
    }

    friend int FrCreater(const Kamaz& kamaz, const Tatra& tatra);
    friend class Kamaz;
};

int FrCreater(const Kamaz& kamaz, const Tatra& tatra) {
    if (kamaz.speed > tatra.speed)
        return 1;
    else if (kamaz.speed < tatra.speed)
        return -1;
    else
        return 0;
}

int main() {
    Kamaz kamaz(120, "Грузовик Камаз");
    Tatra tatra(110, "Грузовик Tatra");

    kamaz.display();
    tatra.display();

    int result = FrCreater(kamaz, tatra);

    if (result == 1)
        cout << "Грузовик Камаз быстрее, чем грузовик Tatra." << endl;
    else if (result == -1)
        cout << "Грузовик Tatra быстрее, чем грузовик Камаз." << endl;
    else
        cout << "Грузовик Камаз и грузовик Tatra имеют одинаковую скорость." << endl;

    return 0;
}