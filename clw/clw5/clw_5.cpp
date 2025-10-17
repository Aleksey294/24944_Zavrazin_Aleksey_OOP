#include <iostream>
#include <string>
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
    static const string class_name;

    void normalize() {
        if (page_nums <= 0 || page_nums > 10000)
            page_nums = 1;
        if (publish_year < 0 || publish_year > 2025)
            publish_year = 2025;

        for (auto& c : author)
            if (!isalpha(c) && c != ' ') c = ' ';
        for (size_t i = 0; i < author.size(); ++i)
            author[i] = (i == 0 || author[i - 1] == ' ') ? toupper(author[i]) : tolower(author[i]);
    }

public:
    Book()
        : author("Unknown"), title("Untitled"), page_nums(1), publish_year(2025),
          bookmarks(nullptr), bookmark_count(0)
    {
        ++object_count;
        cout << class_name << " default constructor (" << object_count << " objects)" << endl;
    }

    Book(const string& a, const string& t, int pages, int year)
        : author(a), title(t), page_nums(pages), publish_year(year),
          bookmarks(nullptr), bookmark_count(0)
    {
        normalize();
        ++object_count;
        cout << class_name << " init constructor (" << object_count << " objects)" << endl;
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
        cout << class_name << " copy constructor (" << object_count << " objects)" << endl;
    }

    ~Book() {
        --object_count;
        delete[] bookmarks;
        cout << class_name << " destructor (" << object_count << " objects left)" << endl;
    }

    Book& operator=(const Book& other) {
        cout << class_name << " copy assignment operator" << endl;
        if (this == &other) return *this;

        author = other.author;
        title = other.title;
        page_nums = other.page_nums;
        publish_year = other.publish_year;

        delete[] bookmarks;
        bookmark_count = other.bookmark_count;
        bookmarks = new int[bookmark_count];
        for (int i = 0; i < bookmark_count; ++i)
            bookmarks[i] = other.bookmarks[i];

        return *this;
    }

    void AddBookmark(int page) {
        if (page <= 0 || page > page_nums) return;
        int* new_array = new int[bookmark_count + 1];
        for (int i = 0; i < bookmark_count; ++i)
            new_array[i] = bookmarks[i];
        new_array[bookmark_count++] = page;
        delete[] bookmarks;
        bookmarks = new_array;
    }

    void RemoveBookmark(int page) {
        int count = 0;
        for (int i = 0; i < bookmark_count; ++i)
            if (bookmarks[i] != page) count++;
        int* new_array = new int[count];
        int j = 0;
        for (int i = 0; i < bookmark_count; ++i)
            if (bookmarks[i] != page)
                new_array[j++] = bookmarks[i];
        delete[] bookmarks;
        bookmarks = new_array;
        bookmark_count = count;
    }

    string GetAuthor() const { return author; }
    string GetTitle() const { return title; }
    int GetPageNums() const { return page_nums; }
    int GetPublishYear() const { return publish_year; }
    int* GetBookmarks() const { return bookmarks; }
    int GetBookmarkCount() const { return bookmark_count; }

    static int GetObjectCount() { return object_count; }
    static string GetClassName() { return class_name; }
};

int Book::object_count = 0;
const string Book::class_name = "Book";

int main() {
    cout << "Class name: " << Book::GetClassName() << endl;

    Book b1;
    Book b2("George Orwell", "1984", 328, 1949);
    Book b3 = b2;

    b1 = b3;

    b2.AddBookmark(100);
    b2.AddBookmark(200);
    cout << b2.GetAuthor() << " - " << b2.GetTitle() << endl;
    cout << "Bookmarks: " << b2.GetBookmarkCount() << endl;

    cout << "Active objects: " << Book::GetObjectCount() << endl;
    return 0;
}
