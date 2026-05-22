#include "datastruct.hpp"

#include <cctype>
#include <cmath>
#include <iomanip>
#include <istream>
#include <ostream>
#include <string>
#include <utility>

#include "io_utils.hpp"

namespace alberto {
namespace detail {
bool readToken(std::istream& in, std::string& token)
{
  token.clear();
  char c = '\0';
  while (in.get(c)) {
    if (c == ':' || c == ')') {
      in.putback(c);
      break;
    }
    token += c;
  }
  return !token.empty();
}

bool parseSignedLongLit(const std::string& token, long long& value)
{
  if (token.size() < 3) {
    return false;
  }
  const size_t sz = token.size();
  const char   l1 = static_cast< char >(std::tolower(
      static_cast< unsigned char >(token[sz - 2])));
  const char   l2 = static_cast< char >(std::tolower(
      static_cast< unsigned char >(token[sz - 1])));
  if (l1 != 'l' || l2 != 'l') {
    return false;
  }
  const std::string digits = token.substr(0, sz - 2);
  if (digits.empty()) {
    return false;
  }
  const size_t start = (digits[0] == '-') ? 1 : 0;
  if (start == digits.size()) {
    return false;
  }
  for (size_t i = start; i < digits.size(); ++i) {
    if (!std::isdigit(static_cast< unsigned char >(digits[i]))) {
      return false;
    }
  }
  try {
    value = std::stoll(digits);
  } catch (...) {
    return false;
  }
  return true;
}
