// Создайте класс Soft, который содержит информацию об установленном программном обеспе-чении. 
// Закрытыми элементами класса будут: название программы, разработчик, занимаемый объем, дата завершения лицензии. 
// Включите в класс открытые функции подсчета количества дней 
// до завершения лицензии и вывода всех данных об установленном программном обеспе-чении на экран. 
// Для инициализации и удаления объектов класса используйте конструкторы и деструкторы.
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

class Soft {
private:
    string programName;
    string developer;
    double diskSpace;
    chrono::system_clock::time_point licenseExpirationDate;

public:
    Soft(const string& name, const string& dev, double space, const chrono::system_clock::time_point& expirationDate)
        : programName(name), developer(dev), diskSpace(space), licenseExpirationDate(expirationDate) {}

    // Деструктор класса
    ~Soft() {
        cout << "Программа " << programName << " удалена.\n";
    }

    int daysUntilExpiration() const {
        auto now = chrono::system_clock::now();
        auto remainingTime = chrono::duration_cast<chrono::hours>(licenseExpirationDate - now);
        return remainingTime.count() / 24; // Переводим часы в дни
    }

    // Функция вывода данных о программном обеспечении на экран
    void displaySoftwareInfo() const {
        cout << "Название программы: " << programName << endl;
        cout << "Разработчик: " << developer << endl;
        cout << "Занимаемый объем: " << diskSpace << " МБ" << endl;
        cout << "Дата завершения лицензии: " << chrono::system_clock::to_time_t(licenseExpirationDate) << endl;
        cout << "Осталось дней до завершения лицензии: " << daysUntilExpiration() << " дней" << endl;
    }
};

int main() {
    // Пример использования класса
    auto expirationDate = chrono::system_clock::now() + chrono::hours(30 * 24);
    Soft software1("Microsoft Office", "Microsoft", 500, expirationDate);
    software1.displaySoftwareInfo();

    cout << "\n";

    auto expirationDate2 = chrono::system_clock::now() + chrono::hours(15 * 24);
    Soft software2("Adobe Photoshop", "Adobe", 1000, expirationDate2);
    software2.displaySoftwareInfo();

    return 0;
}
