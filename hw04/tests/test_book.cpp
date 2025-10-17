#include "book.h"
#include <gtest/gtest.h>

TEST(BookTest, Normalization) {
    Book b("john123 d0e", "title", -10, 3000);
    EXPECT_EQ(b.GetPageNums(), 1);
    EXPECT_EQ(b.GetPublishYear(), 2025);
    EXPECT_EQ(b.GetAuthor(), "John Doe");
}

TEST(BookTest, AddBookmark) {
    Book b("Author", "Book", 100, 2000);
    b.AddBookmark(10);
    b.AddBookmark(90);
    EXPECT_EQ(b.GetBookmarkCount(), 2);
}

TEST(BookTest, RemoveBookmark) {
    Book b("Author", "Book", 100, 2000);
    b.AddBookmark(10);
    b.AddBookmark(20);
    b.AddBookmark(10);
    b.RemoveBookmark(10);
    EXPECT_EQ(b.GetBookmarkCount(), 1);
}

TEST(BookTest, CopyAssignment) {
    Book a("A", "T", 300, 2001);
    a.AddBookmark(50);
    Book b;
    b = a;
    EXPECT_EQ(b.GetPageNums(), 300);
    EXPECT_EQ(b.GetBookmarkCount(), 1);
}
