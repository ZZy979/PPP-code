#pragma once

#include <unordered_set>
#include <string>

bool is_one_argument_function(const std::string& name);
bool is_two_argument_function(const std::string& name);
bool is_function_name(const std::string& name);
double calculate_function(const std::string& name, double x, double y = 0.0);
