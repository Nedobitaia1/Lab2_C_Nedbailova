#include <vector>
#include <list>
#include "Book.hpp"
#include <iostream>

void processBooks(const std::vector<Book>& books) {
    std::cout << "-----processBooks: -----" << std::endl;
    for (const auto& book : books) {
        book.printBookInfo();
    }
    std::cout << "-----processBooks end -----" << std::endl;
}

Book createBook() {
    std::cout << "-----createBook: -----" << std::endl;
    return Book("And Quiet Flows the Don", "Mikhail Sholokhov", 1928);
    std::cout << "-----createBook end -----" << std::endl;
}

Book& getBookByIndex(std::vector<Book>& books, size_t index) {
    return books[index];  
}


Book getBook(Book book) {
    std::cout << "-----getBook-----" << std::endl;
    book.setTitle(book.getTitle() + " - Special Edition");
    std::cout << "Processing book: ";
    book.printBookInfo();
    std::cout << "-----getBook end-----" << std::endl;
    return book; 
}

int main() {

    std::cout << "-----Static-----" << std::endl;
    Book book1("Crime and Punishment", "Fyodor Dostoevsky", 1866);  
    book1.printBookInfo();
    getBook(book1);


    std::cout << "-----Dynamic-----" << std::endl;
    Book* book2 = new Book("Anna Karenina", "Leo Tolstoy", 1877);  
    book2->printBookInfo();
    delete book2;  


    std::cout << "-----Standard vector block-----" << std::endl;
    std::vector<Book> bookVector;
    bookVector.push_back(Book("The Master and Margarita", "Mikhail Bulgakov", 1967)); 
    bookVector.push_back(Book("War and Peace", "Leo Tolstoy", 1869));  
    bookVector.push_back(Book("Pride and Prejudice", "Jane Austen", 1813));
    bookVector.push_back(Book("1984", "George Orwell", 1949));
    bookVector.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    bookVector.push_back(Book("Moby-Dick", "Herman Melville", 1851));
    processBooks(bookVector);  
    std::cout << "-----Standard vector block end-----" << std::endl;


    std::cout << "-----Standard list block-----" << std::endl;
    std::list<Book> bookList;
    bookList.push_back(Book("Eugene Onegin", "Alexander Pushkin", 1833)); 
    bookList.push_back(Book("A Hero of Our Time", "Mikhail Lermontov", 1840)); 
    bookList.push_back(Book("Dracula", "Bram Stoker", 1897));
    bookList.push_back(Book("Frankenstein", "Mary Shelley", 1818));
    bookList.push_back(Book("Brave New World", "Aldous Huxley", 1932));
    bookList.push_back(Book("War and Peace", "Leo Tolstoy", 1869));
    std::cout << "-----printBooks-----" << std::endl;
    for (const auto& book : bookList) {
        book.printBookInfo();
}
    std::cout << "-----Standard list block end-----" << std::endl;
    Book book3 = createBook();  
    book3.printBookInfo();  


    std::cout << "-----Return book from vector by id-----" << std::endl;
    Book& bookFromVector = getBookByIndex(bookVector, 0);      
    bookFromVector.printBookInfo(); 
 
    std::cout << "-----Assignment operator without moving-----" << std::endl;
    Book book4("The Brothers Karamazov", "Fyodor Dostoevsky", 1880);  
    book4 = book1; 
    book4.printBookInfo(); 




    std::cout << "-----Assignment operator with moving-----" << std::endl;
    Book book5("Dead Souls", "Nikolai Gogol", 1842); 
    book5 = std::move(book4); 
    book5.printBookInfo(); 


    std::cout << "-----Copy constructor-----" << std::endl;
    Book book6 = book5; 
    book6.printBookInfo(); 


}
