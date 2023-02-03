#include "std_lib_facilities.h"

int str_to_num(string str, bool* pok) {
  int x = 0;
  int y = 0;
  for (int i = 0; i < str.length(); ++i) {
    char c = str[i];
    switch (c) {
      case '0': 
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        x = c - 48;
        break;
      default:
        *pok = false;
        return 0; 
    }
    y = y * 10 + x;
  }
  *pok = true;
  return y;
}

int main() {
  string str = "";
  cout << "Enter two numbers and '|' in the end: \n";
  
  while (cin >> str) {
    if (str.length() == 1 && str[0] == '|') {
      break;
    }
    bool ok = true;
    int num = str_to_num(str, &ok);
    if (ok) {
      cout << "'" << num << "' is a number.\n";    
    } else {
      cout << "'" << str << "' not a number, please enter a number.\n";
    }
  }
  /*if (numbers.size() <= 2) {
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
   */
}

