#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>

class Book
{
    public:
        Book(const std::string&, const std::string&, const std::string&);
        Book() = default;


        void setTitle(std::string);
        std::string getTitle() const;
        void setAuthor(std::string);
        std::string getAuthor() const;
        void setISBN(std::string);
        std::string getISBN() const;
    private:
        std::string m_title;
        std::string m_author;
        std::string m_isbn;
};

#endif //_BOOK_H_