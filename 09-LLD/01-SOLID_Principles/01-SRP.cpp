#include<iostream>
#include<vector>

using namespace std;

class Product{
    public:
        string name;
        float price;

        Product(string sName, float fPrice) : name(sName), price(fPrice){}
};

class ShoppingCart{
    vector<Product*> products;
    public:
        ~ShoppingCart(){
            for(auto& product : products)
            {
                delete product;
            }
        }
        ShoppingCart()
        {
            cout<<"Shopping Cart Created !!\n";
        }

        vector<Product*>& getProducts()
        {
            return products;
        }

        void addProduct(Product* prod)
        {
            products.push_back(prod);
        }
        void addProduct(string sName, float fPrice)
        {
            products.push_back(new Product(sName, fPrice));
        }
};

class CartCalculation{
    ShoppingCart* sc;
    public:
        CartCalculation(ShoppingCart* scPtr = nullptr) : sc(scPtr){}
        float calculateTotalBill()
        {
            vector<Product*> products = sc->getProducts();
            float totalBill = 0.0;
            for(auto& product : products)
            {
                totalBill += product->price;
            }
            return totalBill;
        }
};

class InvoicePrinter{
    ShoppingCart* sc;
    public:
        InvoicePrinter(ShoppingCart* scPtr = nullptr) : sc(scPtr){}
        void printInvoice(CartCalculation* calc)
        {
            vector<Product*> products = sc->getProducts();
            float totalBill = 0.0;
            int i = 1;
            cout<<"\n ----- Invoice -----\n";
            for(auto& product : products)
            {
                cout<<"No."<<i++<<" "<<product->name<<" : "<<product->price<<"/-\n";
            }
            cout << "-------------------\n";
            cout << "Final Bill: " << calc->calculateTotalBill() << "/-\n";
            cout << "--- Visit Again ---\n\n";
        }
};

class Shopping{
    ShoppingCart* sc;
    InvoicePrinter* invPtr;
    CartCalculation* calc;
    public:
        ~Shopping(){
            delete calc;
            delete invPtr;
            delete sc;
        }
        Shopping()
        {
            sc = new ShoppingCart();
            if(sc)
            {
                invPtr = new InvoicePrinter(sc);
                calc = new CartCalculation(sc);
            }
        }

        void addToCart(string sName, float fPrice)
        {
            sc->addProduct(sName, fPrice);
        }

        void printInvoice()
        {
            invPtr->printInvoice(calc);
        }
};


int main()
{
    Shopping obj;
    obj.addToCart("Apple", 250);
    obj.addToCart("Eggs", 150);
    obj.addToCart("Milk", 50);

    obj.printInvoice();
}
