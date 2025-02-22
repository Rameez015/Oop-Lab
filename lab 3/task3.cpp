// Library class
#include <iostream>
#include <vector>
#include <string>

class Library
{
private:
    std::vector<std::string> bookList;
    std::vector<std::string> borrowedBooks;
    std::vector<std::string> availableBooks;

public:
    void addBook(const std::string &book)
    {
        bookList.push_back(book);
        availableBooks.push_back(book);
    }

    void lendBook(const std::string &book)
    {
        for (auto &availableBook : availableBooks)
        {
            if (availableBook == book)
            {
                borrowedBooks.push_back(book);
                availableBooks.erase(std::remove(availableBooks.begin(), availableBooks.end(), book), availableBooks.end());
                std::cout << book << " has been lent out." << std::endl;
                return;
            }
        }
        std::cout << book << " is not available." << std::endl;
    }

    void returnBook(const std::string &book)
    {
        for (auto &borrowedBook : borrowedBooks)
        {
            if (borrowedBook == book)
            {
                availableBooks.push_back(book);
                borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), book), borrowedBooks.end());
                std::cout << book << " has been returned." << std::endl;
                return;
            }
        }
        std::cout << book << " was not borrowed." << std::endl;
    }

    void displayAvailableBooks()
    {
        std::cout << "Available Books: ";
        for (const auto &book : availableBooks)
        {
            std::cout << book << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Library lib;
    lib.addBook("1984");
    lib.addBook("To Kill a Mockingbird");
    lib.lendBook("1984");
    lib.displayAvailableBooks();
    lib.returnBook("1984");
    lib.displayAvailableBooks();
    return 0;
}