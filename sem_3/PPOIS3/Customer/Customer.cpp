#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Contact_Info.h"
#include "Product.h"
#include "Customer.h"
using namespace std;

Customer::Customer() : customer("Unknown") {}
Customer::Customer(const string& customer_name, const Contact_Info& contact, const vector<Product>& required_goods)
{
    if (customer_name.empty())
    {
        throw invalid_argument("Customer name cannot be empty.");
    }
    customer = customer_name;
    contInf_of_customer = contact;

    if (required_goods.empty())
    {
        throw invalid_argument("List of required goods cannot be empty.");
    }
    list_of_required_goods = required_goods;
}
void Customer::CustomerInfo() const
{
    cout << "Customer Name: " << customer << endl;
    cout << "Contact Info: " << endl;
    cout << "  Phone Number: " << contInf_of_customer.getTelephoneNumber() << endl;
    cout << "  Email: " << contInf_of_customer.getEmail() << endl;
    cout << "Required Goods: " << endl;

    if (list_of_required_goods.empty()) {
        cout << "  No products required." << endl;
    }
    else {
        for (const auto& product : list_of_required_goods)
        {
            cout << "  - " << product.getNameOfProduct() << endl;
        }
    }
}
