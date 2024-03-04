//  3.	Создать класс, в котором перегружается метод rect_area().  
//  Этот метод возвращает площадь прямоугольника.  
// В этой программе метод rect_area() перегружается двумя способами. 
// В первом — методу передаются оба размера фигуры. 
// Эта версия используется для прямоугольника. 
// Однако, в случае квадрата необходимо задавать только один аргумент, 
// поэтому вызывается вторая версия метода rect_area().

#include <iostream>
#include <limits>

using namespace std;

// Класс для работы с прямоугольниками и квадратами
class Rectangle {
public:
    // Метод для расчета площади прямоугольника
    double rect_area(double length, double width) {
        return length * width;
    }

    // Перегрузка метода для расчета площади квадрата
    double rect_area(double side) {
        return side * side;
    }
};

int main() {
    // Тестирование класса Rectangle
    Rectangle rect;
    double area1 = rect.rect_area(5.0, 3.0);
    cout << "Площадь прямоугольника 1: " << area1 << endl;

    double area2 = rect.rect_area(4.0);
    cout << "Площадь прямоугольника 2 (квадрат): " << area2 << endl;

    return 0;
}
