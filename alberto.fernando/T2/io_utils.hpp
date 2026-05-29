#ifndef IO_UTILS_HPP
#define IO_UTILS_HPP

#include <istream>

namespace alberto {

struct ExpectChar
{
  char expected_ = '\0';
  explicit ExpectChar(char c) : expected_(c) {}
};

struct ExpectStr
{
  const char* expected_ = nullptr;
  explicit ExpectStr(const char* s) : expected_(s) {}
};

std::istream& operator>>(std::istream& in, ExpectChar ec);
std::istream& operator>>(std::istream& in, ExpectStr es);

}

#endif
