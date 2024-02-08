#include "movie.h"

Movie::Movie(const std::string& category, const std::string& name, double price, int qty, const std::string& genre, const std::string& rating)
    : Product(category, name, price, qty), genre_(genre), rating_(rating) {}

std::set<std::string> Movie::keywords() const {
    std::set<std::string> keywords;
    keywords.insert(name_);
    keywords.insert(genre_);
    return keywords;
}

std::string Movie::displayString() const {
    return name + "\nGenre: " + genre + " Rating: " + rating + "\n" + std::to_string(price) + " " + std::to_string(qty) + " left.";
}

void Movie::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\nGenre: " << genre_ << "\nRating: " << rating_ << std::endl;
}
