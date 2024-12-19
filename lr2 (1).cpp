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
        setlocale(LC_ALL, "Russian");
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }
};

// Класс Book, наследуемый от Publication
class Book : public Publication {
private:
    int pages; // Количество страниц

public:
    // Переопределяем метод получения данных
    void getdata() override {
        setlocale(LC_ALL, "Russian");
        Publication::getdata(); // Получаем данные из базового класса
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    // Переопределяем метод вывода данных
    void putdata() const override {
        setlocale(LC_ALL, "Russian");
        Publication::putdata(); // Выводим данные из базового класса
        cout << "Количество страниц: " << pages << endl;
    }
};
// Класс Type, наследуемый от Publication
class Type : public Publication {
private:
    int duration; // Время записи в минутах

public:
    // Переопределяем метод получения данных
    void getdata() override {
        setlocale(LC_ALL, "Russian");
        Publication::getdata(); // Получаем данные из базового класса
        cout << "Введите время записи (в минутах): ";
        cin >> duration;
    }
    // Переопределяем метод вывода данных
    void putdata() const override {
        setlocale(LC_ALL, "Russian");
        Publication::putdata(); // Выводим данные из базового класса
        cout << "Время записи: " << duration << " мин." << endl;
    }
};
int main() {
    Book myBook;
    Type myType;
    setlocale(LC_ALL, "Russian");

    cout << "Введите данные для книги:\n";
    myBook.getdata();
    cout << "\nДанные книги:\n";
    myBook.putdata();

    cout << "\nВведите данные для аудиозаписи:\n";
    myType.getdata();
    cout << "\nДанные аудиозаписи:\n";
    myType.putdata();

    return 0;
}
