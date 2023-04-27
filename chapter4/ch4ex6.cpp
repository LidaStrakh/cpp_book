#include "std_lib_facilities.h"

int main() {
  string sp_number = "";
  int number = -1;
  vector<string> sp_value = 
    {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  cout << "Enter spelled-out value from zero to nine to convert it to a digit.\n";
  cin >> sp_number;
  
  for (int i = 0; i < sp_value.size(); ++i) {
    if (sp_number == sp_value[i]) {
      number = i;
    }
  }
  if (number == -1) {
    cout << "Data entered incorrectly.\n";
  } else {
    cout << sp_number << " is the same as " << number << ".\n";
  }

  cout << "Enter a digit from 0 to 9 to convert it to a spelled-out value.\n";
  number = -1;
  cin >> number;
  if (number < 0 || number > 9) {
    cout << "Data entered incorrectly.\n";
  } else {
    cout << number << " corresponding spelled-out value is " << sp_value[number] << "\n.";
  }
}
