#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// 1. Data Model (Only holds data)
class Product {
public:
    string name;
    float price;
    Product(string sName, float fPrice) : name(sName), price(fPrice) {}
};

// 2. Cart Management (Only manages the collection of products)
class ShoppingCart {
    vector<Product> products; // Use objects (or smart pointers) to avoid manual raw pointer memory leaks
public:
    const vector<Product>& getProducts() const {
        return products;
    }

    void addProduct(const Product& prod) {
        products.push_back(prod);
    }
};

// 3. Business Logic / Calculation (Only handles calculations)
class CartCalculator {
public:
    static float calculateTotal(const ShoppingCart& sc) {
        float total = 0.0f;
        for (const auto& product : sc.getProducts()) {
            total += product.price;
        }
        return total;
    }
};

// 4. Presentation / Printing (Only handles output formatting)
class InvoicePrinter {
public:
    static void print(const ShoppingCart& sc) {
        cout << "\n----- Invoice -----\n";
        int i = 1;
        for (const auto& product : sc.getProducts()) {
            cout << i++ << ". " << product.name << " : " << product.price << "/-\n";
        }
        
        float total = CartCalculator::calculateTotal(sc);
        cout << "-------------------\n";
        cout << "Final Bill: " << total << "/-\n";
        cout << "--- Visit Again ---\n\n";
    }
};

int main() {
    ShoppingCart cart;
    cart.addProduct(Product("Apple", 250));
    cart.addProduct(Product("Eggs", 150));
    cart.addProduct(Product("Milk", 50));

    InvoicePrinter::print(cart);

    return 0;
}