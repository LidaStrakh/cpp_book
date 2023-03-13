#include "std_lib_facilities.h"
#include <assert.h>
#include <limits>

enum class Unit {
  METER,
  CENTIMETER,
  FOOT,
  INCH,
  ERROR,
  NONE
};

constexpr double CM_TO_M = 0.01; // convert centimeters to meters
constexpr double FT_TO_M = 0.3048; // convert feet to meters
constexpr double IN_TO_M = 0.0254; // convert inches to meters

Unit str_to_unit(string str, int i = 0) {
  int len = str.length();

  if (i + 1 == len && str[i] == 'm') {
    return Unit::METER;
  } else if (i + 2 == len && str[i] == 'c' && str[i + 1] == 'm') {
    return Unit::CENTIMETER;
  } else if (i + 2 == len && str[i] == 'f' && str[i + 1] == 't') {
    return Unit::FOOT;
  } else if (i + 2 == len && str[i] == 'i' && str[i + 1] == 'n') {
    return Unit::INCH;
  } else {
    return Unit::ERROR;
  }
}

double str_to_num(string str, bool* pok, Unit* unit) {
  const int len = str.length();
  *pok = false;
  *unit = Unit::NONE;

  if (len == 0) {
    return 0; 
  } 
  
  double result = 0;
  int i = 0;
  char c;
  double exp = 1;
  bool have_unit = false;
  bool have_dot = false;

  for (; i < len; ++i) {
    c = str[i];
    if (c >= '0' && c <= '9') {
      result = result * 10 + (c - '0');
    } else if (c == '.') {
      have_dot = true;
      break;
    } else if (i > 0) { // check that the number contains at least one digit
      have_unit = true;
      break;
    } else {
      return 0;
    }
  }

  if (have_dot) {
    ++i; // skip '.'
    for (int j = i; i < len; ++i) {
      c = str[i];
      if (c >= '0' && c <= '9') {
        exp *= 10;
        result += (c - '0') / exp;
      } else if (i > j) { // check that the fractional part contains at least one digit
        have_unit = true;
        break;
      } else {
        return 0;
      }
    }
  }

  if (have_unit) {
    *unit = str_to_unit(str, i);
  }

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
  Unit unit;

  assert(str_to_num("123", &ok, &unit) == 123 && ok && unit == Unit::NONE);
  assert(str_to_num("123cm", &ok, &unit) == 123 && ok && unit == Unit::CENTIMETER);
  assert(str_to_num("err", &ok, &unit) == 0 && !ok);
  assert(str_to_num("", &ok, &unit) == 0 && !ok);
  assert(str_to_num("12.34", &ok, &unit) == 12.34 && ok && unit == Unit::NONE);
  assert(str_to_num("12.34cm", &ok, &unit) == 12.34 && ok && unit == Unit::CENTIMETER);
  assert(str_to_num("12..34", &ok, &unit) == 0 && !ok);
  assert(str_to_num("cm", &ok, &unit) == 0 && !ok);
  assert(str_to_num(".cm", &ok, &unit) == 0 && !ok);
  assert(str_to_num("12cmm", &ok, &unit) == 12 && ok && unit == Unit::ERROR);
  assert(str_to_num("12.34in", &ok, &unit) == 12.34 && ok && unit == Unit::INCH);
  assert(str_to_num("12.34ft", &ok, &unit) == 12.34 && ok && unit == Unit::FOOT);
  assert(str_to_num("12.34m", &ok, &unit) == 12.34 && ok && unit == Unit::METER);
  // assert(str_to_num("1.9999999999999999999", &ok) == 1.9999999999999999999 && ok);
  // result of function equals 2

  string str = "";
  cout << "Enter doubles and units and '|' in the end: \n";
  double small = numeric_limits<double>::max();
  double large = numeric_limits<double>::min();
  double num = 0;
  double sum = 0;
  int i_entered = 0;

  while (cin >> str) {
    if (str.length() == 1 && str[0] == '|') {
      break;
    }
    bool error = false;
    num = str_to_num(str, &ok, &unit);
    int num_orig = num;
    if (ok) {
      if (unit == Unit::NONE) {
        string s;
        cin >> s;
        unit = str_to_unit(s);
      }
      switch (unit) {
        case Unit::METER:
          cout << "Converted: " << num_orig << " m = " << num << "m.\n";
          break;
        case Unit::CENTIMETER:
          num *= CM_TO_M;
          cout << "Converted: " << num_orig << " cm = " << num << "m.\n";
          break;
        case Unit::FOOT:
          num *= FT_TO_M;
          cout << "Converted: " << num_orig << " ft = " << num << "m.\n";
          break;
        case Unit::INCH:
          num *= IN_TO_M;
          cout << "Converted: " << num_orig << " in = " << num << "m.\n";
          break;
        case Unit::ERROR:
          error = true;
          cout << "wrong unit.\n";
          break;
        case Unit::NONE:
          abort();
          break;
      }
    } else {
      error = true;
      cout << "'" << str << "' error.\n";
    }
    if (!error) {
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
    }
  }

  cout << "The smallest value is: " << small << " m" << "\n";
  cout << "The largest value is: " << large << " m" << "\n";
  cout << "The number of values: " << i_entered << "\n";
  cout << "Sum: "<< sum << " m\n";
}

