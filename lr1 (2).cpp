#include <iostream> 
#include <vector>   
#include <string>     
#include <stdexcept>
using namespace std;
// Перечисление для типов книг
enum class BookType {
    Fiction,   // Художественная литература
    Technical  // Техническая литература
};

// Класс книги
class Book {
public:
    // Конструктор класса Book, принимающий автора, название и тип книги
    Book(const string& author, const string& title, BookType type)
        : author_(author), title_(title), type_(type) {
        // Проверка на пустые строки для автора и названия
        setlocale(LC_ALL, "Russian");
        if (author_.empty() || title_.empty()) {
            throw invalid_argument("Отсутстует Автор или Название!");
        }
    }
    // Метод для отображения информации о книге
    void display() const {
        setlocale(LC_ALL, "Russian");
        cout << "Автор: " << author_ << ", Название: " << title_ << ", Тип: "
            << (type_ == BookType::Fiction ? "Художественная" : "Техническая") << endl;
    }
private:
    string author_; 
    string title_;  
    BookType type_;       
};
// Класс библиотеки
class Library {
public:
    // Метод для добавления книги в библиотеку
    void addBook(const Book& book) {
        books_.push_back(book); // Добавляем книгу в вектор книг
    }
    // Метод для отображения всех книг в библиотеке
    void displayBooks() const {
        setlocale(LC_ALL, "Russian");
        // Проверяем, есть ли книги в библиотеке
        if (books_.empty()) {
            cout << "В библиотеке нет книг" << endl; // Если нет книг, выводим сообщение
            return;
        }
        // Выводим заголовок
        cout << "Книги в библиотеке:" << endl;
        // Проходим по всем книгам и отображаем их
        for (const auto& book : books_) {
            book.display();
        }
    }
private:
    vector<Book> books_; // Вектор для хранения списка книг
};
int main() {
    setlocale(LC_ALL, "Russian");
    Library library; // Создаем объект библиотеки
    try {
        // Добавляем книги в библиотеку
        library.addBook(Book("Автор А", "Художественная книга 1", BookType::Fiction));
        library.addBook(Book("Автор Б", "Техническая книга 1", BookType::Technical));
        // Выводим все книги в библиотеке
        library.displayBooks();
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl; // Отлавливаем исключения и выводим сообщение об ошибке
    }
    return 0; // Возвращаем 0 для успешного завершения программы
}
