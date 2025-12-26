#include "book.h"

using namespace std;

int main() {
    cout << "=== Test 1: Default and Init Constructors ===" << endl;
    Book b1;
    Book b2("george orwell", "1984", 328, 1949);
    
    cout << "\n=== Test 2: Normalization ===" << endl;
    Book b3("john123 d0e", "Test Book", -10, 3000);
    cout << "Normalized author: " << b3.GetAuthor() << endl;
    cout << "Normalized pages: " << b3.GetPageNums() << endl;
    cout << "Normalized year: " << b3.GetPublishYear() << endl;
    
    cout << "\n=== Test 3: Bookmarks ===" << endl;
    b2.AddBookmark(50);
    b2.AddBookmark(120);
    b2.AddBookmark(200);
    b2.RemoveBookmark(120);
    
    cout << b2.GetAuthor() << " - " << b2.GetTitle()
         << " (" << b2.GetPublishYear() << "), pages: " << b2.GetPageNums() << endl;
    
    int* bm = b2.GetBookmarks();
    for (int i = 0; i < b2.GetBookmarkCount(); ++i)
        cout << "Bookmark: " << bm[i] << endl;
    
    cout << "\n=== Test 4: Copy Constructor ===" << endl;
    Book b4(b2);
    cout << "Copied book: " << b4.GetAuthor() << " - " << b4.GetTitle() << endl;
    cout << "Bookmarks count: " << b4.GetBookmarkCount() << endl;
    
    cout << "\n=== Test 5: Assignment Operator ===" << endl;
    b1 = b2;
    cout << "Assigned book: " << b1.GetAuthor() << " - " << b1.GetTitle() << endl;
    cout << "Bookmarks count: " << b1.GetBookmarkCount() << endl;
    
    cout << "\n=== Destructors will be called now ===" << endl;
    return 0;
}
