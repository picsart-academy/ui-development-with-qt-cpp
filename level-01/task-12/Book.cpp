#ifndef _BOOK_CPP_
#define _BOOK_CPP_

#include "Book.h"

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
        : m_title(title), m_author(author), m_isbn(isbn) {}

void Book::setTitle(std::string title)
{
    m_title = std::move(title);
}

std::string Book::getTitle() const
{
    return m_title;
}

void Book::setAuthor(std::string author)
{
    m_author = std::move(author);
}

std::string Book::getAuthor() const
{
    return m_author;
}

void Book::setISBN(std::string isbn)
{
    m_isbn = std::move(isbn);
}

std::string Book::getISBN() const
{
    return m_isbn;
}

#endif //_BOOK_CPP_