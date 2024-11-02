#include <gtest/gtest.h>
#include "Client.h"
#include "Person.h"
#include "Date.h"
#include "ContactInfo.h"
#include "Reservation.h"
#include "Country.h"
#include "Tour.h"
#include <vector>
#include <string>

using namespace std;

TEST(ClientTest, DefaultConstructor) {
    Client cl;
    EXPECT_EQ(cl.status_of_client, "");
    EXPECT_EQ(cl.client_reservation.size(), 0);
}

TEST(ClientTest, ParameterizedConstructor) {
    Country cr("France", "FR");
    Discount dis(10);
    Hotel ht("Hotel Paris", ContactInfo("+375259689451", "dasha@mail.com"), 200.0, 4.5);
    Excursion exc1("Eiffel Tower Tour", "Visit the iconic Eiffel Tower", Guide());
    Excursion exc2("Louvre Museum Tour", "Explore the famous Louvre Museum", Guide());
    vector<Excursion> exc = {exc1, exc2};
    Tour tr("Paris Trip", cr, exc, ht, dis);
    vector<Tour> tours = {tr};

    Payment payment(100.0, "Pending", dis);

    Comment comment("Excellent experience!", 5);

    ContactInfo contact("dasha@mail.com", "+375259689451");
    Date birthdate(2006, 10, 1); 
    Reservation res1("10", "CONF", tours, payment, comment);
    vector<Reservation> reservations = { res1 };


    Client client("John", "Doe", "Male", birthdate, contact, "Active", reservations);

    EXPECT_EQ(client.status_of_client, "Active");
    EXPECT_EQ(client.client_reservation.size(), 1);
    EXPECT_EQ(client.client_reservation[0].status_of_reservation, "CONF");
    EXPECT_EQ(client.setClientStatus(), "Active");
}


// Тестируем метод setClientStatus для неактивного клиента
/*TEST(ClientTest, SetClientStatusInactive) {
    ContactInfo contact("test@example.com", "1234567890");
    Date birthdate(1990, 1, 1);
    Reservation reservation("CANC", "Tour1", Date(2024, 5, 1));
    vector<Reservation> reservations = { reservation };

    Client client("John", "Doe", "Male", birthdate, contact, "", reservations);

    EXPECT_EQ(client.setClientStatus(), "Inactive");
}*/

// Тестируем метод bookTour
TEST(ClientTest, BookTour) {
    Country cr("France", "FR");
    Discount dis(10);
    Hotel ht("Hotel Paris", ContactInfo("+375259689451", "dasha@mail.com"), 200.0, 4.5);
    Excursion exc1("Eiffel Tower Tour", "Visit the iconic Eiffel Tower", Guide());
    Excursion exc2("Louvre Museum Tour", "Explore the famous Louvre Museum", Guide());
    vector<Excursion> exc = {exc1, exc2};
    Tour tr("Paris Trip", cr, exc, ht, dis);
    vector<Tour> tours = {tr};

    Payment payment(100.0, "Pending", dis);

    Comment comment("Excellent experience!", 5);

    ContactInfo contact("dasha@mail.com", "+375259689451");
    Date birthdate(2006, 10, 1); 
    Reservation res("10", "CONF", tours, payment, comment);
    vector<Reservation> reservations = {};


    Client client("John", "Doe", "Male", birthdate, contact, "Active", reservations);

    EXPECT_TRUE(client.bookTour(res));
    EXPECT_EQ(client.client_reservation.size(), 1);
    EXPECT_EQ(client.client_reservation[0].status_of_reservation, "CONF");
    EXPECT_EQ(client.setClientStatus(), "Active");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}