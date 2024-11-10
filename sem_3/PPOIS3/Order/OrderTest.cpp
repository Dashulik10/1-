#include <gtest/gtest.h>
#include "Order.h"
#include "Product.h"
#include "Supplier.h"
#include "Date.h"
#include "Climate_Placement.h"
#include "Storage_Conditions.h"


TEST(OrderTest, DefaultConstructor)
{
    Order order;
    EXPECT_EQ(order.getOrderInfo().find("Order Number: 0000"), 0);
    EXPECT_EQ(order.getOrderInfo().find("Order Status: Pending"), order.getOrderInfo().find("Order Status: Pending"));
    EXPECT_EQ(order.getStatusDescription(), "Order is pending and not yet processed.");
}

TEST(OrderTest, IsDeliveredOnTime) 
{
    Supplier supplier("Supplier Name", ContactInfo("000-111-222", "supplier@domain.com"), "General", 6.0);
    Product product("ProductA", "CategoryA", 7.5, Storage_Conditions());
    vector<Product> products = { product };
    Date creation_date(20, 10, 2023);
    Date delivery_date(25, 10, 2023);

    Order order("D123", 5, creation_date, supplier, products);

    EXPECT_TRUE(order.isDeliveredOnTime(delivery_date));

    Date late_date(26, 10, 2025);
    EXPECT_FALSE(order.isDeliveredOnTime(late_date));
}

TEST(OrderTest, UpdateOrderStatus)
{
    Supplier supplier("Quick Supplier", ContactInfo("321-654-987", "quick@supplier.com"), "Perishable", 9.0);
    Product product("Milk", "Dairy", 8.0, Storage_Conditions());
    vector<Product> products = { product };
    Date creation_date(1, 10, 2023);
    Date on_time_date(3, 10, 2023);

    Order order("Q123", 3, creation_date, supplier, products);

    order.updateOrderStatus(on_time_date);
    EXPECT_EQ(order.getStatusDescription(), "Order was delivered within the expected timeframe.");

    Date late_date(10, 10, 2023);
    order.updateOrderStatus(late_date);
    EXPECT_EQ(order.getStatusDescription(), "Order was delivered later than expected.");
}


TEST(OrderTest, GetOrderInfo) 
{
    Supplier supplier("Reliable Supplier", ContactInfo("555-000-111", "reliable@supplier.com"), "Electronics", 8.5);
    Product product1("Smartphone", "Electronics", 9.1, Storage_Conditions());
    Product product2("Tablet", "Electronics", 8.7, Storage_Conditions());
    vector<Product> products = { product1, product2 };
    Date creation_date(25, 9, 2023);

    Order order("O789", 7, creation_date, supplier, products);

    string order_info = order.getOrderInfo();

    EXPECT_NE(order_info.find("Order Number: O789"), string::npos);
    EXPECT_NE(order_info.find("Order Status: Pending"), string::npos);
    EXPECT_NE(order_info.find("Reliable Supplier"), string::npos);
    EXPECT_NE(order_info.find("Smartphone"), string::npos);
    EXPECT_NE(order_info.find("Tablet"), string::npos);
    EXPECT_NE(order_info.find("Expected Delivery Days: 7"), string::npos);
}
