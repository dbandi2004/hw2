#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <map>
#include <vector>
#include <string>
#include <set>

class MyDataStore : public DataStore 
{
public:
    MyDataStore();
    virtual ~MyDataStore();
    void addProduct(Product* p) override;
    void addUser(User* u) override;
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;
    void addToCart(std::string username, Product* p);
    void viewCart(std::string username);
    void buyCart(std::string username);

private:
    std::map<std::string, std::set<Product*>> keywordToProducts;
    std::map<std::string, User*> users;
    std::map<std::string, std::vector<Product*>> userCarts;
    std::set<Product*> allProducts;
};

#endif // MYDATASTORE_H
