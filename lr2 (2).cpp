#include <iostream>
#include <string>

using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title; // Название
    float price;  // Цена

public:
    // Метод получения данных от пользователя
    virtual void getdata() {
        cout << "Введите название публикации: ";
        cin >> title;
        cout << "Введите цену публикации: ";
        cin >> price;
    }

    // Метод вывода данных
    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }
};

// Базовый класс Sales
class Sales {
protected:
    float salesAmount[3]; // Массив для общего количества продаж за последние три месяца

public:
    // Метод получения данных о продажах
    void getSalesData() {
        for (int i = 0; i < 3; ++i) {
            cout << "Введите количество продаж за месяц " << (i + 1) << ": ";
            cin >> salesAmount[i];
        }
    }

    // Метод вывода данных о продажах
    void putSalesData(float price) const {
        cout << "Выручка за последние три месяца: ";
        for (int i = 0; i < 3; ++i) {
            float revenue = salesAmount[i] * price; // Вычисляем выручку
            cout << "Месяц " << (i + 1) << ": " << revenue << " руб." << endl;
        }
    }
};

// Класс Book, наследуемый от Publication и Sales
class Book : public Publication, public Sales {
private:
    int pages; // Количество страниц

public:
    // Переопределяем метод получения данных
    void getdata() override {
        Publication::getdata(); // Получаем данные из базового класса
        cout << "Введите количество страниц: ";
        cin >> pages;

        // Получаем данные о продажах
        getSalesData();
    }

    // Переопределяем метод вывода данных
    void putdata() const override {
        Publication::putdata(); // Выводим данные из базового класса
        cout << "Количество страниц: " << pages << endl;

        // Выводим данные о продажах
        putSalesData(price);
    }
};

// Класс Type, наследуемый от Publication и Sales
class Type : public Publication, public Sales {
private:
    string duration; // Тип публикации

public:
    // Переопределяем метод получения данных
    void getdata() override {
        Publication::getdata(); // Получаем данные из базового класса
        cout << "Введите время записи (в минутах): ";
        cin >> duration;

        // Получаем данные о продажах
        getSalesData();
    }

    // Переопределяем метод вывода данных
    void putdata() const override {
        Publication::putdata(); // Выводим данные из базового класса
        cout << "Время записи: " << duration << " мин." << endl;

        // Выводим данные о продажах
        putSalesData(price);
    }
};

// Основная функция
int main() {
    setlocale(LC_ALL, "Russian");
    Book book;
    book.getdata();
    cout << endl << "Данные о книге:" << endl;
    book.putdata();

    cout << endl;

    Type type;
    type.getdata();
    cout << endl << "Данные о типе публикации:" << endl;
    type.putdata();

    return 0;
}
