#include <gtest/gtest.h>
#include "Tour.h"
#include "Country.h"
#include "Excursion.h"
#include "Hotel.h"
#include "Discount.h"

TEST(TourTest, Constructor) {
    Tour tr;
    EXPECT_TRUE(tr.excursionList().empty()); 
}

TEST(TourTest, ParConstructor) {
    Country cr("France", "FR");
    Discount dis(10);
    Hotel ht("Hotel Paris", ContactInfo("+375259689451", "dasha@mail.com"), 200.0, 4.5);
    
    Excursion exc1("Eiffel Tower Tour", "Visit the iconic Eiffel Tower", Guide());
    Excursion exc2("Louvre Museum Tour", "Explore the famous Louvre Museum", Guide());
    
    vector<Excursion> exc = {exc1, exc2};
    Tour tr("Paris Trip", cr, exc, ht, dis);
    
    EXPECT_EQ(tr.excursionList().size(), 2);
    EXPECT_EQ(tr.excursionList()[0], "Eiffel Tower Tour");
    EXPECT_EQ(tr.excursionList()[1], "Louvre Museum Tour");
}

TEST(TourTest, Empty) {
    Country cr("Italy", "IT");
    Discount dis(5); 
    Hotel ht("Rome Hotel", ContactInfo("+375259689451", "dasha@mail.com"), 150.0, 4.0);
    vector<Excursion> exc;
    Tour tr("Rome Trip", cr, exc, ht, dis);
    
    EXPECT_TRUE(tr.excursionList().empty());
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}