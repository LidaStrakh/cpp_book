#include "std_lib_facilities.h"
#include <assert.h>

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

int main() {
  bool ok = true;
   
  assert(str_to_num("123", &ok) == 123 && ok);
  assert(str_to_num("err", &ok) == 0 && !ok);
  assert(str_to_num("", &ok) == 0 && !ok);
  assert(str_to_num("12.34", &ok) == 12.34 && ok);
  assert(str_to_num("12..34", &ok) == 0 && !ok);
  // assert(str_to_num("1.9999999999999999999", &ok) == 1.9999999999999999999 && ok); // result of function equals 2 
  
  string str = "";
  vector<double> numbers;
  cout << "Enter two numbers and '|' in the end: \n";
  
  while (cin >> str) {
    if (str.length() == 1 && str[0] == '|') {
      break;
    }
    double num = str_to_num(str, &ok);
    if (ok) {
      numbers.push_back(num);   
    } else {
      cout << "'" << str << "' not a number.\n";
    }
  }
  if (numbers.size() < 2) {
    cout << "You entered too few numbers.\n";
  } else if (numbers.size() == 2) {
    cout << "You have entered: ";
    for ( double х : numbers) {
      cout << х << ", " ;
    }
    cout << "\n"; 
    sort(numbers);
    double first = numbers[0];
    double last = numbers[numbers.size() - 1];
    cout << "The smaller value is: " << first << "\n";
    cout << "The larger value is: " << last << "\n";
    if (first == last) {
      cout << "The numbers " << first << " and " << last << " are equal.\n";
    } else if (last -  first <= 1) {
      cout << "The numbers " << first << " and " << last << " are almost equal (differ by less than 1.0).\n";
    } else if (last -  first <= 100) {
      cout << "The numbers " << first << " and " << last << " are almost equal (differ by less than 100).\n";
    }
  } else {
    cout << " You entered too many numbers.\n";
  }
}

