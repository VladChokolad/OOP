#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <exception>

// Базовый класс для всех ошибок
class ProgramError {
public:
    virtual std::string what() const {
        return "Ошибка в программе.";
    }
    virtual ~ProgramError() = default; // Виртуальный деструктор
};

// Производные классы ошибок
class InsufficientPrivilegesError : public ProgramError {
public:
    std::string what() const override {
        return "Недостаточно привилегий.";
    }
};

class ConversionError : public ProgramError {
public:
    std::string what() const override {
        return "Ошибка преобразования.";
    }
};

class ValueCannotBeConvertedError : public ConversionError {
public:
    std::string what() const override {
        return "Невозможно преобразовать значение.";
    }
};

class CannotCastToInterfaceError : public ConversionError {
public:
    std::string what() const override {
        return "Невозможно привести к интерфейсу.";
    }
};

// Исключение для несуществующего индекса
class IndexOutOfBoundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Индекс вне диапазона.";
    }
};

// Шаблонный класс для хранения массива указателей на объекты
template<typename T>
class PointerArray {
private:
    std::vector<std::shared_ptr<T>> array;
public:
    void add(std::shared_ptr<T> element) {
        array.push_back(element);
    }

    std::shared_ptr<T>& operator[](size_t index) {
        if (index >= array.size()) {
            throw IndexOutOfBoundsException();
        }
        return array[index];
    }

    size_t size() const {
        return array.size();
    }
};

// Пример использования
int main() {
    try {
        setlocale(LC_ALL, "Russian");
        // Создаем массивы для хранения указателей на различные типы ошибок
        PointerArray<ProgramError> errors;
        errors.add(std::make_shared<InsufficientPrivilegesError>());
        errors.add(std::make_shared<ValueCannotBeConvertedError>());
        errors.add(std::make_shared<CannotCastToInterfaceError>());

        // Демонстрация работы
        for (size_t i = 0; i < errors.size(); ++i) {
            std::cout << "Ошибка " << i + 1 << ": " << errors[i]->what() << std::endl;
        }

        // Попытка доступа к несуществующему элементу
        try {
            std::cout << "Доступ к несуществующему элементу: " << std::endl;
            std::cout << errors[3]->what() << std::endl; // Это вызовет исключение
        }
        catch (const IndexOutOfBoundsException& ex) {
            std::cerr << "Исключение: " << ex.what() << std::endl;
        }

        // Создать другой массив для тестирования с другим классом
        PointerArray<int> numbers;
        numbers.add(std::make_shared<int>(10));
        numbers.add(std::make_shared<int>(20));

        std::cout << "Число 1: " << *numbers[0] << std::endl;
        std::cout << "Число 2: " << *numbers[1] << std::endl;

        // Проверка на утечки памяти не требуется вручную, так как используются умные указатели

    }
    catch (const std::exception& ex) {
        std::cerr << "Произошла ошибка: " << ex.what() << std::endl;
    }

    return 0;
}
