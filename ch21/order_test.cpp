#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "order.h"

TEST(PurchaseTest, InputFail) {
    std::vector<std::string> input = {"}", R"({"apple" 6.23 2})", R"(["apple" 6.23 2])", R"("apple" 6.23 2)"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Purchase p;
        EXPECT_FALSE(iss >> p);
        EXPECT_TRUE(iss.fail());
    }
}

TEST(PurchaseTest, InputBadFormat) {
    std::vector<std::string> input = {
        "", "(", R"(("apple")", R"(("apple" 6.23)", R"(("apple" 6.23 2)", R"(("apple" 6.23 2})",
        R"(("apple",6.23,2))", R"(("apple" "banana" 2))", R"(("apple" 6.23))", "()", R"(("apple 6.23 2))"
    };
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Purchase p;
        EXPECT_THROW(iss >> p, std::runtime_error);
    }
}

TEST(PurchaseTest, InputSuccess) {
    std::vector<std::string> input = {R"(("apple" 6.23 2))", R"(  ( "apple" 6.23 2  ) )", "(\"apple\"\t6.23\n2)"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Purchase p;
        EXPECT_TRUE(iss >> p);
        EXPECT_EQ(p.product_name, "apple");
        EXPECT_DOUBLE_EQ(p.unit_price, 6.23);
        EXPECT_EQ(p.count, 2);
    }
}

TEST(PurchaseTest, Output) {
    Purchase p{"apple", 6.23, 2};
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), R"(("apple" 6.23 2))");
}

TEST(PurchaseTest, GetValue) {
    Purchase p{"apple", 6.23, 2};
    EXPECT_DOUBLE_EQ(get_purchase_value(p), 12.46);
}

TEST(OrderTest, InputFail) {
    std::vector<std::string> input = {
        "", R"(("Alice" "Washington" 1234))", R"(["Alice" "Washington" 1234])", R"("Alice" "Washington" 1234)"
    };
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Order o;
        EXPECT_FALSE(iss >> o);
        EXPECT_TRUE(iss.fail());
    }
}

TEST(OrderTest, InputBadStart) {
    std::vector<std::string> input = {"{", R"({"Alice")", R"({"Alice" "Washington")", R"({"Alice" "Washington" "1234)"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Order o;
        EXPECT_THROW(iss >> o, std::runtime_error);
    }
}

TEST(OrderTest, InputBadEnd) {
    std::vector<std::string> input = {
        R"({ "Alice" "Washington" "1234" ("apple" 6.23 2) ))",
        R"({ "Alice" "Washington" "1234" ("apple" 6.23 2) ])",
        R"({ "Alice" "Washington" "1234" ("apple" 6.23 2) $)",
        R"({ "Alice" "Washington" "1234" ("apple" 6.23 2))"
    };
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Order o;
        EXPECT_THROW(iss >> o, std::runtime_error);
    }
}

TEST(OrderTest, InputSuccess) {
    std::istringstream iss(R"({ "Alice" "Washington" "1234" ("apple" 6.23 2) ("banana" 7.3 1) })");
    Order o;
    EXPECT_TRUE(iss >> o);
    EXPECT_EQ(o.customer_name, "Alice");
    EXPECT_EQ(o.address, "Washington");
    EXPECT_EQ(o.phone_number, "1234");

    EXPECT_EQ(o.purchase.size(), 2);
    EXPECT_EQ(o.purchase[0].product_name, "apple");
    EXPECT_DOUBLE_EQ(o.purchase[0].unit_price, 6.23);
    EXPECT_EQ(o.purchase[0].count, 2);
    EXPECT_EQ(o.purchase[1].product_name, "banana");
    EXPECT_DOUBLE_EQ(o.purchase[1].unit_price, 7.3);
    EXPECT_EQ(o.purchase[1].count, 1);

    iss.str(R"({ "Bob Smith" "New York" "5678" })");
    Order o2;
    EXPECT_TRUE(iss >> o2);
    EXPECT_EQ(o2.customer_name, "Bob Smith");
    EXPECT_EQ(o2.address, "New York");
    EXPECT_EQ(o2.phone_number, "5678");
    EXPECT_TRUE(o2.purchase.empty());
}

TEST(OrderTest, Output) {
    Order o{"Alice", "Washington", "1234", {{"apple", 6.23, 2}, {"banana", 7.3, 1}}};
    std::ostringstream oss;
    oss << o;
    EXPECT_EQ(oss.str(), R"({ "Alice" "Washington" "1234" ("apple" 6.23 2) ("banana" 7.3 1) })");
}

TEST(OrderTest, GetValue) {
    Order o{"Alice", "Washington", "1234", {{"apple", 6.23, 2}, {"banana", 7.3, 1}}};
    EXPECT_DOUBLE_EQ(get_order_value(o), 19.76);
}

TEST(OrderTest, GetTotalValue) {
    std::vector<Order> vo = {
        {"Alice", "Washington", "1234", {{"apple", 6.23, 2}, {"banana", 7.3, 1}}},
        {"Bob", "Texas", "5678", {{"orange", 9.98, 5}, {"grape", 10.77, 2}}}
    };
    EXPECT_DOUBLE_EQ(get_total_value(vo.begin(), vo.end()), 91.2);
}
