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
  
  for (; i < len; ++i) {
    c = str[i];
    if (c >= '0' && c <= '9') {
      result = result * 10 + (c - '0');
    } else if (c == 'c' && i > 0) { // check that there is at least one digit
      goto unit;      
    } else if (c == '.') {
      break;
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
    } else if (c == 'c' && i > 1) {  // check that there is at least one digit besides '.'
      goto unit;
    } else {
      return 0;
    }
  }
  
unit:
  ++i;
  if (i < len) {
    c = str[i];
    if (c != 'm') {
      return 0;
    } 
  } else {
    return 0;
  }
  ++i;
  if (i < len) {
    return 0;
  } else {
    *pok = true;
  }

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
  assert(str_to_num("123cm", &ok) == 123 && ok);
  assert(str_to_num("err", &ok) == 0 && !ok);
  assert(str_to_num("", &ok) == 0 && !ok);
  assert(str_to_num("12.34", &ok) == 0 && !ok);
  assert(str_to_num("12.34cm", &ok) == 12.34 && ok);
  assert(str_to_num("12..34", &ok) == 0 && !ok);
  assert(str_to_num("cm", &ok) == 0 && !ok);
  assert(str_to_num(".cm", &ok) == 0 && !ok);
  assert(str_to_num("12cmm", &ok) == 0 && !ok);
  // assert(str_to_num("1.9999999999999999999", &ok) == 1.9999999999999999999 && ok); // result of function equals 2 

  
  string str = "";
  cout << "Enter doubles and units and '|' in the end: \n";
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
      }
      if (num > large) {
        cout << num << " the largest so far. \n";
        large = num;
      } 
    } else {
      cout << "'" << str << "' not a number.\n";
    }
  }
  
  cout << "The smallest value is: " << small << "\n";
  cout << "The largest value is: " << large << "\n"; 
}

