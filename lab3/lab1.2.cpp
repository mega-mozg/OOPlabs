// Создайте класс Nomenclature, описывающий товары на складе магазина. 
// Закрытыми элемен-тами класса будут: название товара, оптовая цена, 
// розничная наценка и количество товаров на складе. 
// Включите в класс открытые функции подсчета возможного чистого дохода при прода-же этого товара и вывода всех данных о товаре на экран. 
// Для инициализации и удаления объек-тов класса используйте конструкторы и деструкторы.

#include <iostream>
#include <string>

using namespace std;

class Nomenclature {
private:
    string itemName;
    double wholesalePrice;
    double retailMarkup;
    int stockQuantity;

public:  
    Nomenclature(const string& name, double wholesalePrice, double retailMarkup, int quantity)
        : itemName(name), wholesalePrice(wholesalePrice), retailMarkup(retailMarkup), stockQuantity(quantity) {}

    // Деструктор класса
    ~Nomenclature() {
        cout << "Объект " << itemName << " удален.\n";
    }

    double calculateNetIncome() const {
        return stockQuantity * retailMarkup;
    }

    void displayProductInfo() const {
        cout << "Название товара: " << itemName << endl;
        cout << "Оптовая цена: $" << wholesalePrice << endl;
        cout << "Розничная наценка: $" << retailMarkup << endl;
        cout << "Количество на складе: " << stockQuantity << " шт." << endl;
        cout << "Возможный чистый доход: $" << calculateNetIncome() << endl;
    }
};

int main() {
    Nomenclature product1("Лаптоп", 800, 200, 10);
    product1.displayProductInfo();

    cout << "\n";

    Nomenclature product2("Смартфон", 500, 150, 20);
    product2.displayProductInfo();

    return 0;
}

