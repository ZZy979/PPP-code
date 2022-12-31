#pragma once
#include <string>
#include <vector>

double maxv(const std::vector<double>& v);

struct Double_result {
    double min;
    double max;
    double mean;
    double median;
};

Double_result describe(std::vector<double> v);

struct String_result {
    std::string shortest;
    std::string longest;
    std::string min;
    std::string max;
};

std::vector<int> describe(const std::vector<std::string>& v, String_result& result);
