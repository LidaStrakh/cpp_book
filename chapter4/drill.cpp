#include "std_lib_facilities.h"

int main() {
  while (true) {
    cout << "Enter '|' to exit or anything else to continue.\n";
    char x = 0;
    cin >> x;
    if (x == '|') {
      break;
    } else if (x == 0) {
      cout << "You entered nothing";
      break;
    } else {
      cout << "You entered '" << x << "'.\n"; 
    }
  }
 
 /* if (numbers.size() <= 2) {
    cout << "You have entered: ";
    for ( int х : numbers) {
      cout << х << ", " ;
    }
    cout << "\n"; 
    sort(numbers);
    cout << "The smaller value is: " << numbers[0] << "\n";
    cout << "The larger value is: " << numbers[numbers.size() - 1] << "\n";
    if (numbers[0] == (numbers[numbers.size() - 1])) {
      cout << "The numbers " << numbers[0] << " and " << numbers[numbers.size() - 1] << " are equal.\n";
    }
  } else {
    cout << " You entered too many numbers.\n";
  }
   */
}

