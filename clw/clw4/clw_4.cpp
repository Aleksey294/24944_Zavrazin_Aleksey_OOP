#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    int page_nums;
    int publish_year;

public:
    // Конструктор по умолчанию
    Book()
        : author("Unknown"), title("Untitled"), page_nums(0), publish_year(0)
    {
        cout << "default constructor" << endl;
    }

    // Инициализирующий конструктор
    Book(const string& a, const string& t, int pages, int year)
        : author(a), title(t), page_nums(pages), publish_year(year)
    {
        cout << "init constructor" << endl;
    }

    // Конструктор копирования
    Book(const Book& other)
        : author(other.author), title(other.title), 
          page_nums(other.page_nums), publish_year(other.publish_year)
    {
        cout << "copy constructor" << endl;
    }

    // Деструктор
    ~Book() {
        cout << "destructor" << endl;
    }

    // Оператор присваивания
    Book& operator=(const Book& other) {
        cout << "assignment operator" << endl;
        if (this == &other) return *this;
        author = other.author;
        title = other.title;
        page_nums = other.page_nums;
        publish_year = other.publish_year;
        return *this;
    }

    void print() const {
        cout << author << ", " << title << ", " << page_nums << " pages, " << publish_year << endl;
    }
};

int main() {
    Book b1;
    Book b2("George Orwell", "1984", 328, 1949);
    b1 = b2;
    b1.print();
    return 0;
}