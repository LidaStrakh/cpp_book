// https://en.cppreference.com/w/cpp/language/operator_precedence
#include "std_lib_facilities.h"

int main() {
  cout << 4 - 5 - 6 << "\n"; // -7 
  cout << 4 - (5 - 6) << "\n"; // 5
  cout << 4 + 5 * 6 << "\n"; // 34
  cout << (4 + 5) * 6 << "\n"; // 54
  cout << 30 / 5 * 6 << "\n"; // 36
  cout << 30 / (5 * 6) << "\n"; // 1
  cout << 16 / 4 / 2 << "\n"; // 2
  cout << 16 / (4 / 2) << "\n"; // 8
  cout << 13 / 6 % 5 << "\n"; // 2    n = k*m + r  n=2 m=5 2 = k*5 + r
  cout << 13 / (6 % 5) << "\n"; // 13
  int n = 16;
  cout << ++n << "\n"; // 17 
  cout << n++ << "\n"; // 17
  cout << n << "\n"; // 18
  cout << ++ ++n << "\n"; // 20 
  cout << ++++ ++n << "\n"; // 23 
  // cout << (n++ ++) << "\n"; // error: lvalue required as increment operand
  cout << (n = 1) + 5 << "\n";
  cout << (n = 1 + 5) << "\n";
  cout << n << "\n";
  cout << n++ * 2 << "\n"; // 12
  n = n = n = 6;
  cout << n << "\n";
  cout << ++(n = n + 1) << "\n"; // 8
  cout << ((n += 5) *= 2)  << "\n"; // 26
  cout << ((n += 5) += 2)  << "\n"; //
  //cout << n += 5 << "\n"; // error: operator << has higher precedence than operator +=
  return 0;
}
