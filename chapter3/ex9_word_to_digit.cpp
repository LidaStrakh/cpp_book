#include "std_lib_facilities.h"

int main() {
  string str = " ";
  int num = 10;
  cout << "Enter spelled-out number: ";
  cin >> str;

  if (str == "zero") {
    num = 0;
  } else if (str == "one") {
    num = 1;
  } else if (str == "two") {
    num = 2;
  } else if (str == "three") {
    num = 3;
  } else if (str == "four") {
    num = 4;
  } 
  if (num != 10) {
    cout << num << "\n";
  } else { 
    cout << "This is not a number I know\n";
  }
  return 0;
}
