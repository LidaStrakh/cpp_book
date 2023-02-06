#include "std_lib_facilities.h"
#include <assert.h>

int str_to_num(string str, bool* pok) {
  if (str.empty()) {
    *pok = false;
    return 0; 
  } 
  int result = 0;
  for (int i = 0; i < str.length(); ++i) {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      result = result * 10 + (c - '0');
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
  
  string str = "";
  vector<int> numbers;
  cout << "Enter two numbers and '|' in the end: \n";
  
  while (cin >> str) {
    if (str.length() == 1 && str[0] == '|') {
      break;
    }
    int num = str_to_num(str, &ok);
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
    for ( int х : numbers) {
      cout << х << ", " ;
    }
    cout << "\n"; 
    sort(numbers);
    int first = numbers[0];
    int last = numbers[numbers.size() - 1];
    cout << "The smaller value is: " << first << "\n";
    cout << "The larger value is: " << last << "\n";
    if (first == last) {
      cout << "The numbers " << first << " and " << last << " are equal.\n";
    }
  } else {
    cout << " You entered too many numbers.\n";
  }
}

