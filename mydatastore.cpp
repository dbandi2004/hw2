#include "mydatastore.h"
#include "util.h"
#include <algorithm>

MyDataStore::MyDataStore() {}

MyDataStore::~MyDataStore() {
    for (auto& pair : users) {
        delete pair.second;
        pair.second = nullptr;
    }
    for (auto* product : allProducts) {  
        delete product;
        product = nullptr;
    }
}

void MyDataStore::addProduct(Product* p) {
    allProducts.insert(p);  
    std::set<std::string> keywords = p->keywords();
    for (const std::string& keyword : keywords) {
        keywordToProducts[keyword].insert(p);
    }
}

void MyDataStore::addUser(User* u) {
    users[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    std::set<Product*> result;
    if (!terms.empty()) {
        for (auto& term : terms) {
            term = convToLower(term); // Convert each term to lowercase before the search
        }
        
        auto termIt = terms.begin();
        if (keywordToProducts.find(*termIt) != keywordToProducts.end()) {
            result = keywordToProducts[*termIt];
        }
        ++termIt;

        for (; termIt != terms.end(); ++termIt) {
            if (keywordToProducts.find(*termIt) != keywordToProducts.end()) {
                std::set<Product*> tempResult = keywordToProducts[*termIt];
                if (type == 0) { 
                  // AND search
                    result = setIntersection(result, tempResult);
                } else if (type == 1) { 
                  // OR search
                    result = setUnion(result, tempResult);
                }
            }
        }
    }

    return std::vector<Product*>(result.begin(), result.end());
}

void MyDataStore::addToCart(std::string username, Product* p) {
    if (users.find(username) != users.end()) {
        userCarts[username].push_back(p);
    }
}

void MyDataStore::viewCart(std::string username) {
    if (userCarts.find(username) != userCarts.end()) {
        for (Product* p : userCarts[username]) {
            std::cout << p->displayString() << std::endl;
        }
    }
}
void MyDataStore::dump(std::ostream& os) {
    os << "<products>" << std::endl;
    for (const auto& keywordProductsPair : keywordToProducts) {
        for (const auto* product : keywordProductsPair.second) {
            product->dump(os);
        }
    }
    os << "</products>" << std::endl;
    
    os << "<users>" << std::endl;
    for (const auto& usernameUserPair : users) {
        usernameUserPair.second->dump(os);
    }
    os << "</users>" << std::endl;
}

void MyDataStore::buyCart(std::string username) {
    if (userCarts.find(username) != userCarts.end()) {
        auto& cart = userCarts[username];
        auto it = cart.begin();
        while (it != cart.end()) {
            Product* p = *it;
            if (p->getQty() > 0) {
                p->subtractQty(1);
                it = cart.erase(it);
            } else {
                ++it;
            }
        }
    }
}
