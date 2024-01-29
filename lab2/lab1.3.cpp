// 1 3 грузовой 12 вправо пассажирский 2 вправо грузовой 3 влево
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Train {
public:
    string type; // тип вагона
    int number;  // номер вагона

    Train(string t, int n) : type(t), number(n) {}
};

class TrainSortingNode {
private:
    stack<Train> leftDirection;  // Вагоны направляющиеся влево
    stack<Train> rightDirection; // Вагоны направляющиеся вправо

public:
    void addTrainsToDirection(const Train &train, const string &direction) {
        if (direction == "влево") {
            leftDirection.push(train);
        } else if (direction == "вправо") {
            rightDirection.push(train);
        } else {
            cout << "Некорректное направление.\n";
        }
    }

    void displayTrains() {
        cout << "Составы по направлениям:\n";
        cout << "Влево:\n";
        displayStack(leftDirection);
        cout << "Вправо:\n";
        displayStack(rightDirection);
    }

    void displayStack(stack<Train> &s) {
        if (s.empty()) {
            cout << "Стек пуст.\n";
            return;
        }

        stack<Train> temp = s;
        cout << "\nТаблица вагонов:\n";
        cout << "------------------------------------\n";
        cout << "| тип | номер |\n";

        while (!temp.empty()) {
            cout << '|' << temp.top().type << " | " << temp.top().number << "|\n";
            temp.pop();
        }
        cout << "------------------------------------\n";
        cout << endl;
    }

    void loadTrainsFromConsole() {
        int n;
        cout << "Введите количество вагонов: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            string type, direction;
            int number;

            cout << "Введите данные для вагона #" << i + 1 << ":\n";
            cout << "Тип (грузовой/пассажирский): ";
            cin >> type;
            cout << "Номер: ";
            cin >> number;
            cout << "Направление (влево/вправо): ";
            cin >> direction;

            addTrainsToDirection(Train(type, number), direction);
        }
    }
};

int main() {
    TrainSortingNode sortingNode;

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Ввести составы\n";
        cout << "2. Показать составы\n";
        cout << "3. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sortingNode.loadTrainsFromConsole();
                cout << "Составы загружены с клавиатуры.\n";
                break;
            case 2:
                sortingNode.displayTrains();
                break;
            case 3:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Некорректный выбор.\n";
        }
    } while (choice != 3);

    return 0;
}
