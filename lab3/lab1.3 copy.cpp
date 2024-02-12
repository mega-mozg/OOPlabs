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
    
    // Функция подсчета количества дней до завершения лицензии
    int daysUntilExpiration() const {
        auto now = chrono::system_clock::now();
        auto remainingTime = chrono::duration_cast<chrono::hours>(licenseExpirationDate - now);
        return remainingTime.count() / 24; // Переводим часы в дни
    }

    // Функция вывода данных о программном обеспечении на экран
    void displaySoftwareInfo() const {
        auto expirationDateT = chrono::system_clock::to_time_t(licenseExpirationDate);
        cout << "Название программы: " << programName << endl;
        cout << "Разработчик: " << developer << endl;
        cout << "Занимаемый объем: " << diskSpace << " МБ" << endl;
        cout << "Дата завершения лицензии: " << ctime(&expirationDateT);
        
        int daysLeft = daysUntilExpiration();
        if (daysLeft <= 0) {
            cout << "Лицензия истекла." << endl;
        } else {
            cout << "Осталось дней до завершения лицензии: " << daysLeft << " дней" << endl;
        }
    }
};

int main() {
    auto expirationDate = chrono::system_clock::now() + chrono::hours(0 * 24);
    Soft software1("Microsoft Office", "Microsoft", 500, expirationDate);
    software1.displaySoftwareInfo();

    cout << "\n";

    auto expirationDate2 = chrono::system_clock::now() + chrono::hours(10 * 24);
    Soft software2("Adobe Photoshop", "Adobe", 1000, expirationDate2);
    software2.displaySoftwareInfo();

    return 0;
}