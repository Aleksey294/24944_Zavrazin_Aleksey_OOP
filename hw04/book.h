#pragma once
#include <iostream>
#include <string>
#include <cctype>

class Book {
private:
    std::string author;
    std::string title;
    int page_nums;
    int publish_year;
    int* bookmarks;
    int bookmark_count;

    static const int MAX_PAGES = 10000;
    static const int CURRENT_YEAR = 2025;

    void normalize() {
        if (page_nums <= 0 || page_nums > MAX_PAGES)
            page_nums = 1;

        if (publish_year < 0 || publish_year > CURRENT_YEAR)
            publish_year = CURRENT_YEAR;

        for (auto& c : author)
            if (!isalpha(c) && c != ' ') c = ' ';

        for (size_t i = 0; i < author.size(); ++i) {
            if (i == 0 || author[i - 1] == ' ')
                author[i] = toupper(author[i]);
            else
                author[i] = tolower(author[i]);
        }
    }

public:
    Book() : author("Unknown"), title("Untitled"), page_nums(1), publish_year(CURRENT_YEAR),
             bookmarks(nullptr), bookmark_count(0) {
        std::cout << "default constructor" << std::endl;
    }

    Book(const std::string& a, const std::string& t, int pages, int year)
        : author(a), title(t), page_nums(pages), publish_year(year),
          bookmarks(nullptr), bookmark_count(0) {
        std::cout << "init constructor" << std::endl;
        normalize();
    }

    ~Book() {
        std::cout << "destructor" << std::endl;
        delete[] bookmarks;
    }

    Book& operator=(const Book& other) {
        std::cout << "copy assignment operator" << std::endl;
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
        new_array[bookmark_count] = page;

        delete[] bookmarks;
        bookmarks = new_array;
        bookmark_count++;
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

    std::string GetAuthor() const { return author; }
    std::string GetTitle() const { return title; }
    int GetPageNums() const { return page_nums; }
    int GetPublishYear() const { return publish_year; }
    int* GetBookmarks() const { return bookmarks; }
    int GetBookmarkCount() const { return bookmark_count; }
};
