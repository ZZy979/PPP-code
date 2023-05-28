#pragma once

#include <string>

char* strdup_(const char* s);
const char* findx(const char* s, const char* x);
int strcmp_(const char* s1, const char* s2);

std::string cat_dot(const std::string& s1, const std::string& s2, const std::string& separator = ".");
char* cat_dot(const char* s1, const char* s2, const char* separator = ".");
