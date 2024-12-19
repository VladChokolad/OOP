#include <iostream>
#include <vector>
#include <memory>
#include <random>
using namespace std;


// Базовый класс Base
class Base {
public:
    virtual void showType() const {
         cout << "Base" <<  endl;
    }
    virtual ~Base() = default;  // Виртуальный деструктор
};

// Производный класс Derived
class Derived : public Base {
public:
    void showType() const override {
         cout << "Derived" <<  endl;
    }
};

void add( vector< shared_ptr<Base>>& storage, Base* item) {
    storage.emplace_back(item);
}

int main() {
     vector< shared_ptr<Base>> storage;
     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<> distr(1, 10);  // Генерируем числа от 1 до 10

    // Случайное создание объектов
    for (int i = 0; i < 10; ++i) {
        int randomNum = distr(gen);
        if (randomNum % 2 == 0) {
            add(storage, new Base());
        } else {
            add(storage, new Derived());
        }
    }

    // Показываем разницу в поведении типов объектов
    for (const auto& obj : storage) {
        obj->showType();
    }

    return 0;
}
