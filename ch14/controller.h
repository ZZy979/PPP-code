#pragma once

#include <string>

#include "Graph.h"

class Controller {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void set_level(int level) = 0;
    virtual std::string show() const = 0;
};

class Test_controller : public Controller {
public:
    void on() override;
    void off() override;
    void set_level(int level) override;
    std::string show() const override;

private:
    bool on_ = false;
    int level_ = 0;
};

class Line_color_controller : public Controller {
public:
    Line_color_controller(Graph_lib::Shape& shape) :shape_(shape) {}
    void on() override;
    void off() override;
    void set_level(int level) override;
    std::string show() const override;

private:
    Graph_lib::Shape& shape_;
};
