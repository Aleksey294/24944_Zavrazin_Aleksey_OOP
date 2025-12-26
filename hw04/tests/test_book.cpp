#include "../book.h"
#include <gtest/gtest.h>

// Тест нормализации
TEST(BookTest, Normalization) {
    Book b("john doe", "title", -10, 3000);
    EXPECT_EQ(b.GetPageNums(), 1);
    EXPECT_EQ(b.GetPublishYear(), 2025);
    EXPECT_EQ(b.GetAuthor(), "John Doe");  
}


// Тест нормализации с разными граничными случаями
TEST(BookTest, NormalizationEdgeCases) {
    Book b1("", "title", 0, -1);
    EXPECT_EQ(b1.GetPageNums(), 1);
    EXPECT_EQ(b1.GetPublishYear(), 2025);
    EXPECT_EQ(b1.GetAuthor(), "");

    Book b2("test   author", "title", 15000, 2026);
    EXPECT_EQ(b2.GetPageNums(), 1);
    EXPECT_EQ(b2.GetPublishYear(), 2025);
    EXPECT_EQ(b2.GetAuthor(), "Test Author");
}

// Тест добавления закладок
TEST(BookTest, AddBookmark) {
    Book b("Author", "Book", 100, 2000);
    b.AddBookmark(10);
    b.AddBookmark(90);
    EXPECT_EQ(b.GetBookmarkCount(), 2);
}

// Тест добавления невалидных закладок
TEST(BookTest, AddInvalidBookmark) {
    Book b("Author", "Book", 100, 2000);
    b.AddBookmark(0);      // Меньше минимума
    b.AddBookmark(101);    // Больше максимума
    b.AddBookmark(-5);     // Отрицательная
    EXPECT_EQ(b.GetBookmarkCount(), 0);
}

// Тест удаления закладок
TEST(BookTest, RemoveBookmark) {
    Book b("Author", "Book", 100, 2000);
    b.AddBookmark(10);
    b.AddBookmark(20);
    b.AddBookmark(10);
    b.RemoveBookmark(10);
    EXPECT_EQ(b.GetBookmarkCount(), 1);

    int* bookmarks = b.GetBookmarks();
    EXPECT_EQ(bookmarks[0], 20);
}

// Тест удаления всех закладок
TEST(BookTest, RemoveAllBookmarks) {
    Book b("Author", "Book", 100, 2000);
    b.AddBookmark(10);
    b.AddBookmark(10);
    b.RemoveBookmark(10);
    EXPECT_EQ(b.GetBookmarkCount(), 0);
    EXPECT_EQ(b.GetBookmarks(), nullptr);
}

// Тест удаления несуществующей закладки
TEST(BookTest, RemoveNonexistentBookmark) {
    Book b("Author", "Book", 100, 2000);
    b.AddBookmark(10);
    b.RemoveBookmark(20);
    EXPECT_EQ(b.GetBookmarkCount(), 1);
}

// Тест конструктора по умолчанию
TEST(BookTest, DefaultConstructor) {
    Book b;
    EXPECT_EQ(b.GetAuthor(), "Unknown");
    EXPECT_EQ(b.GetTitle(), "Untitled");
    EXPECT_EQ(b.GetPageNums(), 1);
    EXPECT_EQ(b.GetPublishYear(), 2025);
    EXPECT_EQ(b.GetBookmarkCount(), 0);
}

// Тест инициализирующего конструктора
TEST(BookTest, InitConstructor) {
    Book b("George Orwell", "1984", 328, 1949);
    EXPECT_EQ(b.GetAuthor(), "George Orwell");
    EXPECT_EQ(b.GetTitle(), "1984");
    EXPECT_EQ(b.GetPageNums(), 328);
    EXPECT_EQ(b.GetPublishYear(), 1949);
}

// Тест конструктора копирования
TEST(BookTest, CopyConstructor) {
    Book a("Author", "Title", 300, 2001);
    a.AddBookmark(50);
    a.AddBookmark(100);

    Book b(a);

    EXPECT_EQ(b.GetAuthor(), "Author");
    EXPECT_EQ(b.GetPageNums(), 300);
    EXPECT_EQ(b.GetBookmarkCount(), 2);

    int* bookmarks = b.GetBookmarks();
    EXPECT_EQ(bookmarks[0], 50);
    EXPECT_EQ(bookmarks[1], 100);

    // Проверка глубокого копирования
    EXPECT_NE(a.GetBookmarks(), b.GetBookmarks());
}

// Тест оператора присваивания
TEST(BookTest, CopyAssignment) {
    Book a("A", "T", 300, 2001);
    a.AddBookmark(50);

    Book b;
    b = a;

    EXPECT_EQ(b.GetPageNums(), 300);
    EXPECT_EQ(b.GetBookmarkCount(), 1);
    EXPECT_EQ(b.GetAuthor(), "A");

    // Проверка глубокого копирования
    EXPECT_NE(a.GetBookmarks(), b.GetBookmarks());
}

// Тест самоприсваивания
TEST(BookTest, SelfAssignment) {
    Book a("Author", "Title", 200, 2000);
    a.AddBookmark(10);

    a = a;

    EXPECT_EQ(a.GetPageNums(), 200);
    EXPECT_EQ(a.GetBookmarkCount(), 1);
}

// Тест повторяющихся закладок
TEST(BookTest, DuplicateBookmarks) {
    Book b("Author", "Book", 100, 2000);
    b.AddBookmark(10);
    b.AddBookmark(10);
    b.AddBookmark(20);

    EXPECT_EQ(b.GetBookmarkCount(), 3);

    b.RemoveBookmark(10);
    EXPECT_EQ(b.GetBookmarkCount(), 1);

    int* bookmarks = b.GetBookmarks();
    EXPECT_EQ(bookmarks[0], 20);
}