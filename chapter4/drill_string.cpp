#include "std_lib_facilities.h"
#include <assert.h>
#include <limits>

double str_to_num(string str, bool* pok) {

  if (str.empty()) {
    *pok = false;
    return 0; 
  } 
  double result = 0;
  int i = 0;
  for (; i < str.length(); ++i) {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      result = result * 10 + (c - '0');
    } else if (c == '.') {
      break;
    } else {
      *pok = false;
      return 0;
    }
  }
  ++i; // skip '.'
  double exp = 1;
  for (; i < str.length(); ++i) {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      exp *= 10;
      result += (c - '0') / exp;
    } else {
      *pok = false;
      return 0;
    }
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
   
  assert(str_to_num("123", &ok) == 123 && ok);
  assert(str_to_num("err", &ok) == 0 && !ok);
  assert(str_to_num("", &ok) == 0 && !ok);
  assert(str_to_num("12.34", &ok) == 12.34 && ok);
  assert(str_to_num("12..34", &ok) == 0 && !ok);
  // assert(str_to_num("1.9999999999999999999", &ok) == 1.9999999999999999999 && ok); // result of function equals 2 
  
  string str = "";
  cout << "Enter doubles and '|' in the end: \n";
  double small = numeric_limits<double>::max();
  double large = numeric_limits<double>::min();
  
  while (cin >> str) {
    if (str.length() == 1 && str[0] == '|') {
      break;
    }
    double num = str_to_num(str, &ok);
    if (ok) {
      if (num < small) {
        cout << num << " the smallest so far. \n";
        small = num;
      } else if (num > large) {
        cout << num << " the largest so far. \n";
        large = num;
      } else {
        cout << num << "\n";
      }
    } else {
      cout << "'" << str << "' not a number.\n";
    }
  }
  
  cout << "The smallest value is: " << small << "\n";
  cout << "The largest value is: " << large << "\n"; 
}

