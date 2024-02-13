#include "clothing.h"

Clothing::Clothing(const std::string& category, const std::string& name, double price, int qty, const std::string& size, const std::string& brand)
    : Product(category, name, price, qty), size_(size), brand_(brand) {}

std::set<std::string> Clothing::keywords() const {
    std::set<std::string> keywords;
    keywords.insert(name_);
    keywords.insert(brand_);
    return keywords;
}

std::string Clothing::displayString() const {
    return name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
}

void Clothing::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << std::endl;
}

