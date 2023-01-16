#pragma once

#include <iostream>
#include <string>

int get_int(std::istream& is,int low, int high,
        const std::string& greeting = "Please enter an integer in the range",
        const std::string& sorry = "Not in range, please try again");
