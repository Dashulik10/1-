#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Date.h"
#include "Product.h"
#include "Supplier.h"
#include "Order.h"
using namespace std;

Order::Order() : number_of_order("0000"), days_for_delivery(0), date_of_creation_order(Date()), status_of_order("Pending") {}
Order::Order(const string& order_number, int delivery_days, const Date& creation_date, const Supplier& supplier, const vector<Product>& products)
    : number_of_order(order_number), days_for_delivery(delivery_days), date_of_creation_order(creation_date), status_of_order("Pending"), supplier_of_order(supplier), product_for_order(products)
{
    if (order_number.empty())
    {
        throw invalid_argument("Order number cannot be empty.");
    }
    if (delivery_days < 0)
    {
        throw invalid_argument("Days for delivery cannot be negative.");
    }
    if (products.empty())
    {
        throw invalid_argument("Order must contain at least one product.");
    }
}

bool Order::isDeliveredOnTime(const Date& current_date) const
{
    Date expected_delivery_date = date_of_creation_order;
    expected_delivery_date = expected_delivery_date + days_for_delivery;
    return current_date <= expected_delivery_date;
}
bool Order::updateOrderStatus(const Date& current_date)
{
    if (isDeliveredOnTime(current_date))
    {
        status_of_order = "Delivered on time";
    }
    else
    {
        status_of_order = "Late delivery";
    }
    return true;
}
string Order::getStatusDescription() const
{
    if (status_of_order == "Pending")
    {
        return "Order is pending and not yet processed.";
    }
    else if (status_of_order == "Delivered on time")
    {
        return "Order was delivered within the expected timeframe.";
    }
    else if (status_of_order == "Late delivery")
    {
        return "Order was delivered later than expected.";
    }
    else
    {
        return "Unknown status.";
    }
}
string Order::getOrderInfo() const
{
    string info = "Order Number: " + number_of_order + "\n";
    info += "Order Status: " + status_of_order + "\n";
    info += "Expected Delivery Days: " + to_string(days_for_delivery) + "\n";
    info += "Order Creation Date: " + date_of_creation_order.getDayMonthYear() + "\n";
    info += "Supplier: " + supplier_of_order.getNameOfSupplier() + "\n";

    info += "Products in Order:\n";
    for (const auto& product : product_for_order)
    {
        info += " - " + product.getNameOfProduct() + " (" + product.getCategory() + ")\n";
    }

    info += "Status Description: " + getStatusDescription() + "\n";
    return info;
}