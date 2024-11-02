#include <gtest/gtest.h>
#include "Reservation.h"
#include "Tour.h"
#include "Payment.h"
#include "Comment.h"
#include "Country.h"
#include "Discount.h"
#include "Hotel.h"
#include "Excursion.h"
#include "Person.h"
#include "Emploee.h"


TEST(ReservationTest, Constructor) {
    Reservation reservation;
    EXPECT_EQ(reservation.transcriptStatus(), "Unknown status"); 
    EXPECT_EQ(reservation.listOfTours().size(), 0);
}

/*TEST(ReservationTest, ParConstructor) {
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
    Reservation reservation("10", "CONF", tours, payment, comment);

    EXPECT_EQ(reservation.transcriptStatus(), "Confirmed");
    EXPECT_EQ(reservation.listOfTours(), tours);
}*/

TEST(ReservationTest, TranscriptStatusUnknown) {
    Reservation reservation("54321", "PEND", {}, Payment(), Comment());
    EXPECT_EQ(reservation.transcriptStatus(), "Unknown status"); 
}

TEST(ReservationTest, TranscriptStatusCancelled) {
    Reservation reservation("54321", "CANC", {}, Payment(), Comment());
    EXPECT_EQ(reservation.transcriptStatus(), "Cancelled"); 
}

TEST(ReservationTest, ListOfToursEmpty) {
    Reservation reservation("54321", "CONF", {}, Payment(), Comment());
    EXPECT_EQ(reservation.listOfTours().size(), 0); 
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}