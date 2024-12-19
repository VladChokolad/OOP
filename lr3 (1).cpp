#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Базовый класс Part
class Part {
protected:
    Part() {}  // Запрет на явное создание экземпляров
public:
    virtual void showInfo() const = 0;  // Чисто виртуальная функция
    virtual ~Part() = default;  // Виртуальный деструктор
};

// Производный класс Assembly
class Assembly : public Part {
private:
    string name;
public:
    Assembly(const  string& name) : name(name) {}
    void showInfo() const override {
         cout << "Сборка: " << name <<  endl;
    }
};

// Производный класс Detail
class Detail : public Part {
private:
     string name;
public:
    Detail(const  string& name) : name(name) {}
    void showInfo() const override {
         cout << "Деталь: " << name <<  endl;
    }
};
// Шаблонная дружественная функция
template<typename T>
void add( vector< shared_ptr<Part>>& storage, T* item) {
    storage.emplace_back(item);
}

int main() {
    setlocale(LC_ALL, "Russian");
     vector< shared_ptr<Part>> storage;

    add(storage, new Assembly("Фрезировка"));
    add(storage, new Detail("Болт"));
    add(storage, new Assembly("Резка"));
    add(storage, new Detail("Винт"));
    for (const auto& part : storage) {
        part->showInfo();
    }
    return 0;
}
