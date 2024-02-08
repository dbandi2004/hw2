#include "book.h"

Book::Book(const std::string& category, const std::string& name, double price, int qty, const std::string& isbn, const std::string& author)
    : Product(category, name, price, qty), isbn_(isbn), author_(author) {}

std::set<std::string> Book::keywords() const {
    std::set<std::string> keywords;
    keywords.insert(author_);
    keywords.insert(name_);
    return keywords;
}

std::string Book::displayString() const {
    return name + "\nAuthor: " + author + " ISBN: " + isbn + "\n" + std::to_string(price) + " " + std::to_string(qty) + " left.";
}

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\nISBN: " << isbn_ << "\nAuthor: " << author_ << std::endl;
}
