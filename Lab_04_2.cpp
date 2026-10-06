#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h> // Потрібно для налаштування кодування консолі

using namespace std;

int main() {
    // Встановлюємо кодування UTF-8 (CP_UTF8 = 65001) для коректного виводу укр. літер
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double x_start, x_end, dx;

    cout << "=== Табулювання функції (Варіант 3) ===" << endl;
    cout << "Введіть x_start (X_поч): ";
    cin >> x_start;
    cout << "Введіть x_end   (X_кін): ";
    cin >> x_end;
    cout << "Введіть dx      (Крок):  ";
    cin >> dx;

    // Перевірка коректності введення кроку
    if (dx <= 0 || x_start > x_end) {
        cout << "\nПомилка: Крок dx має бути більше 0, а x_start <= x_end!" << endl;
        return 1;
    }

    // Оформлення шапки таблиці
    cout << "\n+----------+----------+" << endl;
    cout << "|    x     |    y     |" << endl;
    cout << "+----------+----------+" << endl;

    cout << fixed;

    double x = x_start;
    // Додаємо dx / 2.0 до межі, щоб уникнути помилок округлення чисел з плаваючою крапкою
    while (x <= x_end + dx / 2.0) {
        double y;

        // Обчислення значення y залежно від діапазону x
        if (x < 0) {
            y = 1.0 + 4.0 * x * x;
        }
        else if (x <= 2.0) {
            y = exp(2.0 * x) + x;
        }
        else {
            y = 5.0 * sin(x * x + 1.0);
        }

        // Виведення x та y з вирівнюванням та зафіксованою точністю
        cout << "| " << setw(8) << setprecision(2) << x
            << " | " << setw(8) << setprecision(3) << y << " |" << endl;

        x += dx; // Збільшення x на крок dx
    }

    cout << "+----------+----------+" << endl;

    return 0;
}