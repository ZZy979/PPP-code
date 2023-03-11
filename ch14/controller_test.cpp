#include <gtest/gtest.h>

#include "Graph.h"
#include "controller.h"

TEST(ControllerTest, TestController) {
    Test_controller controller;
    EXPECT_EQ(controller.show(), "off");

    controller.on();
    EXPECT_EQ(controller.show(), "0");

    controller.set_level(8);
    EXPECT_EQ(controller.show(), "8");

    controller.off();
    EXPECT_EQ(controller.show(), "off");
}

TEST(ControllerTest, LineColorController) {
    Graph_lib::Circle circle(Point(100, 100), 50);
    Line_color_controller controller(circle);

    controller.set_level(Graph_lib::Color::blue);
    EXPECT_EQ(circle.color().as_int(), Graph_lib::Color::blue);
    EXPECT_EQ(controller.show(), std::to_string(Graph_lib::Color::blue));

    controller.off();
    EXPECT_FALSE(circle.color().visibility());
    EXPECT_EQ(controller.show(), "invisible");

    controller.on();
    EXPECT_TRUE(circle.color().visibility());
    EXPECT_EQ(circle.color().as_int(), Graph_lib::Color::blue);
    EXPECT_EQ(controller.show(), std::to_string(Graph_lib::Color::blue));
}
