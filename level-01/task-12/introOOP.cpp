#include <iostream>
#include <string>

#include "Book.h"

int main()
{
    // Create an instance of the Book class
    Book book("The C++ Programming Language, 4th Edition", "Bjarne Stroustrup", "978-0275967307");

    // Display the initial attributes
    std::cout << "Initial attributes of the book:\n"
                 "Title: " << book.getTitle() << "\n"
                 "Author: " << book.getAuthor() << "\n"
                 "ISBN: " << book.getISBN() << std::endl;

    // Set new attributes for the book
    book.setTitle("Effective Modern C++: 42 Specific Ways to Improve Your Use of C++11 and C++14");
    book.setAuthor("Scott Meyers");
    book.setISBN("978-1491903995");

    // Display the updated attributes
    std::cout << "\nUpdated attributes of the book:\n"
                 "Title: " << book.getTitle() << "\n"
                 "Author: " << book.getAuthor() << "\n"
                 "ISBN: " << book.getISBN() << std::endl;

    return 0;
}