#include <gtest/gtest.h>
#include "Emploee.h"
#include "Contact_Info.h"


TEST(EmploeeTest, DefaultConstructor) 
{
    Emploee emploee;
    EXPECT_EQ(emploee.getPost(), ""); 
    EXPECT_DOUBLE_EQ(emploee.getRating(), 0.0); 
}

TEST(EmploeeTest, Constructor) 
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("John", "Doe", "male", contact, "Storekeeper", 7.5);
    EXPECT_EQ(emploee.getPost(), "Storekeeper");
    EXPECT_DOUBLE_EQ(emploee.getRating(), 7.5);
}


TEST(EmploeeTest, GetPostInfoStorekeeper)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("John", "Doe", "male", contact, "Storekeeper", 6.0);
    EXPECT_EQ(emploee.getPostInfo(), "Main responsibilities: receiving, placing and issuing goods; maintaining records in the warehouse; checking the quantity and quality of products.");
}
TEST(EmploeeTest, GetPostInfoWarehouseOperationsManager)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Jane", "Doe", "female", contact, "Warehouse Operations Manager", 8.5);
    EXPECT_EQ(emploee.getPostInfo(), "Main responsibilities: coordination of warehouse operations, distribution of tasks between employees, control over order fulfillment.");
}
TEST(EmploeeTest, GetPostInfoReceivingAndShippingSpecialist)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Alex", "Smith", "non-binary", contact, "Receiving and shipping specialist (receiver)", 9.0);
    EXPECT_EQ(emploee.getPostInfo(), "Main responsibilities: monitoring the process of acceptance and shipment of goods, preparation of accompanying documents.");
}
TEST(EmploeeTest, GetPostInfoGeneralPost) 
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Taylor", "Brown", "female", contact, "Custom Post", 7.0);
    EXPECT_EQ(emploee.getPostInfo(), "General responsibilities: Custom Post");
}


TEST(EmploeeTest, AccessToConfidentialDocsManager) 
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("John", "Doe", "male", contact, "Warehouse Operations Manager", 7.5);
    EXPECT_TRUE(emploee.checkingAccessToConfidentialDocs());
}
TEST(EmploeeTest, AccessToConfidentialDocsSpecialist) 
{
    ContactInfo contact("+1234567890123", "test@example.com");
    Emploee emploee("Jane", "Doe", "female", contact, "Receiving and shipping specialist (receiver)", 8.5);
    EXPECT_TRUE(emploee.checkingAccessToConfidentialDocs());
}


TEST(EmploeeTest, NoAccessToConfidentialDocsStorekeeper) {
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Alex", "Smith", "non-binary", contact, "Storekeeper", 6.0);
    EXPECT_FALSE(emploee.checkingAccessToConfidentialDocs());
}

TEST(EmploeeTest, NoAccessToConfidentialDocsGeneralPost) {
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Taylor", "Brown", "female", contact, "Custom Post", 7.0);
    EXPECT_FALSE(emploee.checkingAccessToConfidentialDocs());
}


TEST(EmploeeTest, CertificatePerformanceExcellent)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("John", "Doe", "male", contact, "Storekeeper", 8.5);
    EXPECT_EQ(emploee.getCertificatePerformance(), "Excellent performance!");
}
TEST(EmploeeTest, CertificatePerformanceGood)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Jane", "Doe", "female", contact, "Storekeeper", 6.0);
    EXPECT_EQ(emploee.getCertificatePerformance(), "Good performance, but there is room for improvement.");
}
TEST(EmploeeTest, CertificatePerformanceNeedsImprovement)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Alex", "Smith", "non-binary", contact, "Storekeeper", 4.0);
    EXPECT_EQ(emploee.getCertificatePerformance(), "Performance needs improvement.");
}


TEST(EmploeeTest, GetPost)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Taylor", "Brown", "female", contact, "Warehouse Operations Manager", 7.5);
    EXPECT_EQ(emploee.getPost(), "Warehouse Operations Manager");
}

TEST(EmploeeTest, GetRating) 
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Emploee emploee("Taylor", "Brown", "female", contact, "Storekeeper", 7.5);
    EXPECT_DOUBLE_EQ(emploee.getRating(), 7.5);
}
