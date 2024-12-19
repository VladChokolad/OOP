#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    // Определяем массив из 10 элементов типа short
    short* array = new short[10];
    // Заполняем массив случайными числами (допустим, от 1 до 100)
    for (int i = 0; i < 10; ++i) {
        array[i] = rand() % 100 + 1; // Генерация случайного числа
    }
    // Выводим содержимое массива и вычисляем расстояние каждого элемента от начала
    cout << "Содержимое массива:" << endl;
    for (int i = 0; i < 10; ++i) {
        // Вычисляем адрес каждого элемента
        short* currentAddress = &array[i];
        // Вычисляем адрес начала массива
        short* baseAddress = array;
        // Вычисляем расстояние
        ptrdiff_t distance = currentAddress - baseAddress;
        // Выводим значение элемента и его расстояние от начала
        cout << "Элемент[" << i << "] = " << array[i]
            << ", Адрес = " << static_cast<void*>(currentAddress)
            << ", Расстояние от начала = " << distance << endl;
    }
    // Освобождаем выделенную память
    delete[] array;

    return 0;
}
