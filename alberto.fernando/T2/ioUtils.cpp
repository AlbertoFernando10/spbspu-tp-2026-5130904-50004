#include "io_utils.hpp"

#include <cctype>
#include <istream>
#include <string>
std::istream&
alberto::operator>>(std::istream& in, ExpectChar ec)
{
  char c = '\0';
  if (in >> c && c != ec.expected_) {
    in.setstate(std::ios::failbit);
  }
  return in;
}
