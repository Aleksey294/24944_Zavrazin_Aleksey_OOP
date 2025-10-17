#include "book.h"
using namespace std;

int main() {
    Book b1;
    Book b2("george orwell", "1984", 328, 1949);

    b2.AddBookmark(50);
    b2.AddBookmark(120);
    b2.AddBookmark(200);
    b2.RemoveBookmark(120);

    cout << b2.GetAuthor() << " - " << b2.GetTitle()
         << " (" << b2.GetPublishYear() << "), pages: " << b2.GetPageNums() << endl;

    int* bm = b2.GetBookmarks();
    for (int i = 0; i < b2.GetBookmarkCount(); ++i)
        cout << "Bookmark: " << bm[i] << endl;

    return 0;
}
