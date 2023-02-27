#include "std_lib_facilities.h"
#include <assert.h>
#include <limits>

double str_to_num(string str, bool* pok) {
  int len = str.length();
  *pok = false;
  if (len == 0) {
    return 0; 
  } 
  
  double result = 0;
  int i = 0;
  char c;
  double exp = 1;
  
  constexpr double CM_TO_M = 0.01; // convert centimeters to meters
  constexpr double FT_TO_M = 0.3048; // convert feet to meters
  constexpr double IN_TO_M = 0.0254; // convert inches to meters

  for (; i < len; ++i) {
    c = str[i];
    if (c >= '0' && c <= '9') {
      result = result * 10 + (c - '0');
    } else if (c == '.') {
      break;
    } else if (i > 0) { // check that the number contains at least one digit
      goto unit;
    } else {
      return 0;
    }
  }
  
  ++i; // skip '.'
  for (; i < len; ++i) {
    c = str[i];
    if (c >= '0' && c <= '9') {
      exp *= 10;
      result += (c - '0') / exp;
    } else if (i > 2) { // check that the fractional part contains at least one digit
      goto unit;
    } else {
      return 0;
    }
  }
  
unit:
  if (i + 2 == len && str[i] == 'c' && str[i + 1] == 'm') {
    result *= CM_TO_M;
    goto ok;
  } else if (i + 2 == len && str[i] == 'f' && str[i + 1] == 't') {
    result *= FT_TO_M;
    goto ok;
  } else if (i + 2 == len && str[i] == 'i' && str[i + 1] == 'n') {
    result *= IN_TO_M;
    goto ok;
  } else if (i + 1 == len && str[i] == 'm') {
    goto ok;
  } else {
    return 0;
  }

ok:
  *pok = true;
  return result;
}

void print_vector(const vector<double>* pv) {
  cout << "Vector: ";
  for (double x : *pv) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  bool ok = true;
   
  assert(str_to_num("123", &ok) == 0 && !ok);
  assert(str_to_num("123cm", &ok) == 1.23 && ok);
  assert(str_to_num("err", &ok) == 0 && !ok);
  assert(str_to_num("", &ok) == 0 && !ok);
  assert(str_to_num("12.34", &ok) == 0 && !ok);
  assert(str_to_num("12.34cm", &ok) == 0.1234 && ok);
  assert(str_to_num("12..34", &ok) == 0 && !ok);
  assert(str_to_num("cm", &ok) == 0 && !ok);
  assert(str_to_num(".cm", &ok) == 0 && !ok);
  assert(str_to_num("12cmm", &ok) == 0 && !ok);
  assert(str_to_num("12.34in", &ok) == 0.313436 && ok);
  assert(str_to_num("12.34ft", &ok) == 3.761232 && ok);
  assert(str_to_num("12.34m", &ok) == 12.34 && ok);
  // assert(str_to_num("1.9999999999999999999", &ok) == 1.9999999999999999999 && ok);
  // result of function equals 2

  string str = "";
  cout << "Enter doubles and units and '|' in the end: \n";
  double small = numeric_limits<double>::max();
  double large = numeric_limits<double>::min();
  double sum = 0;
  int i_entered = 0;

  while (cin >> str) {
    if (str.length() == 1 && str[0] == '|') {
      break;
    }
    double num = str_to_num(str, &ok);
    if (ok) {
      cout << "Converted: " << str << " = " << num << "m.\n";
      sum += num;
      ++i_entered;
      if (num < small) {
        cout << num << " the smallest so far. \n";
        small = num;
      }
      if (num > large) {
        cout << num << " the largest so far. \n";
        large = num;
      } 
    } else {
      cout << "'" << str << "' not a number.\n";
    }
  }
  
  cout << "The smallest value is: " << small << " m" << "\n";
  cout << "The largest value is: " << large << " m" << "\n";
  cout << "The number of values: " << i_entered << "\n";
  cout << "Sum: "<< sum << " m\n";
}

