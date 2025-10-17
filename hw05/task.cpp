#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>
#include <cctype>
using namespace std;

class Book {
private:
    string author;
    string title;
    int page_nums;
    int publish_year;
    int* bookmarks;
    int bookmark_count;

    static int object_count;

    void validate() {
        if (page_nums <= 0 || page_nums > 10000)
            throw invalid_argument("Invalid page count!");
        if (publish_year < 0 || publish_year > 2025)
            throw invalid_argument("Invalid publish year!");
        if (author.empty())
            throw invalid_argument("Author name cannot be empty!");
    }

public:
    static const string class_name;

    Book()
        : author("Unknown"), title("Untitled"), page_nums(1), publish_year(2025),
          bookmarks(nullptr), bookmark_count(0)
    {
        ++object_count;
        cout << "Book default constructor (" << object_count << " total)" << endl;
    }

    Book(const string& a, const string& t, int pages, int year)
        : author(a), title(t), page_nums(pages), publish_year(year),
          bookmarks(nullptr), bookmark_count(0)
    {
        validate();
        ++object_count;
        cout << "Book init constructor (" << object_count << " total)" << endl;
    }

    Book(const Book& other)
        : author(other.author), title(other.title),
          page_nums(other.page_nums), publish_year(other.publish_year),
          bookmark_count(other.bookmark_count)
    {
        bookmarks = new int[bookmark_count];
        for (int i = 0; i < bookmark_count; ++i)
            bookmarks[i] = other.bookmarks[i];
        ++object_count;
        cout << "Book copy constructor (" << object_count << " total)" << endl;
    }

    ~Book() {
        delete[] bookmarks;
        --object_count;
        cout << "Book destructor (" << object_count << " left)" << endl;
    }

    Book& operator=(const Book& other) {
        cout << "Book assignment operator" << endl;
        if (this == &other) return *this;

        delete[] bookmarks;

        author = other.author;
        title = other.title;
        page_nums = other.page_nums;
        publish_year = other.publish_year;

        if (page_nums <= 0) throw invalid_argument("Assignment: invalid page count!");

        bookmark_count = other.bookmark_count;
        bookmarks = new int[bookmark_count];
        for (int i = 0; i < bookmark_count; ++i)
            bookmarks[i] = other.bookmarks[i];
        return *this;
    }

    void add_bookmark(int page) {
        if (page <= 0 || page > page_nums)
            throw out_of_range("Bookmark out of range!");

        int* new_array = new int[bookmark_count + 1];
        for (int i = 0; i < bookmark_count; ++i)
            new_array[i] = bookmarks[i];
        new_array[bookmark_count++] = page;
        delete[] bookmarks;
        bookmarks = new_array;
    }

    void printBook() const {
        cout << author << ", \"" << title << "\" (" << publish_year << "), " << page_nums << " pages, bookmarks: ";
        for (int i = 0; i < bookmark_count; ++i)
            cout << bookmarks[i] << " ";
        cout << endl;
    }

    static void print_count() {
        cout << "Active objects: " << object_count << endl;
    }

    friend ostream& operator<<(ostream& os, const Book& b) {
        os << b.author << " - " << b.title << " (" << b.publish_year << ")";
        return os;
    }
};

int Book::object_count = 0;
const string Book::class_name = "Book";

int main() {
    try {
        cout << "static values: " << endl;
        Book::print_count();
        cout << Book::class_name << endl << endl;

        cout << "Book creation: " << endl;
        Book my_first_book("Volkov Alexander", "The Wizard of Oz", 500, 1939);
        my_first_book.printBook();
        my_first_book.print_count();
        cout << my_first_book << endl;

        cout << "\nSecond book: " << endl;
        Book my_second_book{my_first_book};
        cout << my_second_book << endl;
        my_second_book.add_bookmark(222);
        my_first_book.add_bookmark(111);
        my_second_book.printBook();

        {
            cout << "\n inside {} " << endl;
            Book my_second_book{my_first_book};
            cout << my_second_book << endl;
            my_second_book.add_bookmark(30);
            my_first_book.add_bookmark(40);
            my_second_book.printBook();
        }

        cout << "\n outside {} " << endl;
        my_second_book.printBook();

        cout << "\n--- Testing exceptions ---" << endl;
        try {
            Book wrong_book("X", "Error", -100, 2050);
        } catch (const exception& e) {
            cout << "Caught exception: " << e.what() << endl;
        }

        cout << "\n--- Containers demonstration ---" << endl;

        vector<Book> books_vec;
        list<Book> books_list;
        set<string> titles_set;

        books_vec.emplace_back("J.K. Rowling", "Harry Potter", 600, 2001);
        books_vec.emplace_back("Tolkien", "The Hobbit", 310, 1937);
        books_vec.emplace_back("Pushkin", "Eugene Onegin", 200, 1833);

        for (const auto& b : books_vec)
            b.printBook();

        books_list.push_back(Book("Dostoevsky", "Idiot", 500, 1869));
        books_list.push_back(Book("King", "It", 1000, 1986));
        books_list.push_back(Book("Orwell", "Animal Farm", 150, 1945));

        for (const auto& b : books_list)
            b.printBook();

        titles_set.insert("Book A");
        titles_set.insert("Book B");
        titles_set.insert("Book C");

        for (const auto& title : titles_set)
            cout << "Set element: " << title << endl;
    }
    catch (const exception& e) {
        cout << "Global exception: " << e.what() << endl;
    }

    return 0;
}
