#include "mydatastore.h"
#include "book.h"
#include "user.h"
#include <iostream>

int main() {
    // Correct instantiation of a derived Product class
    Product* p1 = new Book("book", "C++ Primer", 39.99, 5, "123456789", "Lippman");

    // Correct instantiation of User class with expected three parameters
    User* u1 = new User("john_doe", 100.0, 0); // Assuming 0 is a valid type

    MyDataStore ds;
    ds.addProduct(p1);
    ds.addUser(u1);

    // Example of a search operation
    std::vector<std::string> terms = {"C++", "Primer"};
    auto results = ds.search(terms, 0); // AND search

    // Display search results
    std::cout << "Search Results:" << std::endl;
    for (auto* prod : results) {
        std::cout << prod->displayString() << std::endl;
    }

    // Clean up
    delete p1;
    delete u1;

    return 0;
}
