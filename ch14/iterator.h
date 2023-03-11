#pragma once

#include <list>
#include <ostream>
#include <vector>

class Iterator {
public:
    virtual double* next() = 0;
};

class Vector_iterator : public Iterator {
public:
    Vector_iterator(std::vector<double>& v) :it(v.begin()), end(v.end()) {}
    double* next() override;

private:
    std::vector<double>::iterator it, end;
};

class List_iterator : public Iterator {
public:
    List_iterator(std::list<double>& l) :it(l.begin()), end(l.end()) {}
    double* next() override;

private:
    std::list<double>::iterator it, end;
};

void print(std::ostream& os, Iterator& it);
