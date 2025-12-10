#include "catch_amalgamated.hpp"
#include "library.cpp"
#include <sstream>
 
TEST_CASE("Library constructor initializes with zero books", "[constructor]") {
    Library library;
    REQUIRE(library.getCount() == 0);
    REQUIRE(library.getBooks() == nullptr);
}
 
TEST_CASE("Library addBook method adds a book to the collection", "[addBook]") {
    Library library;
    Book* book = new Book("Sample Title", "Sample Author", "123-456-789");
    library.addBook(book);
    REQUIRE(library.getCount() == 1);
    REQUIRE(library.getBooks()[0]->getTitle() == "Sample Title");
    REQUIRE(library.getBooks()[0]->getAuthor() == "Sample Author");
    REQUIRE(library.getBooks()[0]->getIsbn() == "123-456-789");
}
 
TEST_CASE("Library removeBook method removes a book from the collection", "[removeBook]") {
    Library library;
    Book* book1 = new Book("Title1", "Author1", "111-111-111");
    Book* book2 = new Book("Title2", "Author2", "222-222-222");
    library.addBook(book1);
    library.addBook(book2);
    library.removeBook(0);
    REQUIRE(library.getCount() == 1);
    REQUIRE(library.getBooks()[0]->getTitle() == "Title2");
    REQUIRE(library.getBooks()[0]->getAuthor() == "Author2");
    REQUIRE(library.getBooks()[0]->getIsbn() == "222-222-222");
}
 
TEST_CASE("Library removeBook method handles invalid index", "[removeBook]") {
    Library library;
    Book* book = new Book("Sample Title", "Sample Author", "123-456-789");
    library.addBook(book);
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
 
    library.removeBook(1);
 
    std::cout.rdbuf(p_cout_streambuf);
    REQUIRE(oss.str() == "Invalid index\n");
    REQUIRE(library.getCount() == 1);
}
 
TEST_CASE("Library destructor frees all memory", "[destructor]") {
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
 
    {
        Library library;
        Book* book1 = new Book("Title1", "Author1", "111-111-111");
        Book* book2 = new Book("Title2", "Author2", "222-222-222");
        library.addBook(book1);
        library.addBook(book2);
    }
 
    std::cout.rdbuf(p_cout_streambuf);
    REQUIRE(oss.str() == "Destroying book: Title1\nDestroying book: Title2\nLibrary destroyed\n");
}